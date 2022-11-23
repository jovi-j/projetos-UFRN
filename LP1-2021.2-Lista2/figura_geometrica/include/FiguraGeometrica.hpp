#ifndef FiguraGeometrica_hpp
#define FiguraGeometrica_hpp

#include "Tipos.hpp"
#include <iostream>
#include <string>
#include <vector>
class FiguraGeometrica{
    public:
        std::string nome;
        Tipo tipo;
        std::vector<std::pair<int, int>> pontos;
    /**
     * FiguraGeometrica, contendo um nome, um tipo e um vetor de pontos.
     * @param nome, nome da figura.
     * @param tipo, tipo da figura.
     * @param pontos, vetor de pontos da figura.
    **/
    FiguraGeometrica(std::string nome, int tipo);

    /**
     * Adiciona um ponto ao vetor de pontos.
     * Para _Retangulos_, a função pode ser chamada duas vezes.
     * Para _Trianguo_, a função pode ser chamada três vezes.
     * @param p, ponto a ser adicionado.
     * @return true se o ponto foi adicionado, false caso contrário.
     **/
    bool addPoint(std::pair<int, int> p);

    /**
     * Retorna a área da figura caso hajam pontos suficientes para realizar o cálculo da área. Se não houver pontos suficientes, retorna -1.
     * @return área da figura.
     **/
    float getArea();
    
    /**
     * Retorna a figura em formato string.
     * @return os atributos da figura, em formato string "nome:tipo - {pontos}".
     **/
    std::string toString();

};

#endif //FiguraGeometrica_hpp