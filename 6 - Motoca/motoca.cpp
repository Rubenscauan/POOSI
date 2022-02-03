#include <iostream>

struct Pessoa {
    int idade;
    std::string nome;

public:

    Pessoa(std::string nome = "", int idade = 0) : 
    idade{idade},nome{nome}{}

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa){
    os << pessoa.nome << ": " << pessoa.idade << " Anos\n";
    return os;
    }

};

class Moto {
    Pessoa* pessoa;
    int potencia;
    int tempo;

public:
    
    Moto(Pessoa* pessoa = nullptr, int potencia = 1, int tempo = 0) :
    pessoa{pessoa}, potencia{potencia}, tempo{tempo}{}

    friend std::ostream& operator<<(std::ostream& os, const Moto& moto){
    os << "Pessoa = " << *moto.pessoa;
    os << "Potencia = " << moto.potencia << "\n"; 
    os << "Tempo = " << moto.tempo << "\n";
    return os;
    }

    void descer_da_moto(){
        if (pessoa == nullptr){
            std::cout << "Moto ja esta vazia.\n";
        }
        else {
            this->pessoa = nullptr;
            std::cout << "Moto vazia.\n";
        }
    }

    void subir_na_moto(Pessoa* p){
        this->pessoa = p;
    }

    void comprar_tempo (int compra){
        this->tempo = compra + tempo;
        std::cout << "Comprou " << compra << " Minutos.\n";
    }

    void dirigir(int total){
        if (pessoa != nullptr && pessoa->idade <= 10 && tempo >= total){
            std::cout << "Andando por " << total << "minutos\n";
            this -> tempo -= total;
        }
        if (pessoa == nullptr){
            std::cout << "Moto sem ninguem.\n";
        }
        if(pessoa->idade > 10 ){
            std::cout << "Crianca Maior que 10 anos.\n";
        }
        if (tempo < total){
            std::cout << "So foi possivel andar " << tempo << " minutos\n";
            this -> tempo -= total;
        }
    }

    void buzinar (){
        std::cout << "P";
        for(int i = 0; i <= potencia; i++){
            std::cout << "e";
        }
        std::cout << "m\n";
    }


    friend class Pessoa;

};

int main() {
    
    Pessoa carlos{"Carlos", 6};
    std::cout << carlos;

    Moto CB {&carlos, 2, 3};
    std::cout << CB; 

    Pessoa amada{"Amada", 7};

    CB.descer_da_moto();
    CB.subir_na_moto(&amada);
    std::cout << CB;
    CB.dirigir(5);
    CB.buzinar();

    Moto Titan{&carlos,100000, 0};
    Titan.buzinar();
    
    

}