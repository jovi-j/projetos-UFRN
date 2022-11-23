# Classe Casa e Classe Rua

Classes são normalmente usadas para modelar dados assim como qualquer Registro de linguagens mais baixo nível. Dessa forma é comum
que exemplos básicos sejam compostos de modelagem de dados simples, por isso as dezenas de exemplos da classe Pessoa, Animal, etc.
Uma diferença inicial de classes para Registros é a possibilidade de modelarmos comportamentos que tem a ver com a classe/objeto em
questão e seus próprios atributos internos.

Dessa forma iremos modelar dois tipos de dados Casa e Rua:

- A classe Casa contem os seguintes atributos, todos privados:
    - Número, do tipo inteiro, contendo um número que representa aquela casa
    - Dono, do tipo string, contendo o nome do dono da casa
- Implemente ainda os seguintes métodos na classe casa:
    - `Casa(std::string dono)`: construtor com nome do dono da casa, o número deve ser inicializado com -1.
    - `int getNumero() e void setNumero(int n)`: retorna/modifica o número da casa.
    - `std::string getDono()`: retorna o nome do dono da casa.

- A classe Rua contém os seguintes atributos:
    - nome, uma string com o nome da rua
    - CEP, uma string no formato XX-XXX-XXX
    - Dois containers, A container contendo um conjunto de casas e B contendo outro contjunto de casas
- Na classe rua iremos implementar os seguintes métodos:
    - `Rua(std::string nome, std::string cep)`: construtor com o nome e cep da rua
    - `void adiciona_casa(Casa &c, std::string l)`: adiciona uma casa no vetor de casas do lado "A" ou lado "B" da rua, dependendo do valor de l. O número da casa deve ser modifiado conforme sua posição no vetor A ou B, casas do lado A só tem numeros pares, começando em 0; as casas do lado B possuem apenas números ímpares, começando em 1. Se o valor de l não for "A" ou "B" ignore este comando não adicionando a casa à rua.
    - `std::pair<Casa, Casa> vizinhos(Casa c)`: retorna um par contendo os visinhos da casa _c_. Uma casa é considerada
    vizinha se ela vem logo após ou é anterior à casa _c_ no vetor da Rua em que a casa _c_ está adicionada. Se a casa em questão não tiver
    anterior ou posterior, a casa correspondente deve ter o número igual a -1.
    - `std::pair<Casa, Casa> vizinhos(std::string nome)`: retorna um par contendo as casas que são vizinhas à pessoa com o _nome_ fornecido.
    - `std::vector<Casa> casa(std::string nome)`: retorna um vetor com todas as casas cujo dono tem o _nome_ passado.
    - `std::string endereco(std::string nome)`: retorna o endereço da casa de uma pessoa com _nome_ passado. 
    No formato: `Rua <nome>, No. <numero_casa>, Cep: <CEP>`, caso a casa não pertença à rua, retorne uma string vazia.


## Usando as funções em um programa

Usando as classes implementadas escreva um programa que lê da entrada padrão, inicialmente o nome da rua e o CEP, seguido por um conjunto
de pares contendo o Nome do Dono e o lado da Rua em que ele mora.

```
Osvaldo Montenegro
59-513-491
Ssanyu Humbert
A
Carina Nekesa
B
Maree Christina
A
João Evangeline
B
Wilhelm Nan
A
```

O programa deverá então imprimir o endereço de todas as pessoas adicionadas junto com seus vizinhos, o que ficaria, para o exemplo acima:

```
Ssanyu Humbert - Rua Osvaldo Montenegro, No. 0, Cep: 59-513-491
Vizinhos
Maree Christina
Carina Nekesa - Rua Osvaldo Montenegro, No. 1, Cep: 59-513-491
Vizinhos
João Evangeline
Maree Christina - Rua Osvaldo Montenegro, No. 2, Cep: 59-513-491
Vizinhos
Ssanyu Humbert
Wilhelm Nan
João Evangeline - Rua Osvaldo Montenegro, No. 3, Cep: 59-513-491
Vizinhos
Carina Nekesa
Wilhelm Nan - Rua Osvaldo Montenegro, No. 4, Cep: 59-513-491
Vizinhos
Maree Christina
```

## Executando os testes

Nesta questão para executar os testes você precisa fazer os seguintes comandos, no terminal, a partir do diretório onde este README está:

```
mkdir build
cd build
cmake ..
cmake --build . --target verify
```

## Importante

Esta questão mostra exemplos de documentação seguindo o estilo do [Doxygen](https://www.doxygen.nl/manual/docblocks.html), esta ferramenta
é usada junto com programas em C++ e outras linguagens para gerar documentação automaticamente com base em comentários escritos nos arquivos
de código.

