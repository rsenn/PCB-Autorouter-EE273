#include "CImg.h"
#include <iostream>
using namespace cimg_library;

#define length 640
#define width 480

int main() {
	CImg<unsigned char> PCB(length, width, 1, 3, 0); // Creates window

	CImgDisplay display(PCB, "PCB Autorouter"); // Names window

	unsigned int colour[3] = { 158, 23, 67 }; // RGB colour

	while (!display.is_closed()) { // While the window isn't closed
		display.wait(); // Wait for mouse click
		if (display.button() && display.mouse_y() >= 0 && display.mouse_x() >= 0) {
			const int y = display.mouse_y();
			const int x = display.mouse_x();
			PCB.draw_rectangle(x, y, 500, 500, colour); // Draw rectange
		}
		PCB.display(display); // Display the rectangle
	}
	return 0;
}