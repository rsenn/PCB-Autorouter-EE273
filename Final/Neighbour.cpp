// ********** NEIGHBOUR.CPP ********** //
// Source file for implementation of neighbour finding function

// Developed by Martin Riis
// EE273 - Engineering for Software Design
// University of Strathclyde

// Last Edited: 11:27 21/04/2018

#include "Neighbour.h"

// ***** FUNCTION FOR FINDING ALL NEIGHBOURS OF A COORDINATE ***** //

vector<node>findNeighbours(int x, int y, int z) {
	int maxX = PCBLength - 1; // Maximum x dimension
	int maxY = PCBWidth - 1; // Maximum x dimension
	int maxZ = PCBLayers - 1; // Maximum x dimension
	vector<node> neighbour; // Vector of coordinates for storing neighbour data
	node validNeighbour; // Temporary storage for valid neighbour coordinate

	for (int dx = -1; dx <= 1; ++dx) { // Loops through possible delta x values
		for (int dy = -1; dy <= 1; ++dy) { // Loops through possible delta y values
			for (int dz = -1; dz <= 1; ++dz) { // Loops through possible delta z values
				if (dx == 0 && dy == 0 && dz == 0) { // Same location as input therefor not valid neighbour
					continue;
				}
				int newX = x + dx; // X coordinate of possible neighbour
				int newY = y + dy; // Y coordinate of possible neighbour
				int newZ = z + dz; // Z coordinate of possible neighbour

				if (newX > maxX || newX < 0) { // New x coordinate out of range
					continue; // Skip coordinate
				}
				else if (newY > maxY || newY < 0) { // New y coordinate out of range
					continue; // Skip coordinate
				}
				else if (newZ > maxZ || newZ < 0) { // New z coordinate out of range
					continue; // Skip coordinate
				}
				validNeighbour.set(newX, newY, newZ); // Stores neighbour coordinates
				neighbour.push_back(validNeighbour); // Adds neighbour coordinates to vector or neighbours
			}
		}
	}
	return neighbour;
}

// Can a trace node be placed on location "coordinate"?
// Range is the keepout region around each trace/object on the PCB
bool testPlace(node coordinate, int range, node nodes[PCBLength][PCBWidth][PCBLayers], vector<node> path) {
	int x = coordinate.get('x');
	int y = coordinate.get('y');
	int z = coordinate.get('z');

	int maxX = PCBLength - 1; // Maximum x dimension
	int maxY = PCBWidth - 1; // Maximum x dimension
	int maxZ = PCBLayers - 1; // Maximum x dimension
	vector<node> neighbour; // Vector of coordinates for storing neighbour data
	node validNeighbour; // Temporary storage for valid neighbour coordinate

	for (int dx = -range; dx <= range; ++dx) { // Loops through possible delta x values
		for (int dy = -range; dy <= range; ++dy) { // Loops through possible delta y values
			for (int dz = -range; dz <= range; ++dz) { // Loops through possible delta z values
				if (dx == 0 && dy == 0 && dz == 0) { // Same location as input therefor not valid neighbour
					continue;
				}
				int newX = x + dx; // X coordinate of possible neighbour
				int newY = y + dy; // Y coordinate of possible neighbour
				int newZ = z + dz; // Z coordinate of possible neighbour

				if (nodes[newX][newY][newZ].isOccupied(nodes)) { // If current node is occupied by object
					for (int n = 0; n < path.size(); n++) { // Iterates through every node in the CURRENT path
						//cout << n << endl;
						if (nodes[newX][newY][newZ].get('x') == path[n].get('x') && nodes[newX][newY][newZ].get('y') == path[n].get('y') && nodes[newX][newY][newZ].get('z') == path[n].get('z')) { // If the neighbour node is in the path
							std::cout << "Nodes equal" << std::endl;
							break; // Ignore the occupied status
						}
						else {
							continue;
						}
					}
					//cout << "Returning False" << endl;
					return false; // Node in range "range" is occupied, node cannot be placed on coordinate
				}
				continue; // Node not occupied, continue scanning
			}
		}
	}
	return true; // No nodes in range "range" are occupied, node can be placed on coordinate
}