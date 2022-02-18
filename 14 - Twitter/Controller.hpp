#pragma once

#include <iostream>
#include "User.hpp"

class Controller {
private:
    std::map<std::string, User*> users;
    std::map<int, Tweet*> tweets;
    int nextTwId;

public:
    Controller() : users{}, tweets{}, nextTwId{0} {}

    ~Controller() {
        for (auto i : tweets) {
            delete i.second;
        }
        for (auto j : users) {
            delete j.second;
        }
    }

    void add_user(User user) {
        auto aux = users.find(user.get_user());
        if (aux == users.end()) {
            users.insert(std::make_pair(user.get_user(), &user));
            std::cout << user.get_user() << " foi adicionado" << std::endl;
            return;
        }
        std::cout << user.get_user() << " ja esta adicionado" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, Controller& c) {
        os << "Users [" << c.users.size() << "]\n";
        for (auto a : c.users) {
            os << *a.second;
        }
        os << "\nTweets [" << c.tweets.size() << "]\n";
        for(auto b: c.tweets){
            os << *b.second << " Tweet from " << b.second->get_user() << "\n";
        }
        return os;
    }

    Tweet* create_tweet(std::string sender, std::string msg) {
        Tweet *tweet = new Tweet(this->nextTwId, sender, msg);
        this->tweets.insert({this->nextTwId, tweet});
        this->nextTwId++;
        return tweet;
    }

    User* get_user(std::string &username) {
        if (this->users.find(username)->first == username) {
           return this->users.find(username)->second;
        } 
        std::cout << ("Usuario nao encontrado");
    }


    void twittar(std::string username, std::string msg){
        if (this->users.find(username)->first == username) {
            this->get_user(username)->sendTweet(this->create_tweet(username, msg));
            return;
        }
    }
    void send_rt(std::string &username, int twID, std::string &msg) {
        Tweet *rt = this->create_tweet(username, msg);
        try {
            User *user = this->get_user(username);
            Tweet *tweet = this->tweets.find(twID)->second;
            tweet->set_rt(rt);
            user->sendTweet(rt);
        } catch (std::string &error) {
            if (error == "User not found") {
                std::cout << error;
            } else if (error == "Tweet not found") {
                std::cout << error;
            }
        }
    }

    void rm_user(std::string &username) {
        try {
            User *user(this->get_user(username));
            user->unfollowAll();
            for (auto i : user->get_inbox()->get_MyTweets()) {
                i->set_deleted();
            }
            this->users.erase(username);
            std::cout << username << " foi deletado";
        } catch (std::string &error) {
            std::cout << error;
        }
    }
}; 