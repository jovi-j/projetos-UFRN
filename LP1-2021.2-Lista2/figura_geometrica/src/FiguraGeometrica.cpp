#include "FiguraGeometrica.hpp"
#include <sstream>
/*TODO implementação da classe*/
FiguraGeometrica::FiguraGeometrica(std::string nome, int tipo)
{
	this->nome = nome;
	if (tipo == 0)
	{
		this->tipo = RETANGULO;
	}
	else if (tipo == 1)
	{
		this->tipo = TRIANGULO;
	}
}

bool FiguraGeometrica::addPoint(std::pair<int, int> p)
{
	if (this->tipo == RETANGULO){
		if (this->pontos.size() == 2)
		{
			return false;
		}
		else
		{
			this->pontos.push_back(p);
			return true;
		}
	}
	else if (this->tipo == TRIANGULO){
		if (this->pontos.size() == 3)
		{
			return false;
		}
		else
		{
			this->pontos.push_back(p);
			return true;
		}
	}
	else
	{
		return false;
	}
}

float FiguraGeometrica::getArea(){
	if (this->tipo == RETANGULO){
		if (this->pontos.size() != 2){
			return -1;
		}
		else{
			int x1 = this->pontos[0].first;
			int y1 = this->pontos[0].second;
			int x2 = this->pontos[1].first;
			int y2 = this->pontos[1].second;
			int area = (x2 - x1) * (y2 - y1);
			if (area < 0)
				return area * -1;
			return area;
		}
	}else{
		if (this->pontos.size() != 3){
			return -1;
		}
		float area = 0;
		for (unsigned int i = 0; i < this->pontos.size() - 1; i++){
			area += (this->pontos[i].first * this->pontos[i+1].second) - (this->pontos[i].second * this->pontos[i+1].first);
		}
		area += (this->pontos[this->pontos.size() - 1].first * this->pontos[0].second) - (this->pontos[this->pontos.size() - 1].second * this->pontos[0].first);
		return area / 2;
	}
}


std::string FiguraGeometrica::toString(){
	std::stringstream ss;
	ss << this->nome << ":" << this->tipo << " - {";
	for (unsigned int i = 0; i < this->pontos.size(); i++){
		ss << "(" << this->pontos[i].first << ", " << this->pontos[i].second << ")";
	}
	ss << "}" << std::endl;
	return ss.str();
}
