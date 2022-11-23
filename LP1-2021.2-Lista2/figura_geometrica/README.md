# Adaptada da questão Adaptada da questão: Figuras Geométricas 1 (LoP)

Usando classes iremos escrever um programa para lidar com figuras geométricas. Para isso inicie criando
implementando uma classe FiguraGeometrica que possui possui todos os atributos privados:

- nome: atributo do tipo string
- tipo: atributo do tipo inteiro (você pode usar uma enumeração se quiser). Tipo pode ser 0-RETANGULO, 1-TRIANGULO
- pontos: atributo do tipo _container_, que guarda os pontos da figura geomética. Escolha o tipo de _container_ que preferir.

A classe deve ter os seguintes métodos:

1. `FiguraGeometrica(string, int)`: Construtor que recebe como parâmetro o tipo e o nome da figura, ele deve inicializar os atributos
tipo e nome com os parâmetros recebidos.
2. `bool addPoint(std::pair<float, float> ponto)`: Adiciona um ponto à figura e retorna `true` se bem sucedido. 
    - Se o tipo for RETANGULO, este método pode se chamado 2 vezes, com os pontos correspondentes ao ponto superior esquerdo e inferior direito do retângulo.
    - Se o tipo for TRIANGULO este método pode ser chamado 3 vezes, com os 3 pontos do triângulo, obrigatoriamente no sentido anti-horário. 
    - Depois de chamada a quantidade máxima de vezes para cada tipo de figura, este método deve retornar `false`. Ao retornar false o
    método deve e ignorar as coordenadas recebidas.
    - Suponha que todos os pontos fornecidos formam corretamente a figura, ou seja, não se precoupe com casos de erro relacionados aos pontos.
3. `float calcularArea()`: Calcula e retorna a área de acordo com a figura geométrica com base no seu tipo. Retorna -1 caso a figura não tenha os pontos completamente configurados.
4. `string toString()`: Retorna uma string descrevendo a figura no formato `nome:tipo - {(px_0,py_0), ..., (px_n,py_n)}`, exemplo: se o tipo for RETANGULO, o nome for "r1" e os pontos forem (1,2) e (3,5), a saída seria: `r1:RETANGULO - {(1.0,2.0), (3.0,5.0)}`.

Nesta questão iremos usar _testes unitários_ o que implica que você precisa primeiro implementar os métodos na classe, mesmo que não retornem/façam nada antes de compilar, caso contrário ocorrerá um erro de compilação, pois a classe não contém os métodos.

## Executando os testes

Nesta questão para executar os testes você precisa fazer os seguintes comandos, no terminal, a partir do diretório onde este README está:

```
mkdir build
cd build
cmake ..
cmake --build . --target run_tests
```

## Importante

Atente que, nesta questão, você precisa documentar os .h seguindo o formato doxygen apresentado na questão [casa_e_rua](../casa_e_rua)