// ********** NODE.CPP ********** //
// Source file for implementation of node and coord classes

// Developed by Martin Riis
// EE273 - Engineering for Software Design
// University of Strathclyde

// Last Edited: 10:50 22/04/2018

#include "Node.h"

node::node() {
	occupied = false; // Node has not been visited
	via = false; // Node has no via
}

void node::printLocation() { // Prints location of node
	cout << x << ", " << y << ", " << z << endl;
}

bool node::isOccupied(node master[PCBLength][PCBWidth][PCBLayers]) { // Returns boolean: node visited = true, not visited = false
	int x = this->x;
	int y = this->y;
	int z = this->z;

	return master[x][y][z].occupied; // Returns occupied state of master node array element
}

void node::isOccupied(bool state, node master[PCBLength][PCBWidth][PCBLayers]) { // Sets if the node is occupied by a trace
	occupied = state; // True = occupied, false = not occupied

	int x = this->x;
	int y = this->y;
	int z = this->z;

	master[x][y][z].occupied = state; // Sets occupied state in master node array
}

void node::addNeighbours(vector<node> n) { // Adds neighbours of type node vector
	neighbours = n;
}

vector<node> node::getNeighbours() { // Returns neighbours of node
	return neighbours;
}

bool node::operator==(node n) { // Node comparison operator
	if (this->x == n.x && this->y == n.y && this->z == n.z) {
		return true;
	}
	else {
		return false;
	}
}

coord::coord() { // Default constructor, zeros location
	x = 0;
	y = 0;
	z = 0;
}

void coord::set(char axis, int value) { // Sets x, y or z axis coordinates
	switch (axis) {
	case 'x': x = value; break; // x-axis define
	case 'X': x = value; break;
	case 'y': y = value; break; // y-axis define
	case 'Y': y = value; break;
	case 'z': z = value; break; // z-axis define
	case 'Z': z = value; break;
	default: cout << "Error : axis not identified" << endl; break; // Unknown axis
	}
}

void coord::set(int xVal, int yVal, int zVal) { // Sets all axis coordinates
	x = xVal; // Sets x coordinate
	y = yVal; // Sets y coordinate
	z = zVal; // Sets z coordinate
}

void coord::set(coord coordinate) { // Equates two coordinates
	x = coordinate.x;
	y = coordinate.y;
	z = coordinate.z;
}

int coord::get(char axis) { // Returns specified axis coordinate
	switch (axis) {
	case 'x': return x; break; // x-axis return
	case 'X': return x; break;
	case 'y': return y; break; // y-axis return
	case 'Y': return y; break;
	case 'z': return z; break; // z-axis return
	case 'Z': return z; break;
	default: cout << "Error : axis not identified" << endl; break; // Unknown axis
	}
}

coord coord::get() {
	coord temp; // Temporary coordinate
	temp.set(x, y, z); // Sets coordinate of temp
	return temp;
}

float calcDistance(coord a, coord b) { // Function for calculating the distance between two points
	float dist = sqrt(pow((a.get('x') - b.get('x')), 2) + pow((a.get('y') - b.get('y')), 2) + pow((a.get('z') - b.get('z')), 2));
	return dist;
}

coord cimg2coord(int x, int y, int z) {
	coord result; // Output
	int tempY; // Temporary y axis value
	result.set('x', x); // x value does not change
	result.set('y', PCBWidth - y);
	result.set('z', z);
	return result;
}

void coord2cimg(coord coordinate, int *x, int *y) {
	int inX = coordinate.get('x'); // Input x
	int inY = coordinate.get('y'); // Inout y

	(*x) = inX;
	(*y) = PCBWidth - inY;
}
