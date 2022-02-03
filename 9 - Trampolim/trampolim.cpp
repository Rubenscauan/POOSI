#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>

class kid {
    std::string nome;
    int idade;

public:
    kid(std::string nome = "",int idade = 0) : 
    nome{nome}, idade{idade}{}

    friend std::ostream& operator<<(std::ostream& os, const kid& k){
    os << k.nome;
    return os;
    }

    std::string show_name(){
        return nome;
    }

    int show_idade(){
        return idade;
    }

    void setidade(int novo){
        idade = novo;
    }

    void setname(std::string novo){
        nome = novo;
    }

};

class trampolim {
    std::list <std::shared_ptr<kid>> pulando;
    std::list <std::shared_ptr<kid>> esperando;

public:

    trampolim(int tamanho){
    }

    trampolim(std::list <std::shared_ptr<kid>> pulando,std::list <std::shared_ptr<kid>> esperando) :
    pulando{pulando}, esperando{esperando}{}


    friend std::ostream& operator<<(std::ostream& os, const trampolim& t){
        std::cout << "PULANDO \n";
        for(auto vaga: t.pulando){
                os << *vaga << " ";
        }
        std::cout << "\n";

        std::cout << "Esperando: \n";
        for(auto vaga: t.esperando){
                os << *vaga << " ";
        }
        std::cout << "\n";
        return os;
    }

    void chegar(std::shared_ptr<kid> kid){
        std::cout << *kid << " entrou na fila.\n";
        esperando.push_back(kid);
    }

    void remover_trampolim(){
        if(pulando.front() == NULL){
            std::cout << "Trampolim vazio \n";
            return;
        }
        pulando.pop_front();
    }


    void entrar_trampolim(){
        if(esperando.front() == NULL){
            std::cout << "Ninguem na fila\n";
        }
        if(pulando.size() == 3){
            std::cout << "Trampolim lotado\n";
            return;
        }
        else{   
            pulando.push_back(esperando.front());
            esperando.pop_front();
            return;
        }
    }
};

int main () {
    kid carlos{"carlos", 4};
    kid ana{"ana"};
    kid abel{"abel"};

    trampolim trampolim(3);
    trampolim.chegar(std::make_shared<kid>(carlos));
    trampolim.chegar(std::make_shared<kid>(ana));

    trampolim.entrar_trampolim();
    trampolim.entrar_trampolim();
    std::cout << trampolim;


}