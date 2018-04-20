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
								   //cout << "Possible : " << newX << ", " << newY << ", " << newZ << endl; // Prints possible neighbour

				if (newX > maxX || newX < 0) { // New x coordinate out of range
					continue; // Skip coordinate
				}
				else if (newY > maxY || newY < 0) { // New y coordinate out of range
					continue; // Skip coordinate
				}
				else if (newZ > maxZ || newZ < 0) { // New z coordinate out of range
					continue; // Skip coordinate
				}
				//cout << "Neighbours of " << x << ", " << y << ", " << z << endl; 
				//cout << newX << ", " << newY << ", " << newZ << endl; // Prints verified neighbour coordinates
				validNeighbour.set(newX, newY, newZ); // Stores neighbour coordinates
				neighbour.push_back(validNeighbour); // Adds neighbour coordinates to vector or neighbours
			}
		}
	}
	return neighbour;
}