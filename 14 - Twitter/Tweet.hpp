#pragma once

#include <sstream>
#include <iostream>
#include <set>

class Tweet{
    int id;
    std::string username;
    std::string msg;
    std::set <std::string> likes;
    Tweet *rt{nullptr};
    bool deleted;

public:

    Tweet(int id, std::string username, std::string msg):
    id{id},username{username},msg{msg}{}

    int get_id(){return id;}
    std::string get_user(){return username;}
    std::string get_msg(){return msg;}

    void like(std::string username){
        this->likes.insert(username);
    }
    
    std::set<std::string> get_likes(){return likes;}

    void set_rt (Tweet *rt) {this->rt = rt;}

    void set_deleted() {
        this->deleted = true;
        this->msg = "Tweet Deletado";
        this->username.clear();
        this->likes.clear();
    }

    bool is_deleted() {return this->deleted;}

    friend std::ostream& operator<<(std::ostream& os, Tweet& t) {
        os << t.msg << "[";
        for(auto a : t.likes){
            os << &a;
        }
        os << "]";
        return os;
    }


};