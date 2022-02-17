#pragma once

#include "Tweet.hpp"
#include <map>
#include <list>

class Inbox {
private:
    std::map<int, Tweet*> timeline;
    std::map<int, Tweet*> myTweets;

public:

    Inbox(){}

    void store_in_timeline(Tweet *tweet) {
        if (this->timeline.find(tweet->get_id())->second == tweet) {
            throw std::string("Esse tweet ja foi armazenado");
        }
        this->timeline.insert({tweet->get_id(), tweet});
    }

    std::list<Tweet*> get_timeline() {
        std::list<Tweet*> timelineList {};
        for (auto i : this->timeline) {
            timelineList.push_back(i.second);
        }
        return timelineList;
    }

    Tweet* get_tweet(int id) {
        auto aux = this->timeline.find(id);
        if (aux == this->timeline.end()) {
            throw std::string("Tweet não encontrado");
        }
        return &(*aux->second);
    }

    void rm_msgs_from(std::string nome) {
        std::list<int> removes {};
        for (auto i : timeline) {
            if (i.second->get_user() == nome) {
                removes.push_back(i.first);
            }
        }
        for (auto j : removes) {
            this->timeline.erase(j);
        }
    }

    void store_in_mytweets(Tweet *tweet) {
        auto aux = myTweets.find(tweet->get_id());
        if (aux != myTweets.end()) {
            std::cout << "Esse tweet ja esta armazenado" << std::endl;
            return;
        }
        this->myTweets.insert({tweet->get_id(), tweet});
    }

    std::list<Tweet*> get_MyTweets() {
        std::list<Tweet*> myTweetsList {};
        for (auto i : this->myTweets) {
            myTweetsList.push_back(i.second);
        }
        return myTweetsList;
    }

    friend std::ostream& operator<<(std::ostream& os, Inbox& i){
        for (auto& i : i.timeline) {
            os << i.first << ":" << i.second->get_user() << " | " << *i.second << "\n";
        }
        return os;
    }
};