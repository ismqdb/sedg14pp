/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

struct parray {
    char *key;
    char *next;
    int current;
    int head;
    int tail; 
};

/* ******************************************************************************** */

struct parray parrayInit(int);
void parrayDeinit(struct parray*);

/* ******************************************************************************** */

void parrayDeleteNext(struct parray*, char);
char parrayInsertAfter(struct parray*, char, char);
void parrayPrintAll(struct parray*);

/* ******************************************************************************** */