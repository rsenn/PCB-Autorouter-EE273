#include "node.h"
int n = 0;

node::node() {
	//memset(location, 0, 3); // Sets all values in location array to 0
	visited = false; // Node has not been visited
}

void node::printLocation() { // Prints location of node
	cout << x << ", " << y << ", " << z << endl;
}

/*void node::setLocation(coord coordinate) { // Sets location of node
	location = coordinate;
}

coord node::getLocation() { // Returns the location of node
	return location;
}*/

bool node::isVisited() { // Returns boolean: node visited = true, not visited = false
	return visited;
}

void node::setVisited(bool state) { // Sets the visited state of the node: true = node visited, false = not visited 
	visited = state;
}

void node::setDistance(float dist) { // Sets the distance of the node on the current route
	distance = dist;
}

float node::getDistance() { // Returns the distance of the node on the current route
	return distance;
}

void node::addNeighbours(vector<node> n) { // Adds neighbours of type node vector
	neighbours = n;
}

vector<node> node::getNeighbours() { // Returns neighbours of node
	return neighbours;
}

/*void node::addNeighbour(coord n) {
	neighbours.push_back(n); // Adds neighbour n to neighbours vector
}

void node::addNeighbour(node n) {
	coord temp; // Creates a temporary coordinate to hold neighbour
	temp.set(n.get('x'), n.get('y'), n.get('z')); // Adds node n parameters to temp coord
	neighbours.push_back(temp); // Adds neighbour temp to neighbours vector
}*/


coord::coord() { // Default constructor for coord class
	x = 0; // Sets all coordinates to 0
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

void coord::set(coord a) { // Equates two coordinates
	x = a.x; // Equates x value
	y = a.y; // Equates y value
	z = a.z; // Equates z value
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

bool coord::operator==(coord a) { // Tests if two coordinates are equal
	return((this->get('x') == a.get('x')) && (this->get('y') == a.get('y')) && (this->get('z') == a.get('z'))); // Returns true or false
	/*cout << this->get('x') << endl;
	cout << a.get('x') << endl;
	if (this->get('x') == a.get('x') && this->get('y') == a.get('y') && this->get('z') == a.get('z')) {
		return true;
	}
	else {
		return false;
	}*/
}

float calcDistance(coord a, coord b) { // Function for calculating the distance between two points
	float dist = sqrt(pow((a.get('x') - b.get('x')), 2) + pow((a.get('y') - b.get('y')), 2) + pow((a.get('z') - b.get('z')), 2));
	return dist;
}

/*float calcDistance(node a, node b) {
	float dist = sqrt(pow((a.get('x') - b.get('x')), 2) + pow((a.get('y') - b.get('y')), 2) + pow((a.get('z') - b.get('z')), 2));
	return dist;
}*/