//#include "Dijkystra.h"
#include "node.h"
#include "neighbour.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

// ***** PCB SPECS ***** // 
//const int width = 10; // Sets PCB width (units)
//const int length = 10; // Sets PCB length (units)
//const int layers = 2; // Sets PCB layer count

// ***** STARTING LOCATION ***** //
const int startx = 0;
const int starty = 0;
const int startz = 0;

// ***** ENDING LOCATION ***** //
const int endx = 2;
const int endy = 2;
const int endz = 0;

const int bigNumber = width *width * length * length; // Large number for distance comparison

node nodes[length][width][layers]; // Creates a 3D array of nodes
node startNode; // Starting node
node endNode; // Ending node
coord current; // Initialise variable for current coordinate (using in for loops)
vector <coord> neighbour;
vector <node> unvisited; // Vector of unvisted nodes
vector <node> visited; // Vector of visited nodes
int t = 0;

float distance(int pointA [3], int pointB [3]) {
	float x = abs(pointB[0] - pointA[0]); // x axix distance between points A and B
	float y = abs(pointB[1] - pointA[1]); // y axix distance between points A and B
	float z = abs(pointB[2] - pointA[2]); // z axix distance between points A and B

	float dist = sqrt(pow(x, 2) + pow(y, 2)) + z; // 3D distance between point A and B
	return dist;
}

int main() {
	// ***** SET LOCATION OF STARTING COORDINATE ***** // 
	coord startCoord; // Define start location
	startCoord.set(startx, starty, startz); // Sets starting coordinate
	startNode.set(startCoord); // Sets start location

	// ***** SET LOCATION OF ENDING COORDINATE ***** //
	coord endCoord; // Defines end location
	endCoord.set(endx, endy, endz);
	endNode.set(endCoord); // Sets end location

	// ***** INITIALISES EVERY NODE ON  THE BOARD ***** //
	for (int l = 0; l < length; l++) {
		for (int w = 0; w < width; w++) {
			for (int h = 0; h < layers; h++) {
				current.set(l, w, h); // Sets current node location
				nodes[l][w][h].set(current); // Sets location of current node
				if (nodes[l][w][h].get() == startNode.get()) { // If current location is the starting location
					nodes[l][w][h].setVisited(false); // Node has been visited ?????????????????????????????
					startNode.setDistance(0.0); // Sets distance at start node
				}
				else {
					nodes[l][w][h].setDistance(bigNumber); // Sets distance to current node to a large number
					//cout << nodes[l][w][h].isVisited() << endl;
				}
				if (nodes[l][w][h].isVisited()) { // Has node been visited
					visited.push_back(nodes[l][w][h]); // Node has been visited, add to visited vector
				}
				else {
					//cout << l << ", " << w << ", " << h << endl;
					unvisited.push_back(nodes[l][w][h]); // Node has not been visited, add to unvisited vector
					//cout << unvisited[t].get('x') << ", " << unvisited[t].get('y') << ", " << unvisited[t].get('z') << endl;
				}
				t++;
			}
		}
	}

	node current; // Current node
	vector <node> currentNeighbours; // Vector of current neighbours
	current = startNode; // Sets current node to start node

	// Add iterator for goto statement?
	current.addNeighbours(findNeighbours(current.get('x'), current.get('y'), current.get('z'))); // Finds and adds neighbours of current node
	currentNeighbours = current.getNeighbours(); // Sets currentNeighbours to the newly found neighbours of current
	float totalDistance = 0; // Total distance of trace
	vector <float> distances;

	for (int i = 0; i < currentNeighbours.size(); i++) {
		float temp = calcDistance(currentNeighbours[i], current); // Calculates distance between current node and neighbour
		//cout << temp << endl;
		distances.push_back(temp); // Adds temp to distances vector
	}

	for (int j = 0; j < distances.size() - 1; j++) { // Iterates through all values is distances
		cout << distances[j] << endl;
		if (distances[j] < distances[j + 1]) { // If current distance is less than next distance
			cout << "Shortest" << endl;
		}
		else {
			continue;
		}
	}

	/*coord base; // Base node around which neighbours will be found
	float posRoute; // Possible alternative route
	for (int n = 0; n < unvisited.size(); n++) { // For every unvisited node
		int x = unvisited[n].get().get('x'); // Current x coordinate
		int y = unvisited[n].get().get('y'); // Current y coordinate
		int z = unvisited[n].get().get('z'); // Current z coordinate
		base.set(x, y, z);
		vector<node> neighbours = findNeighbours(x, y, z); // Finds all neighbours of current unvisited coordinate


		for (int m = 0; m < neighbours.size(); m++) { // Iterates through all neighbours of current node
			cout << "New loop" << endl;
			//cout << neighbours[m].get('x') << ", " << neighbours[m].get('y') << ", " << neighbours[m].get('z') << endl;
			posRoute = calcDistance(base, neighbours[m]) + unvisited[n].getDistance(); // Distance between current node and neighbour
			//cout << posRoute << endl;
			for (int p = 0; p < unvisited.size(); p++) { // Iterates through every node in unvisited vector
				/*cout << "Unvisited " << p << " = ";
				unvisited[p].printLocation();
				cout << "Neighbours " << m << " = ";
				neighbours[m].printLocation();
				cout << endl;
				if (unvisited[p].get() == neighbours[m].get()) { // If current node equals current neighbour
					//cout << "Equal" << endl; // Found neighbour in unvisited vector
					//unvisited[p].setDistance(calcDistance())
					//cout << unvisited[p].getDistance() << endl;
					break; // Match found, reloop
				}
				else {
					continue; // Else continue searching
				}
			}
			//if (posRoute < )

		}
		//visited.push_back(unvisited[n]); // Adds now visited coordinate to visited vector

	}*/

	system("PAUSE");
	return 0;
}