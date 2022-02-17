#include<sstream>
#include "Controller.hpp"
#include "Tweet.hpp"
#include "Inbox.hpp"
#include "User.hpp"
#include <iostream>
#pragma once

int main() {
    Controller controle;
    User nome("nome");
    User fabin("fabin");
    
    controle.add_user(fabin);
    controle.add_user(nome);

    nome.follow(&fabin);
    controle.create_tweet(nome.get_user(),"caralheo");

    std::cout << controle;

}