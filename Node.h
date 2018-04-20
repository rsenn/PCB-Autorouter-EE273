#ifndef Node_h
#define Node_h

#include <iostream>
#include <vector>
using namespace std;

#define PCBLength 500
#define PCBWidth 500
#define PCBLayers 1

class coord {
protected:
	int x; // x coordinate
	int y; // y coordinate
	int z; // z coordinate

public:
	coord();
	void set(char, int); // Sets coordinate
	void set(int, int, int); // Sets all axis coordinates - x, y, z
	int get(char); // Returns coordinate
	coord get(); // Returns coordinate
};

class node : public coord {
private:
	bool via; // Is the node occupied by a via
	bool occupied; // Is the node occupied by trace
	vector <node> neighbours; // Neighbours of node

public:
	node();
	void printLocation(); // Prints location of node

	bool isOccupied(); // Checks if node is occupied by a trace or not
	void isOccupied(bool); // Sets if the node is occuped by a trace or not
	bool hasVia(); // Checks if the node is occupied by a via
	void hasVia(bool); // Sets if the node has a via

	void addNeighbours(vector <node>); // Adds neighbours of type node vector
	vector <node> getNeighbours(); // Returns neighbours of node
};

float calcDistance(coord, coord);

#endif