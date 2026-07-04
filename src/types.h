#ifndef TYPES_H
#define TYPES_H

#include "../libs/eadk.h"

typedef struct {
	int x, y, z;
} point3D;

typedef struct {
	int indexA, indexB;
} edge;

typedef struct {
	uint16_t nVertex, nEdges;
	point3D *vertices;
	edge *edges;
} model;

#endif