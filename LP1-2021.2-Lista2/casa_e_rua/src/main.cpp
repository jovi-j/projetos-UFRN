#include "Casa.hpp"
#include "Rua.hpp"

/*
TODO: implementar o main
*/
int main(){
    // receber o nome e CEP da rua
    std::string nome, cep;
    std::getline (std::cin, nome);
    std::getline (std::cin, cep);
    // criar a rua
    Rua r = Rua(nome, cep);
    // receber o nome do dono da casa e o lado da casa
    std::string dono, lado;
    int numeroLA = 0, numeroLB = 1;
    while(EOF != std::cin.peek()){
        std::getline(std::cin, dono);
        std::getline(std::cin, lado);
        if(lado == "A"){
            // criar a casa
            Casa c = Casa(dono);
            // atualizar o numero da casa
            numeroLA += 2;
            c.setNumero(numeroLA);
            // adicionar a casa na rua
            r.adiciona_casa(c, lado);
        }
        else if(lado == "B"){
            // criar a casa
            Casa c = Casa(dono);
            // atualizar o numero da casa
            numeroLB +=2;
            c.setNumero(numeroLB);
            // adicionar a casa na rua
            r.adiciona_casa(c, lado);
        }else{
            // caso não seja A nem B
            continue;
        }
    }
    // mostrar o endereço de cada casa e seus vizinhos
    for(Casa c: r.getA()){
        std::cout << r.endereco(c.getDono()) << std::endl;
        std::pair<Casa, Casa> p = r.vizinhos(c);
        std::cout << "Vizinhos" << std::endl;
        std::cout << p.first.getDono() << std::endl;
        std::cout << p.second.getDono() << std::endl;
    }

    for(Casa c: r.getB()){
        std::cout << r.endereco(c.getDono()) << std::endl;
        std::pair<Casa, Casa> p = r.vizinhos(c);
        std::cout << "Vizinhos" << std::endl;
        std::cout << p.first.getDono() << std::endl;
        std::cout << p.second.getDono() << std::endl;
    }
    return EXIT_SUCCESS;
}