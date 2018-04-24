// ********** NODE.H ********** //
// Header file for coord and node classes, used for storing parameters about nodes and coordinates on the board

// Developed by Martin Riis
// EE273 - Engineering for Software Design
// University of Strathclyde

// Last Edited: 11:59 23/04/2018

#ifndef Node_h
#define Node_h

#include "definitions.h"
#include <iostream>
#include <vector>
using namespace std;

class coord {
protected:
	int x; // x coordinate
	int y; // y coordinate
	int z; // z coordinate

public:
	coord();
	void set(char, int); // Sets coordinate
	void set(int, int, int); // Sets all axis coordinates - x, y, z
	void set(coord); // Equates two coords
	int get(char); // Returns coordinate
	coord get(); // Returns coordinate
};

class node : public coord {
private:
	bool occupied; // Is the node occupied by trace
	vector <node> neighbours; // Neighbours of node

public:
	node();
	void printLocation(); // Prints location of node

	bool isOccupied(node[PCBLength][PCBWidth][PCBLayers]); // Checks if node is occupied by a trace or not
	void isOccupied(bool, node[PCBLength][PCBWidth][PCBLayers]); // Sets if the node is occuped by a trace or not
	bool via; // Is the node occupied by a via

	void addNeighbours(vector <node>); // Adds neighbours of type node vector
	vector <node> getNeighbours(); // Returns neighbours of node

	bool operator==(node); // Node comparison operator
};

float calcDistance(coord, coord); // Calculates distance between two points

coord cimg2coord(int, int, int); // Coverts the CImg coordinate system to the autorouter coordinate system
void coord2cimg(coord, int*, int*); // Converts the autorouter coordinate system to the CImg coordinate system

#endif