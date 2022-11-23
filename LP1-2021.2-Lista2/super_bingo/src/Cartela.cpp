#include "Cartela.hpp"
#include <algorithm>

using namespace std;

Cartela::Cartela(){

    while(m_numeros.size() < 10){
        int n = Cartela::getNumeroAleatorio();
        if(std::find(m_numeros.begin(), m_numeros.end(), n) == m_numeros.end()){
            m_numeros.push_back(n);
            m_marcas.push_back(false);
        }
    }
}

void Cartela::marcarNumero(int numero){
    for(unsigned i=0; i<m_numeros.size(); i++)
        if (m_numeros[i] == numero)
            m_marcas[i] = true;
}

bool Cartela::estaCompleta(){
    for(unsigned i=0; i<m_marcas.size(); i++)
        if(!m_marcas[i])
            return false;
    return true;
}

int Cartela::numAcertos(){
    int tot = 0;
    for(unsigned i=0; i<m_marcas.size(); i++)
        if(!m_marcas[i])
            tot++;
    return tot;
}

int Cartela::getNumeroAleatorio(){
    return rand() % 25 + 1;
}

void Cartela::iniciaSeed(long seed){
    srand(seed);
}