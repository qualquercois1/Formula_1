# Fórmula 1
Este é um trabalho, do aluno **Cássio dos Santos Rodrigues**, da matéria PC1(Programação de Computadores 1) ministrada pelo professor **Daniel Saad**, do curso de Ciência da Computação do IFB (Instituto Federal de Brasília) Campus Taguatinga.

## Requisitos
Para execução do código é necessário ter instalado o compilador GCC na versão 10.2.0 ou mais recente, e o make para geração de arquivos através do makefile.

## Execução
Para executar basta seguir os seguintes passos:
1. Baixar o projeto em algum diretório de sua preferência.
2. Acessar este diretório pelo terminal.
3. Executar o comando "`make`" para criação dos arquivos.
4. E por fim executar o comando "`./main <arquivo-de-entrada> <arquivo-de-saida>`" para executar o código

OBS. A criação dos arquivos de entrada e saída fica por conta do usuário e devem estar no mesmo diretório de execução do projeto.

O resultado é mostrado no arquivo no saída inserído pelo usuário de acordo com o arquivo de entrada inserído pelo usuário.

## Descrição
O objetivo deste projeto é implementar um sistema em C para calcular e exibir a classificação final dos pilotos e das equipes no campeonato mundial de Fórmula 1 com base nos resultados das corridas.

### Arquivo de Entrada
O arquivo de entrada possui a informação sobre os pilotos de Fórmula 1, as equipes, e o resultado atingido pelos pilotos em cada etapa.

A primeira linha do arquivo de entrada possui dois inteiros `N` e `M`, separados por um espaço, que indicam, respectivamente, o número equipes e o número de etapas. As próximas `N` linhas possuem o nome de um piloto e o nome da sua equipe.

Em seguida, há a descrição dos resultados de cada uma das `M` etapas. Cada etapa possui `N` linhas com o nome dos pilotos. A primeira linha da descrição de uma etapa possui o nome do piloto que venceu aquela etapa, a segunda linha, o nome do piloto que chegou em segundo lugar, e assim por diante.

Existe um separador `---` entre a descrição dos pilotos e equipes e o início da descrição das etapas e também ao final de cada descrição de uma etapa.

#### Restrições:
- `2 ≤ N ≤ 40`;
- `1 ≤ M ≤ 1000`;
- Cada equipe é composta de dois pilotos.
- O nome dos pilotos e das equipes consistem apenas de letras maiúsculas ou minúsculas e hífen, além de estarem limitados a 30 caracteres. Não há espaços.

### Arquivo de Saída

O arquivo de saída lista todos os pilotos em ordem de classificação do campeonato, com a posição final, número de pontos, vitórias e pódios (números de vezes em que o piloto chegou na terceira posição ou superior). Cada informação de um piloto está em uma linha, e os dados estão separados por um espaço.

Após a classificação dos pilotos, consta a classificação dos construtores, também em ordem decrescente. Na classificação dos construtores, é impresso, em cada linha do arquivo de saída, a posição da equipe, seu nome, e sua quantidade de pontos.

Existe um separador `---` entre as classificações dos pilotos e equipes.

## Funcionalidades do Código:
1. [Read](./read.c): Abre o arquivo de entrada e faz a leitura passando as informações para as estruturas de dados corretas.
2. [Process](./process.c): Com as informações nas estruturas faz os calculos de pontuações de cada time.
3. [Order](./order.c): Ordena os Pilotos e Times de acordo com pontuação e número de chegadas.
4. [Write](./write.c): Abre o arquivo de saída e escreve o resultado obtido nele.
5. [Main](./main.c): Faz a chamada das funções.

## Links

Os códigos podem ser obtidos no github: [Fórmula 1](https://github.com/qualquercois1/Formula_1/tree/master) na master branch.