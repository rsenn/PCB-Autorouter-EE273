#include "CImg.hpp"
#include <iostream>
using namespace cimg_library;

#define length 900
#define width 650

int main() {
	CImg<unsigned char> PCB(length, width, 1, 3, 0); // Creates window

	CImgDisplay display(PCB, "PCB Autorouter"); // Names window

	unsigned int White[3] = { 255, 255, 255 }; // RGB colour of White
	unsigned int Black[3] = { 0, 0, 0 }; // RGB colour of Black
	unsigned int Grey[3] = { 170, 170, 1700 }; // RGB colour of Grey

	int component;

	while (!display.is_closed()) // While the window is open
	{
		PCB.draw_rectangle(25, 25, 120, 50, Grey); // Draw White square
		PCB.draw_text(30, 30, "%s", Black, Grey, 0.5f, 20, "RESISTOR");

		PCB.draw_rectangle(130, 25, 235, 50, Grey); // Draw White square
		PCB.draw_text(135, 30, "%s", Black, Grey, 0.5f, 20, "CAPACITOR");

		PCB.draw_rectangle(245, 25, 360, 50, Grey); // Draw White square
		PCB.draw_text(250, 30, "%s", Black, Grey, 0.5f, 20, "TRANSISTOR");

		PCB.draw_rectangle(370, 25, 410, 50, Grey); // Draw White square
		PCB.draw_text(375, 30, "%s", Black, Grey, 0.5f, 20, "LED");

		PCB.draw_rectangle(420, 25, 445, 50, Grey); // Draw White square
		PCB.draw_text(425, 30, "%s", Black, Grey, 0.5f, 20, "IC");

		if (display.button() && display.mouse_x() >= 25 && display.mouse_x() <= 120 && display.mouse_y() >= 25 && display.mouse_y() <= 50)
		{
			component = 0;
			std::cout << "Resistor";
		}

		else if (display.button() && display.mouse_x() >= 130 && display.mouse_x() <= 235 && display.mouse_y() >= 25 && display.mouse_y() <= 50)
		{
			component = 1;
			std::cout << "Capacitor";
		}

		else if (display.button() && display.mouse_x() >= 245 && display.mouse_x() <= 350 && display.mouse_y() >= 25 && display.mouse_y() <= 50)
		{
			component = 2;
			std::cout << "Transistor";
		}

		else if (display.button() && display.mouse_x() >= 370 && display.mouse_x() <= 410 && display.mouse_y() >= 25 && display.mouse_y() <= 50)
		{
			component = 3;
			std::cout << "LED";
		}

		else if (display.button() && display.mouse_x() >= 420 && display.mouse_x() <= 445 && display.mouse_y() >= 25 && display.mouse_y() <= 50)
		{
			component = 4;
			std::cout << "IC";
		}

	Case:
		(component = 0)
		{
			if (display.button() && display.mouse_x() >= 0 && display.mouse_y() >= 0)
			{
				const int x = display.mouse_x();
				const int y = display.mouse_y();

				PCB.draw_rectangle(x - 14, y - 32, x + 14, y - 4, White); // Draw White square
				PCB.draw_rectangle(x - 14, y + 4, x + 14, y + 32, White); // Draw White square	
			}
		}

		PCB.display(display); // Display PCB layout interface

	}
	return 0;
}