#ifndef GENOME_H
#define GENOME_H

int condicao = 0;

void verificarInicio(char *codon);
void inverte(char* vetor,int tamanho);
void verificaAminoacido(char* vetorBase);
void verificarFim(char* codon);
void percorrerString(char* string, int tamanho);
void trocarBase(char* vetorbase, int tamanho);


#endif
