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
    template<typename T>
    class Pilha {
        private:
        int tamanhomax; /**< Tamanho maximo da pilha */
        int tamanho; /**< Tamanho */
        T *pilha; /**< elementos */
        
        public:
        Pilha(int tamanho); /**< Construtor padrao */
        int push(T el); /**< Insere no topo */
        T pop(); /**< Remove do topo */
    };

    /**
    *@details   É alocado um espaço de memoria necessario tamanho maximo
    *			recebe esse tamanho e o tamanho inicializa com 0
    *@param     n tamanho
    */
    template<typename T>
    Pilha<T>::Pilha(int n){
        pilha = new T[n];
        tamanhomax = n;
        tamanho = 0;
    }

    /**
    *@details   O topo da lista recebe um elemento
    *@param     el elemento
    *@return    tamanho atual
    */
    template<typename T>
    int Pilha<T>::push(T el){
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
    template<typename T>
    T Pilha<T>::pop(){
        if(tamanho == 0){
            return tamanho;
        }
        return pilha[--tamanho];
    }
}

#endif