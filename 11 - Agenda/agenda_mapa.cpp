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

    contato(std::string nome,std::vector<telefone> fone = {}) : nome{nome}{
        this->fone = fone;
    }

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

class agenda {
    std::string nome;
    std::map<std::string,contato> contatos;

public:
    agenda(){}

    void add_contato(std::string nome,std::vector<telefone> fone){
        auto it = contatos.find(nome);
        if(it == contatos.end()){
            contatos.insert({nome,contato(nome,fone)});
        }else{
            auto& contato = it->second;
            for(auto& fones: fone)
                contato.add_fone(fones);
        }
    }


    friend std::ostream& operator<<(std::ostream& os, agenda& a){
        for(auto tel: a.contatos){
            os << tel.second;
        }
        std::cout << "\n";
        return os;
    }
    

    void rm_contact(std::string nome){ 
        contatos.erase(nome);
    }

    std::vector<contato> search(std::string procurada){
        std::vector<contato> aux;
        for(auto& contato : contatos){
            if(contato.second.get_name().find(procurada) != std::string::npos){
                std::cout << contato.second << "\n";
                aux.push_back(contato.second);
            }
            return aux;
        }
    }
    
};

int main(){
    agenda agenda;
}