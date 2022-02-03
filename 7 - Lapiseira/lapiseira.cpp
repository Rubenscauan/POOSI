#include <iostream>
#include <algorithm>

struct Grafite {
    float calibre;
    std::string dureza;
    int tamanho;

    Grafite(float calibre = 0, std::string dureza = "", int tamanho = 0) :   
        calibre{calibre}, dureza{dureza}, tamanho{tamanho} {
        }
friend std::ostream& operator<<(std::ostream& os, const Grafite& grafite){
    os << "Calibre: " << grafite.calibre << " mm\n";
    os << "Dureza: " << grafite.dureza << "\n";
    os << "Tamanho: " << grafite.tamanho << " mm\n";
    return os;
}
    
};

struct Lapiseira {
    float calibre;
    Grafite* grafite;
    bool tem_grafite;

    Lapiseira(float calibre = 0.0, Grafite* grafite = nullptr) :
        calibre{calibre}, grafite{grafite}, tem_grafite{true} {
        }

    friend std::ostream& operator<<(std::ostream& os, const Lapiseira& lapiseira){
        os << lapiseira.calibre << "\n";
        os << lapiseira.grafite->dureza << "\n";
        os << lapiseira.tem_grafite << "\n";
        return os;
    }
    bool inserir_grafite (Grafite* grafite) {
        if(this->grafite != nullptr) {
            std::cout << "Já tem grafite.\n";
            return false;
        }
        if (grafite->calibre != this -> calibre) {
            std::cout << "Grafite não cabe.\n";
            return false;
        }
        this->grafite = grafite;
        return true;
    }

    Grafite* remover_grafite (){
        if(this -> grafite == nullptr) {
            std::cout << "Não tem grafite. \n";
            return nullptr;
        }
        return std::exchange(this->grafite,nullptr);
    }
};

int main () {
     Grafite a {12,"hb",32};
     std::cout << a;
     Lapiseira bic {};
     std::cout << bic;

}