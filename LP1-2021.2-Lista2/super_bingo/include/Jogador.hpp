#ifndef Jogador_hpp
#define Jogador_hpp
#include <iostream>
#include <vector>

#include "Cartela.hpp"
class Jogador{
    private:
        std::vector<Cartela*> m_cartelas;
        std::string m_nome;

    public:
        /**
         * Construtor padrão
         */
        Jogador(std::string nome);

        /**
         * Adiciona uma cartela à lista de cartelas apostadas por este jogador
         * @param c a cartela a ser adicionada
         */
        void adicionaCartela(Cartela* c);

        /**
         * Getter do nome
         * @return o valor do atributo m_nome
         */
        std::string getNome();

        /**
         * Retorna o total de números acertados por este jogador
         * @return a quantidade de números acertados em todas as cartelas
         */
        int getTotalNumeros();

        /**
         * Retorna o total de cartelas completadas por este jogador
         * @return a quantidade de cartelas completas do jogador
         */
        int getTotalCartelas();

        /**
         * Retorna a quantidade de dinheiro, caso este jogador vença o jogo.
         * Este método usa as implementações de getTotalCartelas e getTotalNumeros.
         * @return a quantidade de dinheiro recebida de acordo com as regras do jogo.
         */
        float getDinheiroVencedor();

};
#endif //Jogador_hpp