/**
*@file	lista.h
*@brief	Cabecalho da classe Lista
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 10/05/2017
*@date  13/05/2017
*/

#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using std::cout;
using std::endl;


namespace edb1 {
/**
    * @class   Node lista.h
    * @brief   Classe que representa um no
    * @details Os atributos de um no são: ant, dado e prox 
	*/ 
    template <typename T>
    class Node {
        public:    
            Node<T>* ant; /**< ponteiro para o elemento anterior */
            T dado; /**< Dado do no */
            Node<T>* prox; /**< ponteiro para o proximo elemento */

            Node<T>(){ /**< Construtor padrao */
                ant = prox = NULL;
            }
            Node<T>(const T& el, Node<T> *p = NULL, Node<T> *a = NULL) { /**< Construtor parametrizado */
            dado = el; prox = p; ant = a;
            }
    };

/**
    * @class   Lista lista.h
    * @brief   Classe que representa uma Lista duplamente encadeada
    * @details Os atributos de uma Lista são: cabeca e cauda
	*/ 
    template <typename T>
    class Lista {
        private:
            Node<T> *cabeca; /**< cabeca */
            Node<T> *cauda; /**< cauda */
        public:
            Lista() { /**< Construtor padrao */
                cabeca = NULL;
                cauda = NULL;
            }
            ~Lista() { /**< Destrutor */
                if(cabeca){
                    cauda = NULL;
                    Node<T> *tmp = cabeca;
                    while(tmp){
                        cauda = tmp;
                        tmp = tmp->prox;
                    }
                    
                    while(cauda != cabeca){
                        tmp = cabeca;
                        while(tmp->prox){
                            cauda = tmp;
                            tmp = tmp->prox;
                        }
                        delete tmp;
                        cauda->prox = NULL;
                    }
                    tmp = cabeca;
                    delete tmp;
                }
            }
            void Inserir(T el); /**< Insere um elemento na ordem */
            void Remover(T el); /**< Remove um elemento */
            void Print(); /**< Imprime a lista */

    };

    /**
    * @details Imprime os elementos da lista
    */
    template<typename T>
    void Lista<T>::Print(){
        Node<T> *itd = cabeca;
        while(itd){
            cout << itd->dado << endl;
            itd = itd->prox;
        }
    }

    /**
    * @details Insere um elemento na lista de forma ordenada
    */
    template<typename T>
    void Lista<T>::Inserir(T el){
        if(!cabeca || el < cabeca->dado){
            
            Node<T>* tmp = new Node<T>();
            tmp->dado = el;
            tmp->prox = cabeca;
            cabeca = tmp;
        }
        else{
            Node<T> *itd = cabeca;
            Node<T>* tmp = new Node<T>();
            tmp->dado = el;

            while(itd && itd->dado < el && itd->prox){
                itd = itd->prox;
            }
            if(el < itd->dado){
                tmp->prox = itd;
                tmp->ant = itd->ant;
                itd->ant->prox = tmp;   
            }
            else{
                tmp->prox = itd->prox;
                itd->prox = tmp;
                tmp->ant = itd;
            }
        }
    }

    /**
    * @details Remove um elemento da lista
    */
    template<typename T>
    void Lista<T>::Remover(T el){
        
        Node<T> *itd = cabeca;
        Node<T> *tmp = NULL;
        
        while(itd && itd->dado != el){
            tmp = itd;
            itd = itd->prox;
        }
        
        if(itd && itd->dado == el){
            if(itd->prox){
                if(tmp){
                    tmp->prox = itd->prox;
                    itd->prox->ant = tmp;
                }
                else{
                    cabeca = itd->prox;
                    itd->prox->ant = NULL;
                }
            }
            else{
                if(tmp){
                    tmp->prox = NULL;
                }
                else{
                    cabeca = NULL;
                }
            }
            
            tmp = itd;
            delete tmp;
        }
        else{
            cout << "Elemento para ser removido não encontrado" << endl;
        }
    }
}



#endif