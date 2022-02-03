#include <iostream>

class Veiculo{
    std::string tipo;
public:
    Veiculo(std::string tipo = "Carro Popular") : 
    tipo{tipo}{}

    friend std::ostream& operator<<(std::ostream& os, const Veiculo& v){
    os << v.tipo << " \n";
    return os;
    }

    std::string get_tipo()const {return tipo;}
    void set_tipo(std::string novo) {this->tipo = novo;}

};

class Veiculo_de_Carga : public Veiculo{
    int carga_max;
    int carga_atual = 0;
public:

    Veiculo_de_Carga(std::string tipo = "Caminhao", int carga_max = 3000) :
    Veiculo{tipo},carga_max{carga_max}{}

    friend std::ostream& operator<<(std::ostream& os, const Veiculo_de_Carga& v){
    os << v.get_tipo() << " : " << v.carga_atual << " de " << v.carga_max << "KGs\n";
    return os;
    }
    
    int get_carga_max()const{return carga_max;}
    int get_carga_atual()const{return carga_atual;}
    void set_carga_max(int novo){this->carga_max = novo;}

    void abastecer_carga(int carga){
        if(carga > carga_max)
            std::cout << "Muita carga";
        else
            carga_atual += carga;
    }
    void fazer_entrega(int qtd){
        this -> carga_atual -= qtd;
    }

};

class Caminhao : public Veiculo_de_Carga{
    int qtd_rodas;

public: 
    Caminhao(int qtd_rodas = 8, int carga_max = 3000) : 
    qtd_rodas{qtd_rodas},Veiculo_de_Carga("Caminhao",carga_max){}

    friend std::ostream& operator<<(std::ostream& os, const Caminhao& c){
    os << c.get_tipo() << " de " << c.qtd_rodas << " Rodas" <<   " : " << c.get_carga_atual() << " de " << c.get_carga_max() << "KGs\n";
    return os;
    }

    int get_rodas() const{return qtd_rodas;}
    void set_rodas(int novo){this ->qtd_rodas = novo;}

    void viajar(){
        std::cout << "Caminhão Viajando\n";
    }

    void furar_pneu(){
        std::cout << "Pneu furado\n";
        qtd_rodas--;
    }
    void remendar_pneu(){
        std::cout << "Pneu remendado\n";
        qtd_rodas++;
    }
};

int main(){
    Caminhao a;
    a.abastecer_carga(2000);
    std::cout << a;

}