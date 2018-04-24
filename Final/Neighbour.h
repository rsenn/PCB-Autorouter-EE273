// ********** NEIGHBOUR.H ********** //
// Header file for neighbour finding function and verification function

// Developed by Martin Riis
// EE273 - Engineering for Software Design
// University of Strathclyde

// Last Edited: 11:59 23/04/2018

#ifndef Neighbour_h
#define Neighbour_h

#include "definitions.h"
#include <vector>
#include "Node.h"

vector<node>findNeighbours(int, int, int); // Find neighbours of coordinate
// Arguments = x, y, z coordinates of point

bool testPlace(node, int, node[PCBLength][PCBWidth][PCBLayers], vector<node>); // Test if a node can be placed on specified location

#endif