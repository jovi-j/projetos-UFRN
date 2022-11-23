# Super Bingo

O jogo super bingo consiste num globo contendo um conjunto de bolas numeradas, sorteadas uma a uma, de forma similar ao jogo Bingo. Porém, no início da partida, ao invés de receber apenas uma cartela para jogar, cada jogador aposta em uma quantidade de cartelas que já existem. Um jogador não pode apostar na mesma cartela mais de uma vez, porém jogadores diferentes podem apostar na mesma cartela. O jogo tem 50 cartelas que são geradas automaticamente no inicio, assim a aposta do jogador é um conjunto de até 10 números entre 1 e 50, representando
quais cartelas ele está apostando.

Para apostar em 1 cartela o jogador gasta R$ 1,00, apostar em 2 o jogador gasta R$ 2,00, em 3 ele gasta R$ 4,00, e assim até a aposta em 10 cartelas que custa R$ 512,00. O jogo executa até que um jogador complete ao menos 1 cartela, ou seja, se ele acertar os 10 números de uma 
cartela específica. Depois disso o jogo acaba e o premio é calculado da seguinte forma:
1. O jogador que acerta mais números no total em todas as suas cartelas e tem ao menos uma cartela completa vence. O jogador recebe a quantidade de números acertados vezes R$ 5, somada à R$ 20,00 vezes a quantidade de cartelas completadas por ele. Um mesmo número pode 
ser contabilizado mais de uma vez, por exemplo, se o número 1  está em 3 cartelas do jogador, ele é contado 3 vezes! É possível ter 
mais de um vencedor, desde que ambos tenham ao menos uma cartela completa.
2. Os demais jogadores que não ganham qualquer coisa.

## Atividade:

Neste problema, como cada jogador pode apostar na mesma cartela o uso de Ponteiros e new/delete é util pois nos poupa de ter que marcar
cartelas de cada jogador toda vez que um número é sorteado. Ao invés disso, cada jogador terá uma **referencia** para as cartelas em que
apostou, fazendo com que o precisemos marcar o número em uma dada cartela apenas uma vez. Para fazer isso implemente o programa principal da seguinte forma:

1. Comece inicializando a seed do jogo através do método `iniciaSeed`. A seed do jogo é a primeira linha da entrada.
    - Este método só precisa ser chamado uma vez!
2. Crie e armazene 50 cartelas no vetor `cartelas` já declarado no main.
    - As cartelas terão 10 números aleatórios entre os presentes no globo.
    - **não chame srand diretamente no seu código e nem mais de uma vez, caso contrário os testes não irão funcionar!**.
3. Leia a aposta de cada jogador da entrada
    - Busque a Cartela correspondente no vetor `cartelas` e use o método `adicionaCartela` da classe jogador para armazenar 
    atribuir à cartela apostada ao jogador sendo processado.
    - Após todas as apostas do jogador terem sido armazenadas, adicione o jogador no vetor `jogadores`.
4. Realize o sorteio de um dos 25 números do bingo usando método `getNumeroAleatorio` da classe Cartela.
    - Se o número retornado já foi sorteado, apenas chame o método novamente até que um novo número seja retornado.
    - Use o método `marcarNumero` da classe Cartela para marcar o número sorteado. Após marcar todas as cartelas, verifique se alguma 
    cartela, __de algum jogador__, está completa com método `estaCompleta`.
5. Se alguma cartela for completada após a marcação, finalize o jogo, exiba os vencedores e a quantidade de dinheiro recebida por cada um.
Caso contrário, retorne para o passo 4.
    - Itere no vetor de jogadores e determine a quantidade de pontos do vencedor, depois descubra quais jogadores atingiram 
    aquela pontuação.
    - Para calcular o valor recebido use os métodos `getTotalNumeros` e `getTotalCartelas` da classe jogador. 
    **Esses métodos precisam ser implementado por você!**
    - Ao final imprima os vencedores de acordo com o formato especificado
6. Após imprimir os vecedores, antes do programa terminar, libere a memória alocada dinamicamente de forma que não hajam leaks ao fim
do programa.


Um exemplo de entrada e saída segue abaixo, observe que a aposta supõe que a primeira cartela tem __indice__ 1:

```
10
Julio 4 12 13 1 3
Selan 10 2 3 5 1 9 8 17 20 2 3
Isaac 7 1 43 1 2 44 11 33
```

Essa entrada irá gerar uma saída no formato:

```
Vencedores
Isaac
>>Números acertados 12
>>Cartelas completadas 1
>>Dinheiro recebido R$ 80
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

