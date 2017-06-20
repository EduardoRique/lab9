/** 
*@file main.cpp
*@brief Arquivo fonte para execução do projeto
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 20/06/2017
*@date  20/06/2017
*/

#include <iostream>
#include <cstdlib>
#include "eduardo.h"

using namespace std;
using namespace edb1;

/**
* @brief        Função principal do programa
* @return		Retorno
*/

int main(){

    //Testa a classe lista
    cout << "Teste de lista ligada" << endl;
    Lista<int> *lista = new Lista<int>();
    lista->Inserir(10);
    lista->Print();

    //Testa a classe pilha
    cout << "Teste de pilha" << endl;
    Pilha<int> pilha(1);
    pilha.push(10);
    cout << pilha.pop() << endl;

    //Testa as buscas
    cout << "Testes de buscas" << endl;
    int V[100];
    for(int i = 0; i < 100; i++)
        V[i] = i + 1;
    cout <<  busca_seq_i(V, 0, 100, 9) << endl;
    cout <<  busca_seq_r(V, 0, 100, 87) << endl;
    cout <<  busca_bin_i(V, 0, 100, 12) << endl;
    cout <<  busca_bin_r(V, 0, 100, 65) << endl;
    cout <<  busca_ter_i(V, 0, 100, 85) << endl;
    cout <<  busca_ter_r(V, 0, 100, 10) << endl;

    return 0;
}