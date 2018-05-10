#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "genome.c"


int main(){
    setlocale(LC_ALL, "Portuguese");
    int initGenome = 22983;
    int finishGenome = 25781;
    int countInitGenome = 0;
    int ordem = 1;
    int optimalDistance = 30;
    int countPreencherVetor = 0;
    int tamanhoVetor = 0;
    char restricTest[10];
    //int x =0;

    char url[]="Complete_Genome.txt";
    char ch;
    FILE *arq;


    printf("Digite o inicio do Genome:\n");
    scanf("%d",&initGenome);
    printf("Digite o fim do Genome:\n");
    scanf("%d",&finishGenome);
    printf("Digite 1 para positivo e 0 para negativo: \n");
    scanf("%d",&ordem);
    printf("Total de caracters para analise do promotor \n");
    scanf("%d",&optimalDistance);


    tamanhoVetor = ((finishGenome) - initGenome)+1;
    char vetorGenome[tamanhoVetor];
    char vetorPromoter[optimalDistance];

    arq = fopen(url, "r");
    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        while(ch != EOF && countInitGenome <= finishGenome){
            ch = fgetc(arq);
        if(ch!='A' && ch!= 'T' && ch!= 'G' && ch!='C')countInitGenome--;
            else if(countInitGenome+1 >= initGenome){
                vetorGenome[countPreencherVetor] = ch;
                countPreencherVetor++;
            }
         countInitGenome++;
        }
    }
    fclose(arq);
    if(ordem == 0){
        inverte(vetorGenome, tamanhoVetor);
        trocarBase(vetorGenome, tamanhoVetor);
    }

    percorrerEImprimir(vetorGenome, tamanhoVetor);

    if(ordem == 0)
        buscarImprimirPromotorNegativo(vetorPromoter, finishGenome, optimalDistance);
    else
        buscarImprimirPromotorPositivo(vetorPromoter, initGenome, optimalDistance);

    restricts(countPreencherVetor, restricTest, initGenome, finishGenome);
    return 0;
}
