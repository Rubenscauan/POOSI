#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <ostream>

bool existe (std::vector<int> vetor, int procurado){
    for (int i = 0; i < vetor.size(); i++){
        if (vetor[i] == procurado)
            return true;
    }
    return false;
}

void imprimir (std::vector<int> vetor) {
    std::cout << "[ ";
    for (int i = 0; i < vetor.size(); i++){
        if (i == vetor.size() - 1){
            std::cout << vetor[i] << "]" << "\n";
            break;
        }std::cout << vetor[i] << " ";
    }
}

std::vector<int> sozinhos (std::vector<int>& vetor){
    std::vector<int> sozinhos {};
    for (int i = 0; i < vetor.size(); i++) {
        if (!existe(sozinhos,vetor[i]))
            vetor.push_back(vetor[i]);
        }
    return sozinhos;
}


int main () {

    std::vector<int> vetor {1, 3, 4, 2, 4, -1, 3};
    std::cout << sozinhos(vetor);

    return 0;
}