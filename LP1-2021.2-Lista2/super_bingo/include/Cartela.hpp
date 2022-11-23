#ifndef Cartela_hpp
#define Cartela_hpp

#include <iostream>
#include <vector>

/**
 * Representa uma cartela do jogo Super bingo.
 */
class Cartela{
    private:
        std::vector<int> m_numeros; //<! numeros desta cartela
        std::vector<bool> m_marcas; //<! determina se um número está marcado ou não
    public:
        /**
         * Construtor padrão
         */
        Cartela();


        /**
         * Marca um número na cartela, evetivamente setando a posição do número no vetor m_marcas para true.
         * @param numero o número a ser marcado
         */
        void marcarNumero(int numero);

        /**
         * Identifica se uma cartela está completa, retornando true se todos os números estiverem marcados.
         * @return true se a cartela estiver completa, false caso contrário
         */
        bool estaCompleta();

        /**
         * Retorna o número de acertos nesta cartela
         * @return a quantidade de números marcados nesta cartela
         */
        int numAcertos();

        /**
         * Retorna um número aleatório entre 1 e 25 de acordo com as regras do jogo.
         * @return um número aleatório entre 1 e 25.
         */
        static int getNumeroAleatorio();

        /**
         * Inicia a seed do jogo, efetivamente um wrapper para o srand.
         * @param seed a seed desejada
         */
        static void iniciaSeed(long seed);
};
#endif