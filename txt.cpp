#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
int verificar(char []);
void contar(char []);
int ascii(char [], char[]);
int convert(int );
FILE *arq;
FILE *arq_aux;
int tamglob;
int main(){
    int x;
    char path[20];
    printf("Digite o nome do arquivo\n");fflush(stdin);gets(path);
    x = verificar(path);
    if(x == -1){
        exit(1);
    }
    else{
    contar(path);
    }
}
int verificar(char path[20]){
    char aux[1];
    strcat(path,".txt");
    arq = fopen(path, "r");
    if(arq){
        ;
    }
    else{
        printf("Arquivo n%co encontrado!\nPrecione qualquer tecla para sair\n", 198);
        aux[1] = getch();
        return -1;
    }
    fclose(arq);
    }
void contar(char path[20]){
    char palavra2[50], linha[50], linha2[50]; int veri2[100];
    int deci, teste, tam, aux = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    arq = fopen(path, "r+");
    printf("Digite uma palavra para ser pesquisada no seu texto\n");fflush(stdin);gets(palavra2);
    printf("1 - Verificar se existe a palavra\n2 - Contar o n%cmero de ocorr%cncias desta palavra\n3 - Substituir todas as palavras por uma outra\n",163, 136);
    scanf("%d", &deci);
    tam = strlen(palavra2);
    char veri[tam];
    char palavra[tam];
    tamglob = tam;
    strcpy(palavra, palavra2);
    switch (deci){
    case 1 :{
        while(fgets(linha, sizeof linha, arq) != NULL){
            //printf("%d, ", strcmp(strdup(linha), palavra2));
            k = ascii(palavra, linha);
            if(k == 1){
                printf("A palavra %s existe\n", palavra);
                break;
            }
    }
    break;
    }
    case 2 :{
        while(fgets(linha, sizeof linha, arq) != NULL){
            //printf("%d, ", strcmp(strdup(linha), palavra2));
            k = ascii(palavra, linha);
            if(k == 1){
                j++;
            }
            
        }
        printf("%s repete %dx", palavra, j);
        break;
    }
    case 3 :{
        i = 0;
        printf("Por qual palavra deseja substituir?\n");fflush(stdin);gets(palavra2);
        while(fgets(linha, sizeof linha, arq) != NULL){
            //printf("%d, ", strcmp(strdup(linha), palavra2));
            arq_aux = fopen("temp.txt", "w");
            fclose(arq_aux);
            arq_aux = fopen("temp.txt", "r+");
            k = ascii(palavra, linha);
            if(k == 1){
                printf("Mudando %s para %s\n", linha, palavra2);
                fprintf(arq_aux, palavra2);
                fprintf(arq_aux, "\n");
            }
            else{
                printf("Colocando %s\n", linha);
                fprintf(arq_aux, linha);
                fprintf(arq_aux, "\n");
            }
            
        }
        fclose(arq);
        fclose(arq_aux);
        arq_aux = fopen("temp.txt", "r");
        do{
            int x = fgetc(arq_aux);
            if(feof(arq_aux)){
                break;
            }
            veri2[i]=x;
            //arq = fopen(path, "w");
            //fclose(arq);
            
            i++;
        }while(1);
        arq = fopen(path, "r+");
        
        //fprintf(arq, veri2);
        int x[sizeof veri2];
        int veri3;
        for(i = 0; i < sizeof veri2; i++){
            veri3 = veri2[i];
            x[i] = convert(veri3);
        }
        char x1[sizeof x];
        for(i = 0; i < sizeof x; i++){
            for(j = 0; j < 255; j++){
                if(x[i] == j){
                    x1[i] = char(x[i]);
                }
            }
        }
        //printf("\n%s", x1);
        fclose(arq_aux);
        break;
    }
    default :{
        printf("Op%c%co inv%clida", 135, 198, 160);
    }
    }
    rewind(arq);
    fclose(arq);
    }
int ascii(char palavra[50], char linha[50]){
    char y;
    int aux = 0;
    //x = toupper(x);
   // printf("(%d), \n", linha[1]);
   int x = strlen(palavra);
    for(int i = 0; i < x; i++){
        
        if(toupper(palavra[i]) == toupper(linha[i])){
            aux++;
        }
        else{
            aux = 0;
        }
    }
    if(aux >= 1){
        //printf(" - foi \n");
        return 1;
    }
    else{
    return 0;
    }
}
int convert(int veri2){
    char x;
        for(int i = 0; i < 255; i++){
            if(veri2 == i){
                //printf("%d,", i);
                return printf("%d,", i);
            }
        }
    }