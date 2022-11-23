#ifndef Rua_hpp
#define Rua_hpp

#include <iostream>
#include <vector>
#include "Casa.hpp"

/** 
 * Esta classe representa uma rua, com dois lados A e B.
 * A rua contém dois parâmetros e dois conjuntos representando as casas da rua. As casas do lado A
 * tem números pares enquanto as casas do lado B tem números ímpares. Os números são gerados pela própria
 * classe Rua a medida que novas casas são adicionadas.
 */
class Rua{

    private:
        std::string m_nome; //<! uma string com o nome da rua
        std::string m_CEP; //<! uma string no formato XX-XXX-XXX
        std::vector<Casa> m_A, m_B; //<! containers contendo um conjunto de casas em cada lado da Rua

    public:
        /**
         * Construtor com o nome e cep da rua
         * @param nome o nome da rua
         * @param cep o cep atribuido à rua
         **/
        Rua(std::string nome, std::string cep);

        /**
         * Adiciona uma casa no vetor de casas do lado "A" ou lado "B", da rua dependendo do valor de l. 
         * O número da casa deve ser modificado conforme sua posição no vetor A ou B, casas do lado A só tem numeros pares, 
         * começando em 0, as do lado B, começando em 1 números ímpares. Se o valor de l não for "A" ou "B" este comando não tem efeito.
         * @param c uma referencia para a casa a ser adicionada, veja que o número da casa será modificado.
         * @param l o lado da rua em que a casa deve ser adicionada, pode ser "A" ou "B".
         **/
        void adiciona_casa(Casa &c, std::string l);

        /**
         * Retorna um par contendo os visinhos de uma casa da rua. 
         * Uma casa é considerada vizinha se ela vem logo após ou é anterior à casa c no vetor em que c está adicionada. 
         * Se a casa em questão não tiver anterior ou posterior, a casa correspondente no par retornado tem número igual a -1.
         * @param c a casa que este método deve usar para procurar os vizinhos
         * @return um par contendo os vizinhos da casa fornecida, se houverem.
         **/
        std::pair<Casa, Casa> vizinhos(Casa c);
        
        /**
         * Retorna um par contendo as casas que são vizinhas à pessoa com o nome fornecido.
         * Uma casa é considerada vizinha se ela vem logo após ou é anterior à casa c no vetor em que c está adicionada. 
         * Se a casa em questão não tiver anterior ou posterior, a casa correspondente no par retornado tem número igual a -1.
         * @param nome o nome da pessoa cuja qual se deseja encontrar os vizinhos
         * @return um par contendo os vizinhos da casa fornecida, se houverem.
         **/
        std::pair<Casa, Casa> vizinhos(std::string nome);

        /**
         * Retorna um vetor com todas as casas cujo dono tem o nome passado.
         * @param nome o nome do dono cujo qual se deseja a casa
         * @return um vetor contendo todas as casas da rua cujo dono tem o nome passado
         **/
        std::vector<Casa> casa(std::string nome);

        /**
         * Retorna o endereço da casa de uma pessoa com _nome_ passado. 
         * O endereço é formatado segundo o formato: Rua <nome>, No. <numero_casa>, Cep: <CEP>. Esta função retorna uma string
         * vazia se o nome procurado não pertencer a nenhuma casa da rua.
         * @param nome o nome de algum dono de alguma casa da rua
         * @return o endereço no formato: Rua <nome>, No. <numero_casa>, Cep: <CEP>
         **/
        std::string endereco(std::string nome);

        /**
         * Retorna todas as casas do lado A da rua.
         * @return um vetor contendo todas as casas do lado A da rua
         **/
        std::vector<Casa> getA();

        /**
         * Retorna todas as casas do lado B da rua.
         * @return um vetor contendo todas as casas do lado B da rua
         **/
        std::vector<Casa> getB();
};
#endif //Rua_hpp