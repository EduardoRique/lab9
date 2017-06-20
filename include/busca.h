/**
*@file	busca.h
*@brief	arquivo com as definicoes e implementacoes das buscas
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 20/06/2017
*@date  20/06/2017
*/

#ifndef BUSCA_H
#define BUSCA_H

namespace edb1 {
    /**
    * @details Função de busca linear iterativa
    * @param Vetor Vetor com os dados
    * @param ini Posicao mais à esquerda no vetor para a busca
    * @param fim Posicao mais à direita para busca
    * @param el Elemento a ser buscado
    */
    extern "C++" template<typename T>
    int busca_seq_i(T Vetor[], int ini, int fim, T el) {
        int i, tam = fim - ini;
        for(i = 0; i < tam; i++)
            if(Vetor[i] == el)
                return i;
        return -1;
    }

    /**
    * @details Função de busca linear recursiva
    * @param Vetor Vetor com os dados
    * @param ini Posicao mais à esquerda no vetor para a busca
    * @param fim Posicao mais à direita para busca
    * @param el Elemento a ser buscado
    */
    extern "C++" template<typename T>
    int busca_seq_r(T Vetor[], int ini, int fim, T el) {
        int n = (fim - ini);
        if(n < 0)
            return -1;
        if(Vetor[n] == el){
            return n;
        } else
            return busca_seq_r(Vetor, 0, (n - 1), el);
    }

    /**
    * @details      Função de busca binária iterativa
    * @param Vetor Vetor com os dados
    * @param ini Posicao mais à esquerda no vetor para a busca
    * @param fim Posicao mais à direita para busca
    * @param el Elemento a ser buscado
    */
    extern "C++" template<typename T>
    int busca_bin_i(T Vetor[], int ini, int fim, T el) {
        int mid;
        while(ini <= fim){
            mid = (ini + fim)/2;
            if(Vetor[mid] == el)
                return mid;
            if(Vetor[mid] < el)
                ini = mid + 1;
            else
                fim = mid - 1;
        }
        return -1;
    }

    /**
    * @details      Função de busca binária recursiva
    * @param Vetor Vetor com os dados
    * @param ini Posicao mais à esquerda no vetor para a busca
    * @param fim Posicao mais à direita para busca
    * @param el Elemento a ser buscado
    */
    extern "C++" template<typename T>
    int busca_bin_r(T Vetor[], int ini, int fim, T el) {
        int mid = (ini + fim)/2;
        if(Vetor[mid] == el)
            return mid;
        if(ini >= fim)
            return -1;
        if(Vetor[mid] < el)
            return busca_bin_r(Vetor, (mid + 1), fim, el);
        else
            return busca_bin_r(Vetor, ini, (mid - 1), el);
        return -1;
    }

    /**
    * @details Função de busca ternaria iterativa
    * @param Vetor Vetor com os dados
    * @param ini Posicao mais à esquerda no vetor para a busca
    * @param fim Posicao mais à direita para busca
    * @param el Elemento a ser buscado
    */
    extern "C++" template<typename T>
    int busca_ter_i(T Vetor[], int ini, int fim, T el) {
        int mid1, mid2;
        while(ini <= fim){

            mid1 = ((fim - ini) / 3) + ini;
            mid2 = (((fim - ini) / 3) * 2) + ini;

            if(el == Vetor[mid1])	return mid1;
                
            if(el == Vetor[mid2]) return mid2;
                
            if(el < Vetor[mid1]) fim = mid1 - 1;
                
            if(el > Vetor[mid1] && el < Vetor[mid2]){
                ini = mid1 + 1;
                fim = mid2 - 1;
            } 
            else if(el > Vetor[mid2]) ini = mid2 + 1;
        }
        return -1;
    }

    /**
    * @details      Função de busca ternaria recursiva
    * @param Vetor Vetor com os dados
    * @param ini Posicao mais à esquerda no vetor para a busca
    * @param fim Posicao mais à direita para busca
    * @param el Elemento a ser buscado
    */
    extern "C++" template<typename T>
    int busca_ter_r(T Vetor[], int ini, int fim, T el) {
        if((ini < 0) || (fim < (fim-ini)-1) || (ini > fim)) return -1;
            
        if(el == Vetor[ini]) return ini;
            
        if(el == Vetor[fim]) return fim;
            
        if(el < Vetor[ini]) return busca_ter_r(Vetor, (ini - 1), fim, el);
            
        if ((el > Vetor[ini]) && (el < Vetor[fim])) return busca_ter_r(Vetor, (ini + 1), (fim - 1), el);
            
        if(el > Vetor[fim]) return busca_ter_r(Vetor, ini, (fim + 1), el);
            
        return -1;
    }
}

#endif