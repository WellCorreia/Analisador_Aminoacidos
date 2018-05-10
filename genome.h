#ifndef GENOME_H
#define GENOME_H

int condicao = 0;

void verificarInicio(char *codon);
void inverte(char* vetor,int tamanho);
void verificaAminoacido(char* vetorBase);
void verificarFim(char* codon);
void percorrerString(char* string, int tamanho);
void trocarBase(char* vetorbase, int tamanho);
void percorrerEImprimir(char* vetorGenome, int tamanho);
int verificaPromotor(char* vetorPromoter, int optimalDistance);
void buscarImprimirPromotorPositivo(char* vetorPromoter, int initGenome, int optimalDistance);
void buscarImprimirPromotorNegativo(char* vetorPromoter, int finishGenome, int optimalDistance);
void restricts(int countPreencherVetor, char* restricTest, int initGenome, int finishGenome);

#endif
