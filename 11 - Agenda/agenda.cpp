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
    std::vector<contato> contatos;

public:
    agenda(std::string nome = ""):nome{nome}{}

    std::vector<contato> get_contacts(){
        return this->contatos;
    }
    void organizar(){
        for(int i = 0; i < contatos.size(); i++){
            for(int j = 0; j < contatos.size();j++){
                if(contatos[i].get_name() < contatos[j].get_name()){
                    auto aux{contatos[j]};
                    contatos[j] = contatos[i];
                    contatos[i] = aux;
                }
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& os, agenda& a){
        a.organizar();
        int i = 0;
        for(auto tel: a.contatos){
            os << tel;
        }
        std::cout << "\n";
        return os;
    }


    int find_contact(std::string nome){
        for(int i = 0; i < contatos.size(); i++){
            if(contatos[i].get_name() == nome){
                std::cout << contatos[i];
                return i;
            }
        }
        std::cout << "Contato nao encontrado\n";
        return -1;
    }
    
    

    void add_contato(contato c){
        contatos.push_back(c);
        
    }

    void rm_contact(std::string nome){ 
        int tamanho = contatos.size();
        for(int i = 0; i < contatos.size();i++){
            if(contatos[i].get_name() == nome){
                auto aux = contatos[i];
                contatos[i] = contatos[tamanho - 1];
                contatos[tamanho - 1] = aux;
                contatos.pop_back();
                std::cout << nome << " Removido \n";
                return;
            } 
        }
        std::cout << "Contato nao encontrado\n";
    }

    std::vector<contato> search(std::string procurada){
        std::vector<contato> novo;
        int aux;
        for(int i = 0; i < contatos.size();i++){
            aux = contatos[i].get_name().find(procurada);
            if(aux == 0){
                novo.push_back(contatos[i]);
                std::cout << contatos[i];
            }
        }
        return novo;
    }
    
};

int main(){
    agenda a("");
    contato c{"claro",{{"vivo","1231"},{"claro","88"}}};
    std::cout << c;
    
    a.add_contato(c);

}