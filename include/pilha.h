/**
*@file	pilha.h
*@brief	Cabecalho da classe Pilha
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 09/05/2017
*@date  09/05/2017
*/

#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

namespace edb1 {

/**
    * @class   pilha pilha.h
    * @brief   Classe que representa uma pilha
    * @details Os atributos da pilha são: tamanhomax, tamanho e pilha
	*/ 
    class Pilha {
        private:
        int tamanhomax; /**< Tamanho maximo da pilha */
        int tamanho; /**< Tamanho */
        char *pilha; /**< elementos */
        
        public:
        Pilha(int tamanho); /**< Construtor padrao */
        int push(char el); /**< Insere no topo */
        char pop(); /**< Remove do topo */
    };

    /**
    *@details   É alocado um espaço de memoria necessario tamanho maximo
    *			recebe esse tamanho e o tamanho inicializa com 0
    *@param     n tamanho
    */
    Pilha::Pilha(int n){
        pilha = new char[n];
        tamanhomax = n;
        tamanho = 0;
    }

    /**
    *@details   O topo da lista recebe um elemento
    *@param     el elemento
    *@return    tamanho atual
    */
    int Pilha::push(char el){
        if(tamanho == tamanhomax){
            return tamanho;
        }
        pilha[tamanho] = el;
        return tamanho++;
    }

    /**
    *@details   O elemento do topo é removido da pilha
    *@return    ultimo elemento
    */
    char Pilha::pop(){
        if(tamanho == 0){
            return tamanho;
        }
        return pilha[--tamanho];
    }
}

#endif