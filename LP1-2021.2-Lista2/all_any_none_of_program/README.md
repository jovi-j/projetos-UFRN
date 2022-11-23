# Usando all_of, any_of e none_of

Na questão [all_any_none_of](../) implementamos um conjunto de funções que são capazes de testar algumas caracterísicas em
vetores. Usando essas funções é possível identificar caracterísiticas interessantes em coleções de elementos, independente
do tipod e _container_ usado para armazená-las, desde que exista uma estrutura de _Iterators_ que possamos usar para iterar
no _container_.

## Usando as funções em um programa

Usando as funções definidas, implemente um programa que usa as funções implementadas e lê uma entrada no seguinte formato:

- A primeira linha é a função que será executada, podendo ser all_of, none_of ou any_of.
- A segunda linha é o vetor de entrada, o primeiro número é o tamanho do vetor, seguido pelos seus elementos.
- A última linha é composta por um caractere e um número representando uma operação relacional, que deve ser usada com a função.

Por exemplo se a entrada for:

```
all_of
7 10 20 30 40 50 60 70
< 0
```

A saída do programa deve ser False, uma vez que não é verdade que todos elementos são menores do que 0. De forma análoga
se a entrada fosse:

```
any_of
-7 -10 20 30 40 50 60 -70
> 0
```

O programa deve imprimir True, uma vez que existe algum elemento que é maior do que 0.

## Executando os testes

Nesta questão para executar os testes você precisa fazer os seguintes comandos, no terminal, a partir do diretório onde este README está:

```
mkdir build
cd build
cmake ..
cmake --build . --target verify
```

## Sugestões

Nesta questão você tem a opção de utilizar tanto a sua versão para as funções all, none e any_of, quanto usar as versões
implementadas pela stl, com o mesmo nome. Sugiro que tente usar suas funções, porém fique à vontade para escolher. Apenas
lembre de explicitar o namespace, por exemplo `std::all_of(...)`, quando quiser usar a função da stl.

