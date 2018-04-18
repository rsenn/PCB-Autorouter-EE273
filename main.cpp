#include "CImg.hpp"
#include <iostream>
using namespace cimg_library;

#define length 640
#define width 480

int main() {
	CImg<unsigned char> PCB(length, width, 1, 3, 0); // Creates window

	CImgDisplay display(PCB, "PCB Autorouter"); // Names window

	unsigned int colour1[3] = { 255, 255, 255 }; // RGB colour of White
	unsigned int colour2[3] = { 0, 0, 0 }; // RGB colour of Black

	while (!display.is_closed()) { // While the window is open
		PCB.draw_rectangle(80, 80, 40, 40, colour1); // Draw White square
		PCB.draw_rectangle(140, 80, 100, 40, colour1); // Draw White square
		PCB.draw_text(55, 55, "%s", colour2, colour1, 0.5f, 15, "1"); // Draw number 1 on the first square
		PCB.draw_text(115, 55, "%s", colour2, colour1, 0.5f, 15, "2"); // Draw number 2 on the second square
		PCB.display(display); // Display numbered pads

		/*/display.wait(); // Wait for mouse click
		if (display.button() && display.mouse_y() >= 0 && display.mouse_x() >= 0) {
			const int y = display.mouse_y();
			const int x = display.mouse_x();
			PCB.draw_rectangle(x, y, 500, 500, colour1); // Draw rectangle
		}
		PCB.display(display); // Display the rectangle/*/

	}
	return 0;
}