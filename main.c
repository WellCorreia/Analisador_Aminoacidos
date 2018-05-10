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
    int contRestric = 0;
    int quantRestrics = 0;
    int RestricInit = 0;
    int RestricFinish = 0;
    int tamStringRest = 0;

    //int x =0;


    char url[]="Complete_Genome.txt";
    char restric[] = "GAATTC";
    char restricTest[8];
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
    printf("Digite a restricao \n");
    scanf("%s",&restric);

    tamStringRest = strlen(restric);


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

    //restricts(restric, initGenome, finishGenome);

    fclose(arq);
    arq = fopen(url,"r");
    contRestric = 0;
    countPreencherVetor = 0;
    if(arq == NULL){
       printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
       while(ch != EOF){
            ch = fgetc(arq);
            if(ch=='A' || ch== 'T' || ch== 'G' || ch=='C'){
                restricTest[contRestric] = ch;
                contRestric++;
                RestricFinish++;
                countPreencherVetor++;
            }
            if(contRestric==tamStringRest){
                contRestric = 0;
                if(strcmp(restric,restricTest)==0){
                    quantRestrics ++;
                    printf("\n Restrict n:%d. Posicao:%d|%d \n",quantRestrics,RestricInit,RestricFinish);
                    if(RestricInit <= initGenome && RestricFinish>=finishGenome){
                        printf("Seu genoma esta presente no Restrict n:%d\n",quantRestrics);
                    }
                    RestricInit = RestricFinish+1;
                    ch = fgetc(arq);
                    countPreencherVetor++;
                }else{
                    countPreencherVetor-=(tamStringRest-1);
                    RestricFinish-=(tamStringRest-1);
                    fseek(arq,countPreencherVetor,SEEK_SET);
                }
            }

        }
    }
    return 0;
}
