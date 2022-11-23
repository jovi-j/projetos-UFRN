#include "Rua.hpp"

/*
TODO: implementação dos métodos
*/


Rua::Rua(std::string nome, std::string cep){
	this->m_nome = nome;
	this->m_CEP = cep;
	this->m_A = std::vector<Casa>();
	this->m_B = std::vector<Casa>();
}

void Rua::adiciona_casa(Casa &c, std::string l){
	if(l == "A"){
		this->m_A.push_back(c);
	}
	else if(l == "B"){
		this->m_B.push_back(c);
	}
}

std::pair<Casa, Casa> Rua::vizinhos(Casa c){
	std::pair<Casa, Casa> p = std::make_pair(Casa(""), Casa(""));
	for(int i = 0; i < this->m_A.size(); i++){
		if(this->m_A[i].getNumero() == c.getNumero()){
			if(i == 0 && this->m_A.size() > 2){
				p.second = this->m_A[i+1];
			}
			else if(i == this->m_A.size()-1 && this->m_A.size() > 2){
				p.first = this->m_A[i-1];
			}
			else{
				p.first = this->m_A[i-1];
				p.second = this->m_A[i+1];
			}
		}
	}
	for(int i = 0; i < this->m_B.size(); i++){
		if(this->m_B[i].getNumero() == c.getNumero()){
			if(i == 0 && this->m_B.size() > 2){
				p.first = this->m_B[this->m_B.size()-1];
				p.second = this->m_B[i+1];
			}
			else if(i == this->m_B.size()-1 && this->m_B.size() > 2){
				p.first = this->m_B[i-1];
				p.second = this->m_B[0];
			}
			else{
				p.first = this->m_B[i-1];
				p.second = this->m_B[i+1];
			}
		}
	}
	return p;
}

std::pair<Casa, Casa> Rua::vizinhos(std::string nome){
	std::pair<Casa, Casa> p = std::make_pair(Casa(""), Casa(""));
	for(int i = 0; i < this->m_A.size(); i++){
		if(this->m_A[i].getDono() == nome){
			if(i == 0 && this->m_A.size() > 2){
				p.second = this->m_A[i+1];
			}
			else if(i == this->m_A.size()-1 && this->m_A.size() > 2){
				p.first = this->m_A[i-1];
			}
			else{
				p.first = this->m_A[i-1];
				p.second = this->m_A[i+1];
			}
		}
	}
	for(int i = 0; i < this->m_B.size(); i++){
		if(this->m_B[i].getDono() == nome){
			if(i == 0 && this->m_B.size() > 2){
				p.second = this->m_B[i+1];
			}
			else if(i == this->m_B.size()-1 && this->m_B.size() > 2){
				p.first = this->m_B[i-1];
			}
			else{
				p.first = this->m_B[i-1];
				p.second = this->m_B[i+1];
			}
		}
	}
	return p;
}

std::vector<Casa> Rua::casa(std::string nome){
	std::vector<Casa> v;
	for(int i = 0; i < this->m_A.size(); i++){
		if(this->m_A[i].getDono() == nome){
			v.push_back(this->m_A[i]);
		}
	}
	for(int i = 0; i < this->m_B.size(); i++){
		if(this->m_B[i].getDono() == nome){
			v.push_back(this->m_B[i]);
		}
	}
	return v;
}

std::string Rua::endereco(std::string nome){
	for(Casa c : this->m_A){
		if(c.getDono() == nome){
			return "Rua " + this->m_nome + " A, No. " + std::to_string(c.getNumero()) + ", " + this->m_CEP;
		}
	}
	for(Casa c : this->m_B){
		if(c.getDono() == nome){
			return "Rua " + this->m_nome + " B, No. " + std::to_string(c.getNumero()) + ", " + this->m_CEP;
		}
	}
	return "";
}

std::vector<Casa> Rua::getA(){
	return this->m_A;
}

std::vector<Casa> Rua::getB(){
	return this->m_B;
}