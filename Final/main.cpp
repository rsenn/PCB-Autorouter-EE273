// ********** MAIN.CPP ********** //
// Main source file for implementation of program

// Developed by Martin Riis and Nathan Bryson
// EE273 - Engineering for Software Design
// University of Strathclyde

// Last Edited: 14:15 24/04/2018

#include "Node.h"
#include "Neighbour.h"
#include "Path.h"
#include <iostream>
#include <string>
#include <vector>
#include "CImg.h"

using namespace cimg_library;

node nodes[PCBLength][PCBWidth][PCBLayers]; // Creates a 3D array of nodes
node startNode; // Starting node
node endNode; // Ending node

node startNode1; // Starting node
node endNode1; // Ending node

int main() {
	CImg<unsigned char> PCB(PCBLength, PCBWidth, 1, 3, 0); // Creates window

	CImgDisplay display(PCB, "PCB Autorouter"); // Names window

	unsigned int red[3] = { 255, 0, 0 }; // RGB colour of red
	unsigned int green[3] = { 0, 255, 0 }; // RGB colour of green
	unsigned int white[3] = { 255, 255, 255 }; // RGB colour of White
	unsigned int black[3] = { 0, 0, 0 }; // RGB colour of Black
	unsigned int grey[3] = { 170, 170, 1700 }; // RGB colour of Grey

	std::vector<std::vector<coord>> connections;
	int iteration = 0;
	bool iterate = false;
	std::vector<std::vector<node>> path;
	int pathSize = 0;

	int component; // Component ID
	// 0 = resistor
	// 1 = capacitor
	// 2 = transistor
	// 3 = LED
	// 4 = IC

	while (!display.is_closed()) { // While the window is open
		// ***** DRAWS BUTTONS ***** //
		PCB.draw_rectangle(25, 25, 120, 50, grey); // Draw White square
		PCB.draw_text(30, 30, "%s", black, grey, 0.5f, 20, "RESISTOR"); // Prints RESISTOR in box

		PCB.draw_rectangle(130, 25, 235, 50, grey); // Draw White square
		PCB.draw_text(135, 30, "%s", black, grey, 0.5f, 20, "CAPACITOR"); // Prints CAPACITOR in box

		PCB.draw_rectangle(245, 25, 360, 50, grey); // Draw White square
		PCB.draw_text(250, 30, "%s", black, grey, 0.5f, 20, "TRANSISTOR"); // Prints TRANSISTOR in box

		PCB.draw_rectangle(370, 25, 410, 50, grey); // Draw White square
		PCB.draw_text(375, 30, "%s", black, grey, 0.5f, 20, "LED"); // Prints LED in box

		PCB.draw_rectangle(420, 25, 445, 50, grey); // Draw White square
		PCB.draw_text(425, 30, "%s", black, grey, 0.5f, 20, "IC"); // Prints IC in box

		PCB.draw_rectangle(455, 25, 545, 50, grey); // Draw White square
		PCB.draw_text(460, 30, "%s", black, grey, 0.5f, 20, "CONNECT"); // Prints Connect in box

		PCB.draw_rectangle(560, 25, 680, 50, grey); // Draw White square
		PCB.draw_text(565, 30, "%s", black, grey, 0.5f, 20, "AUTOROUTE"); // Prints Autoroute in box

		// ***** TESTS FOR COMPONENT BUTTON PRESSES ***** //
		// If resistor button is pressed
		if (display.button() && display.mouse_x() >= 25 && display.mouse_x() <= 120 && display.mouse_y() >= 25 && display.mouse_y() <= 50) {
			component = 0;
			std::cout << "Resistor";
		}

		// If capacitor button is pressed
		else if (display.button() && display.mouse_x() >= 130 && display.mouse_x() <= 235 && display.mouse_y() >= 25 && display.mouse_y() <= 50) {
			component = 1;
			std::cout << "Capacitor";
		}

		// If transistor button is pressed
		else if (display.button() && display.mouse_x() >= 245 && display.mouse_x() <= 350 && display.mouse_y() >= 25 && display.mouse_y() <= 50) {
			component = 2;
			std::cout << "Transistor";
		}

		// If LED button is pressed
		else if (display.button() && display.mouse_x() >= 370 && display.mouse_x() <= 410 && display.mouse_y() >= 25 && display.mouse_y() <= 50) {
			component = 3;
			std::cout << "LED";
		}

		// If IC button is pressed
		else if (display.button() && display.mouse_x() >= 420 && display.mouse_x() <= 445 && display.mouse_y() >= 25 && display.mouse_y() <= 50) {
			component = 4;
			std::cout << "IC";
		}

		// Else do nothing
		else {
		}

		PCB.display(display); // Update the display

		// ***** PLACES COMPONENTS ***** //
		// If the button region is pressed, do nothing
		if (display.button() && display.mouse_y() <= 50) {
		}

		else if (display.button()) { // If button is pressed outwith the display region
			// Cpature current mouse coordinates
			int x = display.mouse_x();
			int y = display.mouse_y();
			coord rectA1, rectA2, rectB1, rectB2, rectC1, rectC2, rectD1, rectD2, rectE1, rectE2, rectF1, rectF2, rectG1, rectG2, rectH1, rectH2;
			switch (component) {
			case 0: // Draw Resistor
				PCB.draw_rectangle(x - 14, y - 32, x + 14, y - 4, red); // Draw coloured square
				rectA1 = cimg2coord(x - 14, y - 32, 1);
				rectA2 = cimg2coord(x + 14, y - 4, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x - 14, y + 4, x + 14, y + 32, red); // Draw coloured square
				rectB1 = cimg2coord(x - 14, y + 14, 1);
				rectB2 = cimg2coord(x + 14, y + 32, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				std::cout << "Placed resistor" << std::endl;
				break;

			case 1: // Draw Capacitor
				PCB.draw_rectangle(x - 14, y - 32, x + 14, y - 4, red); // Draw coloured square
				rectA1 = cimg2coord(x - 14, y - 32, 1);
				rectA2 = cimg2coord(x + 14, y - 4, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x - 14, y + 4, x + 14, y + 32, red); // Draw coloured square
				rectB1 = cimg2coord(x - 14, y + 14, 1);
				rectB2 = cimg2coord(x + 14, y + 32, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				std::cout << "Placed capacitor" << std::endl;
				break;

			case 2: // Draw Transistor
				PCB.draw_rectangle(x - 6, y - 24, x + 6, y - 4, red);
				rectA1 = cimg2coord(x - 6, y - 24, 1);
				rectA2 = cimg2coord(x + 6, y - 4, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x - 8, y + 4, x - 20, y + 24, red);
				rectB1 = cimg2coord(x - 8, y + 4, 1);
				rectB2 = cimg2coord(x - 20, y + 24, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x + 8, y + 4, x + 20, y + 24, red);
				rectC1 = cimg2coord(x + 8, y + 4, 1);
				rectC2 = cimg2coord(x + 20, y + 24, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				std::cout << "Placed transistor" << std::endl;
				break;

			case 3: // Draw LED
				PCB.draw_rectangle(x - 14, y - 32, x + 14, y - 4, red); // Draw coloured square
				rectA1 = cimg2coord(x - 14, y - 32, 1);
				rectA2 = cimg2coord(x + 14, y - 4, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x - 14, y + 4, x + 14, y + 32, red); // Draw coloured square
				rectB1 = cimg2coord(x - 14, y + 14, 1);
				rectB2 = cimg2coord(x + 14, y + 32, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				std::cout << "Placed LED" << std::endl;
				break;

			case 4: // Draw IC
				PCB.draw_rectangle(x - 2, y - 26, x - 10, y - 12, red);
				rectA1 = cimg2coord(x - 2, y - 26, 1);
				rectA2 = cimg2coord(x - 10, y - 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x - 14, y - 26, x - 22, y - 12, red);
				rectB1 = cimg2coord(x - 14, y - 26, 1);
				rectB2 = cimg2coord(x - 22, y - 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x + 2, y - 26, x + 10, y - 12, red);
				rectC1 = cimg2coord(x + 2, y - 26, 1);
				rectC2 = cimg2coord(x + 10, y - 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x + 14, y - 26, x + 22, y - 12, red);
				rectD1 = cimg2coord(x + 14, y - 26, 1);
				rectD2 = cimg2coord(x + 22, y - 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x - 2, y + 26, x - 10, y + 12, red);
				rectE1 = cimg2coord(x - 2, y + 26, 1);
				rectE2 = cimg2coord(x - 10, y + 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x - 14, y + 26, x - 22, y + 12, red);
				rectF1 = cimg2coord(x - 14, y + 26, 1);
				rectF2 = cimg2coord(x - 22, y + 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x + 2, y + 26, x + 10, y + 12, red);
				rectG1 = cimg2coord(x + 2, y + 26, 1);
				rectG2 = cimg2coord(x + 10, y + 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				PCB.draw_rectangle(x + 14, y + 26, x + 22, y + 12, red);
				rectH1 = cimg2coord(x + 14, y + 26, 1);
				rectH2 = cimg2coord(x + 22, y + 12, 1);
				for (int x = rectA1.get('x'); x < rectA1.get('x'); x++) {
					for (int y = rectA1.get('y'); y < rectA2.get('y'); y++) {
						nodes[x][y][1].isOccupied(true, nodes);
					}
				}
				std::cout << "Placed IC" << std::endl;
				break;

			default:
				continue;
			}
			PCB.display(display); // Updates display
		}

		// ***** TESTS FOR ACTION BUTTONS ***** //
		// User presses connect button
		if (display.button() && display.mouse_x() >= 455 && display.mouse_x() <= 545 && display.mouse_y() >= 25 && display.mouse_y() <= 50) {
			int tempX = display.mouse_x();
			int tempY = display.mouse_y();
			while (true) { // Loops until both start and end have been aquired 
				if (display.button() && display.mouse_x() != tempX && display.mouse_y() != tempY) { // Button pressed and mouse location changed
					int startX = display.mouse_x();
					int startY = display.mouse_y();
					coord tempStart; // Initialises start location
					tempStart.set(cimg2coord(startX, startY, 1)); // Sets start location
					display.wait(); // Wait for activity
					secondPress:
						if (display.button() && display.mouse_x() != startX && display.mouse_y() != startY) { // Button pressed and mouse location changed
							connections.resize(iteration + 1); // Expands connections vector for new values
							int endX = display.mouse_x();
							int endY = display.mouse_y();
							coord tempEnd; // Initialises end location
							tempEnd.set(cimg2coord(endX, endY, 1)); // Sets end location
							connections[iteration].push_back(tempStart); // Adds start location to connections vector
							connections[iteration].push_back(tempEnd); // Adds end location to connections vector
							std::cout << "Registered" << std::endl;
							iteration++; // Increament iteration
							component = 100; // Sets component above component count so the last component won't be placed after connecting
							break; // Break out of loop
						}
						else {
							goto secondPress; // Go to second press line and retest
						}
				}
				else {
					continue;
					// If button's not pressed, do nothing
				}
			}
		}

		// User presses autoroute button
		else if (display.button() && display.mouse_x() >= 560 && display.mouse_x() <= 680 && display.mouse_y() >= 25 && display.mouse_y() <= 50) {
			for (int i = 0; i < connections.size(); i++) {
				node currentStart, currentEnd;
				vector<node> currentPath;
				currentStart.set(connections[i][0]);
				currentEnd.set(connections[i][1]);
				currentPath = findPath(currentStart, currentEnd, nodes, &PCB);
				for (int j = 0; j < currentPath.size(); j++) {
					int xStart, yStart, xEnd, yEnd; // Starting and ending values in cimg coordinate system
					coord2cimg(currentPath[j], &xStart, &yStart);
					coord2cimg(currentPath[j], &xEnd, &yEnd);
					PCB.draw_line(xStart, yStart, xEnd, yEnd, red);
				}
			}

			PCB.display(display);
		}

		// User doesn't press button, do nothing
		else {
			display.wait();
		}
	}

	std::system("PAUSE");
	return 0;
}