#ifndef node_h
#define node_h

#include <iostream>
#include <vector>
using namespace std;

const int length = 4;
const int width = 3;
const int layers = 1;

/*struct coord { // Defines structure for 3D coordinate system
	int x; // x coordinate
	int y; // y coordinate
	int z; // z coordinate
};

bool operator==(coord, coord);*/

class coord {
protected:
	int x; // x coordinate
	int y; // y coordinate
	int z; // z coordinate

public:
	coord(); // Defualt constructor
	void set(char, int); // Sets coordinate
	void set(int, int, int); // Sets all axis coordinates - x, y, z
	void set(coord); // Sets coordinate in coord format (equates two coordinates)
	int get(char); // Returns coordinate
	coord get(); // Returns coordinate
	bool operator==(coord); // Operator for comparing two coordinates
	//bool equal(coord);
};

class node : public coord {
private:
	//coord location; // Location of node
	bool visited; // Has the node been visited
	float distance; // Distance from source
	vector <node> neighbours; // Neighbours of node

public:
	node();
	//virtual ~node();
	void printLocation(); // Prints location of node
	//void setLocation(coord); // Sets location of node
	//coord getLocation(); // Returns location of node
	bool isVisited(); // Checks if node has been visited
	void setVisited(bool); // Sets visited status of node
	void setDistance(float); // Sets node distance on current route
	float getDistance(); // Returns node distance on current route
	//float getDistance(coord); // Returns distance between two coordinates
	//void addNeighbour(coord); // Adds neighbour of type coord
	//void addNeighbour(node); // Adds neighbour of type node
	void addNeighbours(vector <node>); // Adds neighbours of type node vector
	vector <node> getNeighbours(); // Returns neighbours of node
};

float calcDistance(coord, coord);
//float calcDistance(node, node);

#endif // !node_h