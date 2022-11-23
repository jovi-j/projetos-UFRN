#include "Jogador.hpp"
Jogador::Jogador(std::string nome){
    m_nome = nome;
}
void Jogador::adicionaCartela(Cartela* c){
    m_cartelas.push_back(c);
}

std::string Jogador::getNome(){
    return m_nome;
}

int Jogador::getTotalCartelas(){
    //! TODO: implementar contagem de cartelas completas
    return 0;
}

int Jogador::getTotalNumeros(){
    //! TODO: implementar contagem de números marcados
    return 0;
}

float Jogador::getDinheiroVencedor(){
    return getTotalNumeros() * 5 + getTotalCartelas() * 20;
}