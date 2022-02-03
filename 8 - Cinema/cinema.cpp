#include <iostream>
#include <list>
#include <vector>
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

    

};

class Cinema {
    std::vector<std::shared_ptr<Cliente>> cadeiras;

public:
    Cinema(int tamanho){
        for (int i = 0; i < tamanho; i++){
            cadeiras.push_back(nullptr);
        }
    }

    Cinema(std::vector<std::shared_ptr<Cliente>> cadeiras) : 
        cadeiras{cadeiras}{}

    int procurar_pessoa(std::string id) {
        for (int i = 0; i < cadeiras.size(); i++){
            if(cadeiras[i] != nullptr && cadeiras[i] -> nome == id)
                return i;
        }
        return -1;
    }


    void comprar_ingresso (std::shared_ptr<Cliente>&& pessoa, int lugar){
        if(lugar < 0 || lugar >= cadeiras.size()){
            std::cout << "Lugar nao existe."<< "\n";
            return;
        }
        if(cadeiras[lugar] != nullptr){
            std::cout << "Lugar ocupado" << "\n";
            return;
        }
        if(this -> procurar_pessoa(pessoa -> nome) != -1){
            std::cout << "Pessoa ja esta no cinema"<< "\n";
            return;
        }
        cadeiras[lugar] = pessoa;
    }

    std::shared_ptr<Cliente> cancelar_ingresso (std::string pessoa){
         int procura = procurar_pessoa(pessoa);
         if(procura == -1){
             std::cout << "Pessoa nao encontrada"<< "\n";
             return 0;
         }
         return std::exchange(cadeiras[procura], nullptr);
    }

friend std::ostream& operator<<(std::ostream& os, const Cinema& c){
    for(auto cadeira: c.cadeiras){
        if(cadeira == nullptr)
            os << "_ ";
        else  
            os << *cadeira << " ";
    }
    std::cout << "\n";
    return os;
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
            c.comprar_ingresso(std::make_shared<Cliente>(nome,idade),indice);
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
    

