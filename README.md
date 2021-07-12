# Projeto Keno
Este programa é uma implementação do jogo [Keno](https://en.wikipedia.org/wiki/Keno) em C++. Ele é capaz de ler um arquivo de apostas, sortear números aleatórios e imprimir no terminal o resultado de cada rodada.

## Como compilar esse projeto?
A compilação do projeto é feita utilizando o **GCC**.
Inicialmente, abra o terminal e crie dentro da pasta do projeto um diretório chamado _build_:
```
mkdir build
```
Depois, vá até a pasta *src*:
```
cd src/
```
Agora, execute o seguinte comando para compilar todos os arquivos `.cpp` do projeto em um único executável chamado _keno_:
```
g++ main.cpp kenoBet.cpp betFile.cpp userInterface.cpp -o ../build/keno
```
Esse comando irá criar o arquivo _keno_ dentro da pasta _build_.

## Como executar o projeto?
Retorne até a pasta inicial do projeto e vá até a pasta *build*:
```
cd build/
```
Dentro dessa pasta, crie um arquivo de apostas com extensão `.dat`:
```
> bet.dat
```
O programa possui funções de validação do arquivo de apostas, portanto ele deve ser escrito corretamente para que não haja erros na execução.

Por fim, execute o arquivo criado na compilação utilizando como argumento o arquivo de apostas:
```
./keno bet.dat
```

## Formato de um arquivo de apostas
Logo abaixo é possível visualizar um exemplo válido para um arquivo de apostas.
```
1500.0  
3  
21 12 64
```
As três linhas ilustradas para arquivo de apostas significam, em ordem:

-   número real representando a quantidade de crédito inicial do jogador (*initial credit* ou **IC**);

-   número inteiro representando a quantidade de rodadas que serão executadas (*number of rounds* ou **NR**);

-   conjunto de até 15 números inteiros únicos em qualquer ordem separados por espaço (chamado de *spots*).

## Como executar o conjunto de testes
Junto com o programa é disponibilizado um conjunto de arquivos de teste para demonstrar sua execução. Eles estão localizados na pasta _data_ e são executados a partir do programa compilado na pasta _build_.
Os comandos para executar os arquivos válidos são:
```
./keno ../data/bet_5_spots.dat
./keno ../data/bet_10_spots.dat
./keno ../data/bet_15_spots.dat
```
Que efetuam apostas válidas com 5, 10 e 15 _spots_, reespectivamente.
Para executar casos onde o programa detecta apostas inválidas, os comandos são:
```
./keno ../data/bet_invalid_char.dat
./keno ../data/bet_invalid_IC.dat
./keno ../data/bet_invalid_NR.dat
./keno ../data/bet_out_of_range_spot.dat
./keno ../data/bet_too_many_spots.dat
```
Que efetuam as seguintes apostas inválidas, reespectivamente:
- Aposta com caractéres estranhos;
- Aposta com **IC** (_initial credit_) inválido;
- Aposta com **NR** (_number of rounds_) inválido;
- Aposta com _spots_ fora do intervalo [0, 80];
- Aposta com mais de 15 spots.

## Limitações do projeto
As limitações do projeto são:
- **TUI** (_text-based user interface_) não muito elaborada, que apresenta poucos elementos gráficos que melhoram a aparência do programa;
- Impossibilidade de executar mais de um arquivo de apostas com uma só linha de comando;
- O jogo não mantém salvo o resultado de apostas anteriores mediante um arquivo de LOG.

## Autor
Gabriel Rocha, 12/07/2021
- Github: https://github.com/GabrielR-d-S
- Email: gabrielrochasant@gmail.com
