/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

#define stype int

void printMSG(ERR msg) {

    switch (msg) {
        case ERROR_CANT_CREATE_SET:
            fprintf(stderr, "Произола ошибка при создании листа\n");
            break;
        case ERROR_NULL_POINTER:
            fprintf(stderr, "В функцию был передан нулевой указатель\n");
            break;
        case ERROR_OVERFLOW:
            fprintf(stderr, "Переполнение набора\n");
            break;
    }

}
typedef struct set_ set;

struct set_ {
    stype * s;
    int size;
};

set* create() {
    set* s = calloc(1, sizeof (set));
    if (s == NULL) {
        printMSG(ERROR_CANT_CREATE_SET);
        return s;
    }
    s->s = calloc(N, sizeof (stype));
    if (s == NULL || s->s == NULL) {
        printMSG(ERROR_CANT_CREATE_SET);
        return s;
    }
    s->size = 0;
    return s;
}

void addElem(set* s, stype x) {
    if (s == NULL) {
        printMSG(ERROR_NULL_POINTER);
        return;
    }

    if (s->size >= N) {
        printMSG(ERROR_OVERFLOW);
        return;
    }
    if (checkElem(s, x) == 0) {
        s->s[s->size] = x;
        s->size ++;
    }

}

int checkElem(set* s, stype x) {
    if (s == NULL) {
        printMSG(ERROR_NULL_POINTER);
        return -1;
    }
    int i;
    for (i = 0; i < s->size; i++) {
        if (s->s[i] == x)
            return i+1;
    }
    return 0;
}

void deleteSet(set* s) {
    if (s == NULL) {
        printMSG(ERROR_NULL_POINTER);
        return;
    }
    free (s->s);
    free (s);

}

void deleteElem(set* s, stype x) {
    if (s == NULL) {
        printMSG(ERROR_NULL_POINTER);
        return;
    }
    if (checkElem(s, x) == 0)
        return;

    int i;

    for (i = checkElem(s, x) - 1; i < s->size - 1; i++) 
    {
        s->s[i] = s->s[i + 1];
        
    }
    s->size --;
}


int size(set* s)
{
    if (s == NULL) {
        printMSG(ERROR_NULL_POINTER);
        return -1;
    }
    return (s-> size);
}
void printSet(set* s)
{
    if (s == NULL) {
        printMSG(ERROR_NULL_POINTER);
        return ;
    }
    int i;
    for (i = 0; i < s->size; i++) {
        printf("%d ", s->s[i]);
    }
    printf("\n");
    return ; 
}
