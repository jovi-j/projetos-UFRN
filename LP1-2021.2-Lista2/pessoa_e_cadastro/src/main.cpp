

#include "Pessoa.hpp"
#include "Cadastro.hpp"

#define CE = "Cadastro Estadual"
#define SIGLA_CE = "CE"
#define CM = "Cadastro Municipal"
#define SIGLA_CM = "CM"
#define SUS = "Sistema Único de Saúde"
#define SIGLA_SUS = "SUS"

int main(){
    
    Cadastro sus = Cadastro(SIGLA_SUS, SUS);
    // for each two lines in file, create a new Pessoa with name, cpf and endereco.
    // Then, recives an input with a cpf and a SIGLA, and assign the Pessoa to the Cadastro with the SIGLA.

    return EXIT_SUCCESS;
}