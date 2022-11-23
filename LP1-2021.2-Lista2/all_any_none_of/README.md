# all_of, any_of e none_of

Nestes exercícios iremos desenvolver uma série de Funções que representam algoritmos típicos para manipulação de vetores, assim
todas as funções receberão um _range_ que deve ser operado como argumento.

O principal objetivo deste exercício é praticar programação usando estruturas de abstração de alto nível, onde seu código não precisa
saber qual o tipo de dados ele está operando. Para fazer isso o nosso código precisa usar funções __template__ associadas com ponteiros.
Os __templates__ dão suporte à criação de funções genéricas, enquanto os ponteiros nos ajudam a definir o _range_ onde as operações serão
executadas.

O objetivo secundário é adquirir exeperiencia de programação na construção de bibliotecas de operações típicas em vetores, chamaremos essa
biblioteca de graal(Generic Array Algorithm Library). Através da experiencia de construir essa bibiliteca, iremos experimentar a importância da abstração de dados e reusabilidade de código no desenvolvimento de aplicações.

## O padrão de programação orientado à Iteradores (Iterator Programming Pattern)

Um _Iterator_ é usualmente representado por um objeto(uma instancia de uma Classe do paradígma de Programação Orientado à Objetos)
que pode iterar sobre um container(que usualmente, também é um Objeto) sem saber como o container é implementado ou funciona internamente.
Na STL, os iteradores são o método mais usado para acessar os elmentos em listas e outros containers.

Por exemplo, se quisermos itear sobre todos os elementos em um `std::vector` de inteiros para imprimir todos os elementos o código seria desta forma:

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> vect;               // Declara um vetor de inteiros.
    for (auto i(0) ; i < 6 ; ++i)
        vect.push_back(i);          // Insere elementos no vetor
    vector<int>::const_iterator it; // Declara um iterator
    it = vect.begin();              // Atribui ao iterator o inicio do vetor
    while (it != vect.end()) {      // Enquanto não chegou no fim
        cout << *it << " ";         // imprime o valor do elemento "apontado" pelo iterato
        ++it;                       // move para o próximo elemento
    }
    cout << endl;
}
```
Veja que o uso dos Iterators é muito similar aos __ponteiros__. De fato, informalmente, um Iterator pode ser uma representação
de um ponteiro encapsulada em uma representação mais abstrata(e com mais possibilidades).

Quando virmos mais à frente alguns containers da STL, vocé constatará que todas essas classes tem quatro métodos básicos que são projetados
para ajudar ao usuário interar sobre os elementos:
- begin() retorna um _iterator_ que aponta para o primeiro elemento de um container
- end() retorna um _iterator_ que aponta para o final de um container. O final é representado por uma posição que está logo após o último elemento.
- cbegin() retorna um _iterator_ (read-only) que aponta para o primeiro elemento de um container
- cend() retorna um _iterator_ (read-only) que aponta para o final de um container. O final é representado por uma posição que está logo após o último elemento.

Um fato importante é que os _iterators_ retornados por __cend()__ e __end()__ apontam sempre para uma posição _após_ o ultimo elemento do container, como mostrado abaixo. Dessa forma, se deseramos definir um _range_ de elementos em qualquer container sempre nos referimos a um intervalo \[__begin()__, __end()__) -ou seja, sempre definimos um intevalo
fechado-aberto!

```
       begin()                              end()
          ↓                                   ↓
Índice |  0|  1| 2| 3|  4|  5| 6| 7|  8| 10|  X|
``` 

# Atividade

Implemente três funções all_of, any_of e none_of. Todas as três funções recebem um range \[first,last), um _predicado_ p. A função all_of retorna
verdadeiro quando o _predicado_ p é verdadeiro para __todos os elementos__ do range. A função any_of retorna true quando o _predicado_ p é verdadeiro
para __pelo menos um elemento__ do range. A função none_of retorna verdadeiro se o _predicado_ p é __falso para todos os elementos no range__.

As assinaturas das funções devem ser:
```c++
template <typename Itr , typename Predicate >
bool all_of ( Itr first , Itr last , Predicate p );
template <typename Itr , typename Predicate >
bool any_of ( Itr first , Itr last , Predicate p );
template <typename Itr , typename Predicate >
bool none_of ( Itr first , Itr last , Predicate p );
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- p - uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário.

Nest exercício o Predicado é uma função recebida por parâmetro, de forma que p possa ser usada como `p(*it1)`. Use essa função para
testar se um valor no range satisfaz o _predicado p_. Por exemlo, se você quer testar se o elemento apontado por it1 não satisfaz p
voce usaria ``!p(*it1)``.

## Retorno
- all_of: retorna verdadeiro se todos os elementos do range satisfazem p, falso caso contrário
- any_of: retorna verdadeiro se ao menos um elemento do range satisfaz p, falso caso contrário
- none_of: retorna verdadeiro se todos os elementos do range __não__ satisfazem p, falso caso contrário

## Executando os testes

Nesta questão para executar os testes você precisa fazer os seguintes comandos, no terminal, a partir do diretório onde este README está:

```
mkdir build
cd build
cmake ..
cmake --build . --target run_tests
```
