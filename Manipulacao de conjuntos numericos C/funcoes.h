#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
    int tamanho;
    int *array;
}Conjunto;

int obterTamanhoConjunto(){
    int tamanho=0;
    do{
        printf("\nDigite o Tamanho do Conjunto:\n");
        scanf("%d", &tamanho);
        if(tamanho<=0)printf("\nO Tamanho tem que ser maior que zero(>0)\n");
    }while(tamanho<=0);
    return tamanho;
}

 void gerarConjunto(Conjunto *const pConjunto, int tamanho){

    pConjunto -> array = malloc(tamanho * sizeof(int));
    if(pConjunto -> array == NULL){
        printf("\nErro ao criar conjunto para o array\n");
        return;
        
    }else{
        printf("\nConjunto criado com sucesso\n");
    }
    pConjunto -> tamanho = tamanho;
    int seed = (int) time(NULL);
    srand(seed);
    for(int i = 0; i < tamanho; i++){
        pConjunto -> array[i] = rand() % 1001;
    }
 }

 void mostrarConjunto(Conjunto const *const pConjunto){
    printf("N = { %d", pConjunto -> array[0]);
    for(int i = 1 ; i < pConjunto -> tamanho;i++){
        printf(" ,%d" ,pConjunto -> array[i]);
    }
    printf(" }\n");
    
 }

 int buscaSequencial(Conjunto const  *const pConjunto, int elemento){
    for(int i = 0 ; i < pConjunto -> tamanho; i++){
        if(pConjunto -> array[i] == elemento) return i;
    }  
    return -1;
}

void ordenarConjunto(Conjunto *const pConjunto)
{
    for(int j = 0; j < pConjunto->tamanho - 1; j++){
        for(int i = 0; i < pConjunto->tamanho - 1 - j; i++){ 
            if(pConjunto->array[i] > pConjunto->array[i+1]){ 
                int aux = pConjunto->array[i];
                pConjunto->array[i] = pConjunto->array[i+1];
                pConjunto->array[i+1] = aux;
            }
        }
    }
}

int buscaBinaria(Conjunto const *const pConjunto, int elemento){
    int inicio = 0;
    int fim = pConjunto -> tamanho - 1;
    int meio;
    while (inicio <= fim){
        meio = (inicio + fim) / 2;
        if(pConjunto -> array[meio] == elemento){
           return meio; 
        }else{
            if(pConjunto -> array[meio] < elemento){
                inicio = meio + 1;
            }else{
                if(pConjunto -> array[meio] > elemento){
                    fim = meio - 1;
                }else{
                    return -1;
                }
            }
        }
    }
    return -1;
}