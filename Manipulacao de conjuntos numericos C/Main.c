#include "funcoes.h"

int main() {
    int tamanho, opcao = 0, j = 0,o = 0, elemento; 
    Conjunto teste;
    printf("------------------Menu------------------\n");
    printf("\n1 - Gerar um conjunto\n2 - Visualizar o conjunto criado\n3 - Buscar elemento no conjunto\n4 - Ordenar Conjunto\n5 - Busca Binaria\n6 - Sair\n");

    while (opcao != 6) {
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\nGerar Conjunto\n");
            tamanho = obterTamanhoConjunto();
            printf("\nTamanho do Conjunto = %d\n", tamanho);
            gerarConjunto(&teste, tamanho);
            j = 1;
        } else {
            if (opcao == 2) {
                printf("\nMostrar Conjunto\n");
                if (j != 1) {
                    printf("\nConjunto ainda nao foi criado!\n");
                } else {
                    mostrarConjunto(&teste);
                }
            } else {
                if (opcao == 3) {
                    int pos;
                    if (j != 1) {
                        printf("\nConjunto ainda nao foi criado!\n");
                    } else {
                        printf("Digite o elemento a ser buscado:\n");
                        scanf("%d", &elemento);
                        pos = buscaSequencial(&teste, elemento);
                        if (pos >= 0) {
                            printf("\nElemento %d encontrado na posicao %d\n", elemento, pos);
                        } else {
                            printf("\nElemento %d nao encontrado\n", elemento);
                        }
                    }
                } else {
                    if (opcao == 4) {
                        if (j != 1) {
                            printf("\nConjunto ainda nao foi criado!\n");
                        } else {
                            ordenarConjunto(&teste);
                            o = 1;
                            printf("\nConjunto Ordenado!\n");
                        }
                    } else {
                        if (opcao == 5) {
                            int pos;
                            if (j != 1) {
                                printf("\nConjunto ainda nao foi criado!\n");
                            } else {
                                if(o != 1){
                                    printf("\nConjunto ainda nao foi ordenado!\n");

                                }else{
                                    printf("Digite o elemento a ser buscado:\n");
                                    scanf("%d", &elemento);
                                    pos = buscaBinaria(&teste, elemento);
                                    if (pos >= 0) {
                                    printf("\nElemento %d encontrado na posicao %d\n", elemento, pos);
                                    } else {
                                    printf("\nElemento %d nao encontrado\n", elemento);
                                    }
                                }
                            }
                        } else {
                            if (opcao == 6) {
                                printf("\nSair\n");
                                free(teste.array);
                                return 0;
                            } else {
                                printf("\nOpcao Invalida!\n");
                            }
                        }
                    }
                }
            }
        }

        printf("\n1 - Gerar um conjunto\n2 - Visualizar o conjunto criado\n3 - Buscar elemento no conjunto\n4 - Ordenar Conjunto\n5 - Busca Binaria\n6 - Sair\n");
    }
} // Fim do Programa
