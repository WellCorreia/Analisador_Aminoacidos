#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "genome.h"

void percorrerEImprimir(char* vetorGenome, int tamanho);
void verificaPromotor(char* vetorPromoter, int optimalDistance);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int initGenome = 22983;
    int finishGenome = 25781;
    int countInitGenome = 0;
    int ordem = 1;
    int optimalDistance = 30;
    int countPreencherVetor = 0;
    int tamanhoVetor = 0;
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

    if(ordem == 0){
        inverte(vetorGenome, tamanhoVetor);
        trocarBase(vetorGenome, tamanhoVetor);
    }

    //percorrerString(vetorGenome,tamanhoVetor);
    percorrerEImprimir(vetorGenome, tamanhoVetor);
    countPreencherVetor = 0;
    countInitGenome = 0;

    fclose(arq);
    arq = fopen(url,"r");
    if(arq == NULL){
       printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
       while(ch != EOF && countInitGenome <= initGenome){
            ch = fgetc(arq);

        if(ch!='A' && ch!= 'T' && ch!= 'G' && ch!='C')countInitGenome--;
            else if(countInitGenome+1 >= (initGenome-optimalDistance)){
            vetorPromoter[countPreencherVetor] = ch;
                    countPreencherVetor++;
        }
         countInitGenome++;
        }
    }
    printf("\n\nPROMOTER:\n\n");
    //percorrerEImprimir(vetorPromoter,optimalDistance);
    verificaPromotor(vetorPromoter,optimalDistance);

    return 0;
}

void verificaPromotor(char* vetorPromoter, int optimalDistance){
    int x;
    char promotor[10];
    char FinishPromotor[10];
    int count =0;
    int countFinish = 0;
    for(x=0;x<optimalDistance;x++){
        //printf("%c",vetorPromoter[x]);
        if(vetorPromoter[x] == 'A' || vetorPromoter[x] =='T'){
            promotor[count] = vetorPromoter[x];
            count++;
        }else{
            if(countFinish==0){
                    strcpy(FinishPromotor,promotor);
                    countFinish = count;
            }
            if(count >= countFinish){
                    strcpy(FinishPromotor,promotor);
                    countFinish = count;
            }
            count = 0;
        }
    }
    printf("\n\n TESTE: \n\n");
        printf("Promotor: %s",FinishPromotor);



}

void imprimirString(char* string, int tamanho){
    int x;
    for(x = 0; x < tamanho; x++){
        printf("%c", string[x]);
    }
}

void percorrerEImprimir(char* vetorGenome, int tamanho){
    int x;
    for(x=0; x<tamanho; x++){
        if(x%3 == 0){
            printf(" ");
        }
        printf("%c",vetorGenome[x]);
    }
}

/*void percorrerString(char* string, int tamanho){
    int x, y=0;
    char codon[3];
    for(x = 0; x < tamanho; x++){
        if(y == 3){
            codon[y]= 0;
        printf("%s",codon);
            //verificarInicio(codon);
            y = 0;
        }
        if(string[x]=='\n'){
            y--;
        }else{
            codon[y] = string[x];
        }
        y++;
    }
}*/
void inverte(char* vetor,int tamanho){
    int x,y;
    int aux;

    for(x = 0, y = tamanho - 1; x<y; ++x,--y){
      aux = vetor[y];
      vetor[y] = vetor[x];
      vetor[x] = aux;
    }
}

void verificarInicio(char* codon){
    if(strcmp(codon,"ATG") == 0 && condicao == 0 ){
        printf("\n INICIO\n");
        verificaAminoacido(codon);
        condicao = 1;
    }
    if(condicao == 1){

        printf("%s ",codon);
        verificaAminoacido(codon);
        verificarFim(codon);
    }
}

void verificarFim(char* codon){
    if((strcmp(codon,"TGA") == 0)||(strcmp(codon,"TAA") == 0)||(strcmp(codon,"TAG") == 0)){
        printf("FIM \n");
        condicao = 0;

    }
}

void trocarBase(char* vetor, int tamanho){
    int x;
    for(x = 0; x < tamanho; x++){
        if(vetor[x] == 'G')
            vetor[x] = 'C';
        else if(vetor[x] == 'C')
            vetor[x] ='G';
        else if(vetor[x] == 'T')
            vetor[x] = 'A';
        else if(vetor[x] == 'A')
            vetor[x] = 'T';
    }

}
void verificaAminoacido(char* vetorBase){

    if(strcmp(vetorBase, "TTT") == 0 || strcmp(vetorBase, "TTC")== 0 ){
        printf("Fenilalanina (Fen)\n");
    }else if(strcmp(vetorBase, "TTA")== 0 || strcmp(vetorBase, "TTG")== 0 || strcmp(vetorBase, "CTT")== 0 || strcmp(vetorBase, "CTC")== 0
    || strcmp(vetorBase, "CTA")== 0 || strcmp(vetorBase, "CTG")== 0){
        printf("Leucina (Leu)\n");
    }else if(strcmp(vetorBase, "ATT")== 0 || strcmp(vetorBase, "ATC")== 0 || strcmp(vetorBase, "ATA")== 0){
        printf("Isoleucina (Ile)\n");
    }else if(strcmp(vetorBase, "ATG")== 0){
        printf("\nMetionina (Met) - (Cordão de Iniciação)\n\n");
    }else if(strcmp(vetorBase, "GTT")== 0 || strcmp(vetorBase, "GTC")== 0 || strcmp(vetorBase, "GTA")== 0 || strcmp(vetorBase, "GTG")== 0 ){
        printf("Valina (Val)\n");
    }
    else if(strcmp(vetorBase, "TCT")== 0 || strcmp(vetorBase, "TCC")== 0 || strcmp(vetorBase, "TCA")== 0 || strcmp(vetorBase, "TCG")== 0
    || strcmp(vetorBase, "AGT")== 0 || strcmp(vetorBase, "AGC")== 0){
        printf("Serina (Ser)\n");
    }
    else if(strcmp(vetorBase, "CCT")== 0 || strcmp(vetorBase, "CCC")== 0 || strcmp(vetorBase, "CCA")== 0 || strcmp(vetorBase, "CCG")== 0){
        printf("Prolina (Pro)\n");
    }
    else if(strcmp(vetorBase, "ACT")== 0 || strcmp(vetorBase, "ACC")== 0 || strcmp(vetorBase, "ACA")== 0 || strcmp(vetorBase, "ACG")== 0){
        printf("Treonina (Tre)\n");
    }
    else if(strcmp(vetorBase, "GCT")== 0 || strcmp(vetorBase, "GCC")== 0 || strcmp(vetorBase, "GCA")== 0 || strcmp(vetorBase, "GCG")== 0){
        printf("Alanina (Ala)\n");
    }
    else if(strcmp(vetorBase, "TAT")== 0 || strcmp(vetorBase, "TAC")== 0){
        printf("Tirosina (Tir)\n");
    }
    else if(strcmp(vetorBase, "CAT")== 0 || strcmp(vetorBase, "CAC")== 0){
        printf("Histidina (His)\n");
    }
    else if(strcmp(vetorBase, "CAA")== 0 || strcmp(vetorBase, "CAG")== 0){
        printf("Glutamina (Glu)\n");
    }
    else if(strcmp(vetorBase, "AAT")== 0 || strcmp(vetorBase, "AAC")== 0){
        printf("Asparagina (Asn)\n");
    }
    else if(strcmp(vetorBase, "AAA")== 0 || strcmp(vetorBase, "AAG")== 0){
        printf("Lisia (Lis)\n");
    }
    else if(strcmp(vetorBase, "GAT")== 0 || strcmp(vetorBase, "GAC")== 0){
        printf("Ácido Aspártico (Asp)\n");
    }
    else if(strcmp(vetorBase, "GAA")== 0 || strcmp(vetorBase, "GAG")== 0){
        printf("Ácido Glutâmico (Glu)\n");
    }
    else if(strcmp(vetorBase, "TGT")== 0 || strcmp(vetorBase, "TGC")== 0){
        printf("Cisteína (Cis)\n");
    }
    else if(strcmp(vetorBase, "TGG")== 0){
        printf("Triptofano (Trp)\n");
    }
    else if(strcmp(vetorBase, "CGT")== 0 || strcmp(vetorBase, "CGC") == 0|| strcmp(vetorBase, "CGA")== 0 || strcmp(vetorBase, "CGG")== 0
    || strcmp(vetorBase, "AGA")== 0 || strcmp(vetorBase, "AGG")== 0){
        printf("Arginina (Arg)\n");
    }
    else if(strcmp(vetorBase, "GGT")== 0 || strcmp(vetorBase, "GGC") == 0|| strcmp(vetorBase, "GGA")== 0 || strcmp(vetorBase, "GGG")== 0){
        printf("Glicina (Gli)\n");
    }
    else if(strcmp(vetorBase, "TAA")== 0 || strcmp(vetorBase, "TAG")== 0 || strcmp(vetorBase, "TGA")== 0){
        printf("\nCordão de Finalização\n\n");
    }
}
