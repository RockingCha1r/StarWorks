#ifndef MODELS_H
#define MODELS_H

#include "types.h"

const model cube = {
    .nVertex = 8, 
    .nEdges = 12,
	.vertices = (const point3D[]) {
        {50, 50, 50}, {-50, 50, 50}, 
        {50, -50, 50}, {50, 50, -50}, 
        {-50, -50, 50}, {50, -50, -50}, 
        {-50, 50, -50}, {-50, -50, -50}
    },

	.edges = (const edge[]) {
        {0,1}, {1,4},
        {4,2}, {2,0},

        {3,6}, {6,7},
        {7,5}, {5,3},

        {0,3}, {1,6}, 
        {2,5}, {4,7}   
    }
};



#endif