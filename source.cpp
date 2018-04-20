#include "Node.h"
#include "Neighbour.h"
#include "Path.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <thread>
#include "CImg.h"
using namespace cimg_library;

// ***** PCB SPECS ***** // 
//#define width 10; // Sets PCB width (units)
//#define length 10; // Sets PCB length (units)
//#define layers 2; // Sets PCB layer count

// ***** STARTING LOCATION ***** //
#define startx 21
#define starty 20
#define startz 0

// ***** ENDING LOCATION ***** //
#define endx 392
#define endy 102
#define endz 0

unsigned int threads = 1;

#define bigNumber width * length // Large number for distance comparison

node nodes[PCBLength][PCBWidth][PCBLayers]; // Creates a 3D array of nodes
node startNode; // Starting node
node endNode; // Ending node


int main() {
	CImg<unsigned char> PCB(PCBLength, PCBWidth, 1, 3, 0); // Creates window

	CImgDisplay display(PCB, "PCB Autorouter"); // Names window

	unsigned int colour[3] = { 158, 23, 67 }; // RGB colour

	for (int n = 0; n < threads; n++) {
		vector<node> path;
		float pathLength;

		// ***** SET LOCATION OF STARTING COORDINATE ***** // 
		startNode.set(startx, starty, startz); // Sets starting coordinate

		// ***** SET LOCATION OF ENDING COORDINATE ***** //
		endNode.set(endx, endy, endz); // Sets starting coordinate

		// ***** FINDS NEIGHBOURS AND DISTANCES ***** //
		path = findPath(startNode, endNode, nodes); // Calculates path with minimum distance
		pathLength = findLength(path); // Finds length of path
		std::cout << pathLength << std::endl;

		while (!display.is_closed()) {
			for (int i = 0; i < path.size() - 1; i++) {
				PCB.draw_line(path[i].get('x'), path[i].get('y'), path[i + 1].get('x'), path[i + 1].get('y'), colour);
			}
			PCB.display(display);
		}
	}

	system("PAUSE");
	return 0;
}