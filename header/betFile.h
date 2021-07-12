#ifndef BETFILE_H
#define BETFILE_H

#include <fstream>
#include <vector>
#include <iostream>

/*!
 * Checa se o arquivo de apostas está escrito corretamente e se todos valores estão
 * dentro do padrão. Fecha o programa caso contrário.
 * @param f Arquivo que será lido. */
void validate(std::ifstream & f);


/*!
 * Lê a quantidade de créditos da aposta no arquivo
 * @param f Arquivo que será lido.
 * @return Float representando os créditos da aposta. */
float read_credits(std::ifstream & f);

/*!
 * Lê o número de rounds que serão jogados na aposta.
 * @param f Arquivo que será lido.
 * @return Int representando o número de rounds. */
int read_rounds(std::ifstream & f);

/*!
 * Lê e armazena os spots do arquivo de apostas em um vector
 * @param f Arquivo que será lido.
 * @return Vector com os spots lidos do arquivo. */
std::vector<short int> read_spots(std::ifstream & f);

#endif
