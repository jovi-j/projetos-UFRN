#include "Casa.hpp"

Casa::Casa(std::string dono){
	this->m_dono = dono;
}

int Casa::getNumero(){
	return this->m_numero;
}

void Casa::setNumero(int n){
	this->m_numero = n;
}

std::string Casa::getDono(){
	return this->m_dono;
}

