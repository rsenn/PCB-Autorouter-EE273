// ********** PATH.CPP ********** //
// Source file for implementation of shortest path finding function

// Developed by Martin Riis
// EE273 - Engineering for Software Design
// University of Strathclyde

// Last Edited: 11:23 24/04/2018

#include "Path.h"
#include "Node.h"
#include "Neighbour.h"
#include <limits>
using namespace cimg_library;

unsigned int green[3] = { 0, 255, 0 }; // RGB colour of green

vector<node> findPath(node start, node end, node nodes[PCBLength][PCBWidth][PCBLayers], CImg<unsigned char> *PCB) {
	node current = start; // Current node equals start node
	vector <node> path; // Shortest path data
	bool cont = true; // Continue seraching
	int iteration = 0;

	while (cont == true) { // Loop until end is reached
		float shortestDistance; // Shortest path distance
		vector <float> neighbourDistance; // Vector of floats to hold distances between neighbours and current node
		vector <float> endDistance; // Vector of floats to hold distances between neighbours and end node
		vector <float> distances; // Vector of floats to hold the distances between current node and end node (neighbourDistance + endDistance)
		vector <node> currentNeighbours; // All current neighbours

		// *** FINDS AND ADDS NEIGHBOURS TO CURRENTNEIGHBOURS VECTOR *** //
		current.addNeighbours(findNeighbours(current.get('x'), current.get('y'), current.get('z'))); // Finds and adds neighbours of current node
		currentNeighbours = current.getNeighbours(); // Sets currentNeighbours to the newly found neighbours of current
		path.push_back(current); // Adds current node to path
		current.isOccupied(true, nodes); // Node is now occupied by trace

		// *** FINDS DISTANCES FROM CURRENT TO NEIGHBOURS *** //
		for (int i = 0; i < currentNeighbours.size(); i++) {
			neighbourDistance.push_back(calcDistance(currentNeighbours[i], current)); // Finds distance between current and each neighbour
			endDistance.push_back(calcDistance(currentNeighbours[i], end)); // Finds distance between each neighbour and end node
			distances.push_back(neighbourDistance[i] + endDistance[i]);
		}

		// *** FINDS SHORTEST DISTANCE *** //
		shortestDistance = std::numeric_limits<int>::max(); // Shortest distance from current node to end via neighbour 0
		for (int j = 0; j < distances.size(); j++) { // Loop count = number of neighbours
			// *** AT END NODE *** //
			if (endDistance[j] == 0) { // One of the neighbours is the end node
				cont = false; // Do not continue searching
				current = currentNeighbours[j]; // Updates current node
				path.push_back(current); // Adds current (end) node to path
				current.isOccupied(true, nodes); // Node is now occupied by trace
				break; // Break out of searching loop
			}

			// *** SHORTER PATH FOUND *** //
			else if ((distances[j] <= shortestDistance) && currentNeighbours[j].isOccupied(nodes) == false) { // Current distance is less than current shortest distance
				shortestDistance = distances[j]; // Updates shortestDistance
				current = currentNeighbours[j]; // Updates current node
			}

			else if (j == distances.size() - 1 && shortestDistance == std::numeric_limits<int>::max()) { // Not found path on last try
				if (path.size() == 0) { // No path found, path is currently empty
					return path; // Could not find a possible path
				}
				else { // Path not found, path is partially full
					current = path[iteration - 1]; // Go back on step on the path
					continue;
				}
			}

			else {
				continue; // End node not reached, continue searching
			}
		}
		nodes[current.get('x')][current.get('y')][current.get('z')].isOccupied(true, nodes); // Updates master node array data
	}


	for (int i = 0; i < path.size() - 1; i++) { // Loops through all locations in the path
		if (path[i].get('z') != path[i + 1].get('z')) { //If z coordinates are different
			nodes[path[i].get('x')][path[i].get('y')][path[i].get('z')].via = true; // Adds via
			int viaX, viaY; // Via x and y coordinates
			coord2cimg(path[i], &viaX, &viaY);
			(*PCB).draw_circle(viaX, viaY, viaRadius, green);
			cout << "Placed via" << endl;
		}
		iteration++;
	}
	return path;
}

float findLength(vector<node> path) {
	float totalDistance = 0;
	for (int i = 0; i < path.size() - 1; i++) {
		path[i].printLocation();
		totalDistance += calcDistance(path[i], path[i + 1]); // Updates total distance
	}
	return totalDistance;
}