#include <iostream>
#include <vector>
#include <cstdio>
#include "testador.hpp"

//busca

bool existe(std::vector<int> vet, int value) {
    for (int i = 0; i < sizeof(vet); i++)
        if (vet[i] == value)
            return true;
    return false;
}

int contar_valor(std::vector<int> vet, int valor) {
    int contador = 0;
    for (int i = 0; i < sizeof(vet); i++)
        if (vet[i] == valor)
            contador++;
    return contador;
}

int procurar_valor (std::vector<int> vet, int valor) {
    int indice = -1;
    for (int i = 0; i < sizeof(vet); i++)
        if (vet[i] == valor)
            return i;
    return indice;
}

int procurar_valor_apartir (std::vector<int> vetor, int valor, int inicio) {
    for (int inicio; inicio < sizeof(vetor); inicio++)
        if (vetor[inicio] == valor)
            return inicio;
    return -1;
}

//melhor caso

int menor_valor (std::vector<int> vetor) {
    int menor = vetor[0];
    for (int i = 0; i < vetor.size(); i++) 
        if (vetor[i] < vetor[0])
            menor = vetor[i];
    return menor;
}

int indice_menor_valor (std::vector<int> vetor) {
    int menor = vetor[0];
    int posicao = 0;
    for (int i = 0; i < vetor.size(); i++){ 
        if (vetor[i] < menor){
            menor = vetor[i];
            posicao = i;
        }
    } return posicao;
}

int pos_menor_valor (std::vector<int> vetor, int inicio) {
    int menor = vetor[inicio];
    int posicao = inicio;
    for (inicio; inicio < vetor.size(); inicio++) {
        if(vetor[inicio] < menor){
            menor = vetor[inicio];
            posicao = inicio;
        }
    } return posicao;
}

int homem_menos_estressado (std::vector<int> vetor) {
    int posicao = -1;
    int menor = 100;
    for (int i = 0; i < vetor.size(); i++){
        if (vetor[i] > 0 && vetor[i] < menor) {
            menor = vetor[i];
            posicao = i;
        }
    } return posicao;
}

// contagem:

float media_estresse (std::vector<int> vetor) {
    float media = 0;
    for (int i = 0; i < vetor.size(); i++)
        media += abs(vetor[i]);
    return media / vetor.size();
}

std::string mais_homens_ou_mulheres(std::vector<int> vetor) {
    int mulheres = 0;
    int homens = 0;
    for (int i = 0; i < vetor.size(); i++) {
        if (vetor[i] < 0)
            mulheres++;
        else
            homens++;

    }if (homens == mulheres)
        return "empate";
    if (homens > mulheres)
        return "homens";
    return "mulheres";
}

std::string metade_mais_estressado (std::vector<int> vetor) {
    int primeira = 0;
    int segunda = 0;
    for (int i = 0; i < vetor.size() / 2; i++)
        primeira += abs(vetor[i]);

    int inicio = vetor.size() / 2;
    if (inicio % 2 == 1) 
        inicio++;
    for (int i = inicio; i < vetor.size(); i++)
        segunda += abs(vetor[i]);

    if (primeira == segunda)
        return "empate";
    if (primeira > segunda)
        return "primeira";
    return "segunda";
}

std::string mais_estressado (std::vector<int> vetor) {
    int homens = 0;
    int mulheres = 0;
    for (int i = 0; i < vetor.size(); i++) {
        if (vetor[i] < 0)
            mulheres += abs(vetor[i]);
        else
            homens += (vetor[i]);
    }
    if (homens == mulheres)
        return "empate";
    if (homens > mulheres)
        return "homens";
    return "mulheres";
}


int main() 
{
    //using namespace std; pode substituir o std no inicio dos codigos
    std::vector<int> vet { 30, 10, 20};
    std::cout << vet << "\n";


    
    
}