/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* ******************************************************************************** */

struct point {
    int x;
    int y;
};

/* ******************************************************************************** */

struct point makePoint(int x, int y);
int isSamePoint(struct point*, struct point*);
struct point *middlePoint(struct point*, struct point*);
void drawPoint(struct point*);
void lineSegment(struct point*, struct point*);

/* ******************************************************************************** */