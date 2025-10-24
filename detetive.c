#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================*
 *  ESTRUTURAS DE DADOS         *
 *==============================*/

// Estrutura para representar cada cômodo da mansão
typedef struct Sala {
    char nome[50];
    char pista[100];        // Pista opcional associada à sala
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Estrutura para representar um nó da árvore de pistas (BST)
typedef struct PistaNode {
    char pista[100];
    struct PistaNode *esquerda;
    struct PistaNode *direita;
} PistaNode;

/*==============================*
 *  FUNÇÕES RELACIONADAS ÀS SALAS
 *==============================*/

/*
 Função: criarSala
 Objetivo: cria dinamicamente uma nova sala, com nome e (opcionalmente) uma pista.
*/
Sala* criarSala(const char *nome, const char *pista) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória para sala!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    if (pista != NULL)
        strcpy(nova->pista, pista);
    else
        strcpy(nova->pista, "");
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

/*==============================*
 *  FUNÇÕES RELACIONADAS ÀS PISTAS
 *==============================*/

/*
 Função: inserirPista
 Objetivo: insere uma pista na árvore de busca (BST) em ordem alfabética.
*/
PistaNode* inserirPista(PistaNode *raiz, const char *pista) {
    if (strlen(pista) == 0) return raiz; // Ignora se a sala não tem pista

    if (raiz == NULL) {
        PistaNode *novo = (PistaNode*) malloc(sizeof(PistaNode));
        strcpy(novo->pista, pista);
        novo->esquerda = novo->direita = NULL;
        return novo;
    }

    if (strcmp(pista, raiz->pista) < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    else if (strcmp(pista, raiz->pista
