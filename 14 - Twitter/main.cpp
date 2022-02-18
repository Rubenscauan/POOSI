#include<sstream>
#include "Controller.hpp"
#include "Tweet.hpp"
#include "Inbox.hpp"
#include "User.hpp"
#include <iostream>
#pragma once

int main(){

    Controller controle;
    while (true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << std::endl;
        std::cout << std::endl;

        if (cmd == "end") {
            break;
        } else if (cmd == "add") {
            std::string name;
            ss >> name;
            controle.add_user(name);
            std::cout << std::endl;
        } else if (cmd == "show") {
            std::cout << controle;
        } else if (cmd == "follow") {
            std::string following, follower;
            ss >> following;
            ss >> follower;
            controle.get_user(follower)->follow(controle.get_user(following));
        }else if (cmd == "twittar") {
            std::string tweet, user, aux;
            ss >> user;
            while (ss >> aux) {tweet += aux + " ";}
                controle.twittar(user, tweet);
        } else if (cmd == "timeline") {
            std::string username;
            ss >> username;
            try {
                std::cout << controle.get_user(username)->get_inbox();
            } catch (std::string &error) {
                std::cout << error << std::endl;
            }
            std::cout << std::endl;
        } else if (cmd == "like") {
            std::string username;
            int twId;
            ss >> twId;
            ss >> username;
            try {
                controle.get_user(username)->like(twId);
            } catch (std::string &error) {
                if (error == "User not found") {
                    std::cout << error << std::endl;
                } else if (error == "Tweet not found") {
                    std::cout << error << std::endl;
                }
            }
            std::cout << std::endl;
        } else if (cmd == "unfollow") {
            std::string unfollow, unfollower;
            ss >> unfollow;
            ss >> unfollower;
            try {
                controle.get_user(unfollower)->unfollow(controle.get_user(unfollow));
            } catch (std::string &error) {
                std::cout << error << std::endl;
            }
            std::cout << std::endl;
        } else if (cmd == "rm") {
            std::string username;
            ss >> username;
            controle.rm_user(username);
            std::cout << std::endl;
        } else if (cmd == "rt") {
            std::string username, msg, aux;
            int msgID;
            ss >> username;
            ss >> msgID;
            while (ss >> aux) {msg += aux + " ";}
            controle.send_rt(username, msgID, msg);
            std::cout << std::endl;
        } else {
            std::cout << "Invalid command" << std::endl;
            std::cout << std::endl;
        }
    }
}