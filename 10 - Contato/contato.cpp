#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

    bool vem_primeiro(std::string a, std::string b){
        return a < b;
    }

class telefone {
    std::string chip;
    std::string numero;

public:

    telefone(std::string chip = "", std::string numero = "") :
    chip{chip}, numero{numero}{}

    friend std::ostream& operator<<(std::ostream& os, const telefone& t){
    os << t.chip << ": " << t.numero;
    return os;
    }

    bool is_valid(){
        int valor;
        int contador = 0;
        for(int i = 0;i < numero.size();i++){
            valor = numero[i];
            if(valor >= 48 && valor <= 57 || valor == 40 || valor == 41 || valor == 32){
                contador++;
            }   
        }
        if(contador == numero.size()){
            return true;
        }else{
            return false;
        }
    }

    std::string get_chip(){
        return chip;
    }
    
    std::string get_numero(){
        return numero;
    }

    void set_number(std::string novo){
        this->numero = novo;
    }

    void set_chip(std::string novo){
        this->chip = novo;
    }

};

class contato {
    std::string nome;
    std::vector <telefone> fone;

public: 

    contato(std::string nome = "") :
    nome{nome}{}

    friend std::ostream& operator<<(std::ostream& os, const contato& t){
    os << t.nome << " -> ";
    int i = 0;
    for(auto tel: t.fone){
        os << "[ ";
        os << i++ << " : " << tel;
        os << " ]";
    }
    std::cout << "\n";
    return os;
    }


    void add_fone (telefone t){
        if(t.is_valid() == true){
            fone.push_back(t);
            std::cout << "Numero Adicionado\n";
        }
        else{
            std::cout << "Numero invalido\n";
        }
    }

    void remove_fone(int indice){
        if(indice < 0 || indice > fone.size()){
            std::cout << "Indice invalido\n";
        }
        else{
        auto tamanho = fone.size();
        auto aux = fone[indice];
        fone[indice] = fone[tamanho - 1];
        fone[tamanho - 1] = aux;
        std::cout << fone[tamanho - 1].get_chip() << " Removido \n";
        fone.pop_back();
        }
    }

    std::string get_name(){
        return nome;
    }


};

int main(){
    contato c("Sem Nome");
    while(true){
        std::string line{}, cmd{};
        std::getline(std::cin,line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << "\n";
        if(cmd == "end"){
            break;
        }
        else if(cmd == "init"){
            std::string nome{};
            ss >> nome;
            c = contato(nome);
        }
        else if(cmd == "show"){
            std::cout << c;
        }
        else if(cmd == "add"){
            std::string chip{}, numero{};
            ss >> chip >> numero;
            telefone novo(chip,numero);
            c.add_fone(novo);
        }else if(cmd == "remove"){
            int indice{};
            ss >> indice;
            c.remove_fone(indice);
        }else{
            std::cout << "Comando invalido \n";
        }
    }
}