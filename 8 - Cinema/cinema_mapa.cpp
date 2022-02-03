#include <iostream>
#include <map>
#include <memory>
#include <algorithm>
#include <sstream>


class Cliente {
public:
    std::string nome;
    int fone;

    Cliente(std::string nome = "", int fone = 0) :
    nome{nome}, fone{fone}{}

    friend std::ostream& operator<<(std::ostream& os, const Cliente& c){
    os << c.nome;
    return os;
    }

    std::string get_name(){
        return this-> nome;
    }

};

class Cinema {
    std::map<int,Cliente> cadeiras;

public:
    int tamanho;
    Cinema(int tamanho): tamanho{tamanho}{
        for(int i = 0; i < tamanho;i++){
            cadeiras.insert({i,{"",NULL}});
        }
        
    }


friend std::ostream& operator<<(std::ostream& os, const Cinema& c){
    for(auto cadeira: c.cadeiras){
        if(cadeira.second.fone == NULL){
            std::cout << "_ ";
        }else{
            std::cout << cadeira.second << " ";

        }
    }
    std::cout << "\n";
    return os;
    }

    int procurar_pessoa(std::string id) {
        for (int i = 0; i < cadeiras.size(); i++){
            if(cadeiras[i].nome == id)
                return i;
        }
        return -1;
    }


    void comprar_ingresso (Cliente cliente, int lugar){
        auto it = cadeiras.find(lugar);
        if (lugar > tamanho || lugar < 0){
            std::cout << "Lugar Inexistente\n";
            return;
        }
        if(procurar_pessoa(cliente.nome) != -1){
            std::cout << "Pessoa ja esta no cinema\n";
        }
        if(it == cadeiras.end() || cadeiras[lugar].fone != NULL){
            std::cout << "Lugar ocupado.\n";
        }else{
            cadeiras[lugar] = cliente;
        }
    }

    std::map<int,Cliente> cancelar_ingresso (std::string pessoa){
        int procura = procurar_pessoa(pessoa);
        if(procura == -1){
            std::cout << "Pessoa nao encontrada"<< "\n";
        }else{
            cadeiras[procura] = {"",NULL};
            return cadeiras;

        }
    }

    
};

int main(){
    Cinema c(0);
    while(true){
        std::string line{},cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << "\n";

        if (cmd == "end"){
            break;
        }
        else if (cmd == "show"){
            std::cout << c << "\n";
        }
        else if (cmd == "init"){
            int qtd{};
            ss >> qtd;
            c = Cinema(qtd);
        }
        else if (cmd == "add"){
            std::string nome {};
            int idade {}, indice {};
            ss >> nome >> idade >> indice;
            Cliente novo(nome,idade);
            c.comprar_ingresso(novo,indice);
        }
        else if (cmd == "remove"){
            std::string nome{};
            ss >> nome;
            c.cancelar_ingresso(nome);
        }
        else {
            std::cout << "Comando Invalido" << "\n";
        }
    }
}