#include <stdio.h>
#include <stdlib.h>

int main()
{
    int initGenome = 22983, finishGenome = 25781, countInitGenome = 0;

    char url[]="Complete_Genome.txt";
	char ch;
	FILE *arq;

	arq = fopen(url, "r");
	if(arq == NULL){
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	}else{
	    while(ch != EOF && countInitGenome != finishGenome){
            countInitGenome++;
            ch = fgetc(arq);
            if(countInitGenome >= initGenome){
                putchar(ch);
            }
	    }
	}
	fclose(arq);
    return 0;
}
