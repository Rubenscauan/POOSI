#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "testador.hpp"

//fillter

std::vector<int> clone (const std::vector<int>& vetor) {
    std::vector<int> clone {};
    for (int i = 0; i < vetor.size(); i++)
        clone.push_back(vetor[i] + 1);
    return vetor;    
}

std::vector<int> pegar_homens (const std::vector<int>& vetor) {
    std::vector<int> homens {};
    for (int i = 0; i < vetor.size(); i++)
        if (vetor[i] > 0)  
            homens.push_back(vetor[i]);
    return homens;
}

std::vector<int> pegar_calmos (const std::vector<int>& vetor) {
    std::vector<int> calmos {};
    for (int i = 0; i < vetor.size(); i++)
        if (abs(vetor[i]) < 10 )
            calmos.push_back(vetor[i]);
    return calmos;
}

std::vector<int> pegar_mulheres_calmas (const std::vector<int>& vetor) {
    std::vector<int> calmas {};
    for (int i = 0; i < vetor.size(); i++)
        if(vetor[i] < 0 && abs(vetor[i]) < 10)
            calmas.push_back(vetor[i]);
    return calmas; 
}

//acesso

std::vector<int> inverter_com_copia (const std::vector<int>& vetor) {
    std::vector<int> invertido {};
    for (int i = vetor.size() - 1; i >= 0; i--) 
        invertido.push_back(vetor[i]);
    return invertido;
}

void inverter_sem_copia (std::vector<int>& vetor) {
    std::reverse(vetor.begin(), vetor.end());
    std::cout << vetor << "\n";
}

int sortear(std::vector<int> vetor) {
    unsigned seed = time(0);
    srand(seed);
    return vetor[rand() % vetor.size()];
}

void embaralhar (std::vector<int>& vetor) {
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < vetor.size(); i++)
	{
		int numero = rand() % vetor.size();

		int substituto = vetor[i];
		vetor[i] = vetor[numero];
		vetor[numero] = substituto;
	}
}

void ordenar(std::vector<int>& vetor) {
    for (int i = 0; i < vetor.size(); i++) {
        int indice_menor = i;
        for (int j = i + 1; j < vetor.size(); ++j) {
            if (vetor[j] < vetor[indice_menor]) {
                indice_menor = j;
            }
        }
        int auxiliar = vetor[i];
        vetor[i] = vetor[indice_menor];
        vetor[indice_menor] = auxiliar;
    }
}

// conjuntos

void imprimir (std::vector<int> vetor) {
    std::cout << "[ ";
    for (int i = 0; i < vetor.size(); i++){
        if (i == vetor.size() - 1){
            std::cout << vetor[i] << "]" << "\n";
            break;
        }std::cout << vetor[i] << " ";
    }
}

bool existe(std::vector<int> vet, int value) {
    for (int i = 0; i < sizeof(vet); i++)
        if (vet[i] == value)
            return true;
    return false;
}

std::vector<int> exclusivos(const std::vector<int>& vetor) {
    std::vector<int> unicos {};
    for (int i = 0; i < vetor.size(); i++) {
        if(!existe(unicos, i)) {
            unicos.push_back(i);
        }
    }
    return unicos;
}





int main () 
{   
    std::vector<int> vetor { 3, 23, -30, -4, -5 };
    std::vector<int> vetor2 {3, 3, 4, 4, 2, -2, 2, 4 , 1};
    imprimir(exclusivos(vetor2));
}