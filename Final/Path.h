// ********** PATH.H ********** //
// Header file for shortest path finding functions

// Developed by Martin Riis
// EE273 - Engineering for Software Design
// University of Strathclyde

// Last Edited: 11:59 23/04/2018

#ifndef Path_h
#define Path_h

#include "definitions.h"
#include "Node.h"
#include "CImg.h"

using namespace cimg_library;

void findThePath(node, node, node[PCBLength][PCBWidth][PCBLayers]);

void findThePath(coord, coord, node[PCBLength][PCBWidth][PCBLayers]);

void find(coord, coord, node[PCBLength][PCBWidth][PCBLayers], vector<node>*);

vector<node> findPath(node, node, node[PCBLength][PCBWidth][PCBLayers], CImg<unsigned char>*);

float findLength(vector<node>);

void fill(coord, coord);
#endif