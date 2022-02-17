#pragma once

#include <iostream>
#include "Inbox.hpp"

class User{
private:
    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;

public:
    User(const std::string &username) : 
    username{username}, inbox{}, followers{}, following{} {}

    Inbox* get_inbox() {return &this->inbox;}
    std::string get_user(){return this->username;}

    
    void sendTweet(Tweet *tweet) {
        for (auto i : followers) {
            i.second->inbox.store_in_timeline(tweet);
        }
        this->inbox.store_in_timeline(tweet);
        this->inbox.store_in_mytweets(tweet);
        std::cout << "Tweet postado" << std::endl;    
    }

    void follow(User *other) {
        if (other->username ==  this->username) {
            throw std::string("Voce nao pode seguir a si mesmo");
            return;
        } else if (this->following.find(other->username)->first != other->username) {
            this->following.insert({other->username, other});
            other->followers.insert({this->username, this});
            std::cout << this->username << " seguiu " << other->username << std::endl;
            return;
        }
        std::cout << this->username << " ja esta seguido " << other->username << std::endl;
    }

    void unfollow(User* other) {
        if (this->following.find(other->username)->first == other->username) {
            this->following.erase(other->username);
            other->followers.erase(this->username);
            std::cout << this->username << " deixou de seguir " << other->username << std::endl;
            this->inbox.rm_msgs_from(other->get_user());
            return;
        }
        std::cout << this->username << " deixar de seguir " << other->username << std::endl;
    }

    void like(int tweetID) {
        if(tweetID < 0){
            std::runtime_error("fail: Id invalido");
            return;
        }
        this->inbox.get_tweet(tweetID)->like(this->username);
    }

    void unfollowAll() {
        std::map<std::string, User*>::iterator it = this->following.begin();
        while (it != this->following.end()) {
            this->unfollow((it++)->second);
        }
    }


    friend std::ostream& operator<<(std::ostream& os, User& u) {
        os << u.username << ":\n  followers [" << u.followers.size() << "] ";
        for (auto i : u.followers) {
            os << i.second->username;
        }
        os << "\n  following [" << u.following.size() << "] ";
        for (auto i : u.following) {
            os << i.second->username;
        }
        os << "\n";
        return os;
    }
};