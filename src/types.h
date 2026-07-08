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
	const uint16_t nVertex, nEdges;
	const point3D *vertices;
	const edge *edges;
} model;

typedef struct {
    const model *shipModel;
    point3D rotation;
    point3D position;
} ship;

typedef struct {
    point3D position;
    point3D rotation;
} camera;


#endif