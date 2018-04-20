#include "CImg.hpp"
#include <iostream>
using namespace cimg_library;

#define length 900
#define width 700

int main() {
	CImg<unsigned char> PCB(length, width, 1, 3, 0); // Creates window

	CImgDisplay display(PCB, "PCB Autorouter"); // Names window

	unsigned int colour1[3] = { 255, 255, 255 }; // RGB colour of White
	unsigned int colour2[3] = { 0, 0, 0 }; // RGB colour of Black
	unsigned int colour3[3] = { 255, 255, 0 }; // RGB colour of Yellow
	unsigned int colour4[3] = { 0, 0, 255 }; // RGB colour of Blue
	unsigned int colour5[3] = { 0, 255, 0 }; // RGB colour of Green
	unsigned int colour6[3] = { 255, 0, 0 }; // RGB colour of Red

	while (!display.is_closed()) { // While the window is open
		PCB.draw_rectangle(80, 80, 40, 40, colour1); // Draw White square
		PCB.draw_rectangle(140, 80, 100, 40, colour1); // Draw White square
		PCB.draw_text(55, 55, "%s", colour2, colour1, 0.5f, 15, "1"); // Draw number 1 on the first square
		PCB.draw_text(115, 55, "%s", colour2, colour1, 0.5f, 15, "2"); // Draw number 2 on the second square

		PCB.draw_circle(150, 150, 18, colour1); // Draw White circle
		PCB.draw_circle(800, 600, 18, colour1); // Draw White circle
		PCB.draw_circle(150, 600, 18, colour1); // Draw White circle
		PCB.draw_circle(850, 150, 18, colour1); // Draw White circle

		PCB.draw_circle(200, 250, 8, colour1); // Draw White circle
		PCB.draw_circle(225, 250, 8, colour1); // Draw White circle
		PCB.draw_circle(250, 250, 8, colour1); // Draw White circle
		PCB.draw_circle(275, 250, 8, colour1); // Draw White circle

		PCB.draw_rectangle(193, 268, 207, 282, colour1); // Draw White square
		PCB.draw_circle(225, 275, 8, colour1); // Draw White circle
		PCB.draw_circle(250, 275, 8, colour1); // Draw White circle
		PCB.draw_circle(275, 275, 8, colour1); // Draw White circle

		PCB.draw_circle(550, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(575, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(600, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(625, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(650, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(675, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(700, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(725, 225, 8, colour1); // Draw White circle

		PCB.draw_rectangle(343, 218, 357, 232, colour1); // Draw White square
		PCB.draw_circle(375, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(400, 225, 8, colour1); // Draw White circle
		PCB.draw_circle(425, 225, 8, colour1); // Draw White circle

		PCB.draw_rectangle(293, 368, 307, 382, colour1); // Draw White square
		PCB.draw_circle(325, 375, 8, colour1); // Draw White circle

		PCB.draw_rectangle(393, 368, 407, 382, colour1); // Draw White square
		PCB.draw_circle(400, 400, 8, colour1); // Draw White circle
		PCB.draw_circle(400, 425, 8, colour1); // Draw White circle

		PCB.draw_rectangle(393, 493, 407, 507, colour1); // Draw White square
		PCB.draw_circle(400, 525, 8, colour1); // Draw White circle
		PCB.draw_circle(400, 550, 8, colour1); // Draw White circle

		// BOTTOM LAYER PATHWAYS //
		PCB.draw_line(150, 200, 150, 170, colour3); // Draw Yellow line of the bottom path layer
		PCB.draw_line(150, 200, 450, 200, colour3); // Draw Yellow line of the bottom path layer
		PCB.draw_line(200, 200, 200, 240, colour3); // Draw Yellow line of the bottom path layer
		PCB.draw_line(450, 200, 450, 450, colour3); // Draw Yellow line of the bottom path layer
		PCB.draw_line(450, 450, 770, 450, colour3); // Draw Yellow line of the bottom path layer
		PCB.draw_line(300, 200, 300, 368, colour3); // Draw Yellow line of the bottom path layer
		PCB.draw_line(450, 400, 790, 400, colour3); // Draw Yellow line of the bottom path layer

		// THIRD LAYER PATHWAYS //
		PCB.draw_line(850, 200, 850, 170, colour4); // Draw Blue line of the second bottom path layer
		PCB.draw_line(500, 200, 850, 200, colour4); // Draw Blue line of the second bottom path layer
		PCB.draw_line(500, 200, 500, 600, colour4); // Draw Blue line of the second bottom path layer
		PCB.draw_line(500, 400, 410, 400, colour4); // Draw Blue line of the second bottom path layer
		PCB.draw_line(390, 400, 90, 400, colour4); // Draw Blue line of the second bottom path layer
		PCB.draw_line(90, 400, 90, 170, colour4); // Draw Blue line of the second bottom path layer
		PCB.draw_line(500, 525, 410, 525, colour4); // Draw Blue line of the second bottom path layer

		// SECOND LAYER PATHWAYS //
		PCB.draw_line(800, 510, 800, 580, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(800, 550, 410, 550, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(600, 550, 600, 250, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(600, 500, 410, 500, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(300, 250, 775, 250, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(775, 250, 775, 320, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(300, 250, 300, 150, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(780, 500, 800, 500, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(390, 550, 325, 550, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(325, 550, 250, 400, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(250, 400, 225, 400, colour5); // Draw Green line of the second top path layer
		PCB.draw_line(225, 400, 225, 285, colour5); // Draw Green line of the second top path layer

		// TOP LAYER PATHWAYS //
		PCB.draw_line(150, 275, 150, 580, colour6); // Draw Red line of the top path layer
		PCB.draw_line(150, 275, 190, 275, colour6); // Draw Red line of the top path layer
		PCB.draw_line(150, 500, 300, 280, colour6); // Draw Red line of the top path layer
		PCB.draw_line(300, 280, 550, 280, colour6); // Draw Red line of the top path layer
		PCB.draw_line(480, 280, 480, 150, colour6); // Draw Red line of the top path layer
		PCB.draw_line(550, 280, 775, 350, colour6); // Draw Red line of the top path layer

		PCB.draw_circle(800, 500, 8, colour1); // Draw White circle
		PCB.draw_circle(800, 475, 8, colour1); // Draw White circle
		PCB.draw_circle(800, 450, 8, colour1); // Draw White circle
		PCB.draw_circle(800, 425, 8, colour1); // Draw White circle
		PCB.draw_circle(800, 400, 8, colour1); // Draw White circle
		PCB.draw_circle(800, 375, 8, colour1); // Draw White circle
		PCB.draw_circle(800, 350, 8, colour1); // Draw White circle
		PCB.draw_circle(800, 325, 8, colour1); // Draw White circle

		PCB.draw_circle(775, 500, 8, colour1); // Draw White circle
		PCB.draw_circle(775, 475, 8, colour1); // Draw White circle
		PCB.draw_circle(775, 450, 8, colour1); // Draw White circle
		PCB.draw_circle(775, 425, 8, colour1); // Draw White circle
		PCB.draw_circle(775, 400, 8, colour1); // Draw White circle
		PCB.draw_circle(775, 375, 8, colour1); // Draw White circle
		PCB.draw_circle(775, 350, 8, colour1); // Draw White circle
		PCB.draw_circle(775, 325, 8, colour1); // Draw White circle

		PCB.draw_circle(550, 425, 8, colour1); // Draw White circle
		PCB.draw_circle(575, 425, 8, colour1); // Draw White circle
		PCB.draw_circle(600, 425, 8, colour1); // Draw White circle
		PCB.draw_circle(625, 425, 8, colour1); // Draw White circle
		PCB.draw_circle(650, 425, 8, colour1); // Draw White circle
		PCB.draw_circle(675, 425, 8, colour1); // Draw White circle

		PCB.draw_circle(700, 350, 8, colour1); // Draw White circle
		PCB.draw_circle(650, 350, 8, colour1); // Draw White circle
		PCB.draw_rectangle(693, 368, 707, 382, colour1); // Draw White square
		PCB.draw_rectangle(623, 343, 637, 357, colour1); // Draw White square

		PCB.draw_ellipse(300, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(320, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(340, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(360, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(380, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(400, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(420, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(440, 150, 6, 12, 0, colour1); // Draw White ellipse

		PCB.draw_ellipse(480, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(500, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(520, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(540, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(560, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(580, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(600, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(620, 150, 6, 12, 0, colour1); // Draw White ellipse

		PCB.draw_ellipse(660, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(680, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(700, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(720, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(740, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(760, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(780, 150, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(800, 150, 6, 12, 0, colour1); // Draw White ellipse

		PCB.draw_ellipse(300, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(320, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(340, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(360, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(380, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(400, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(420, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(440, 600, 6, 12, 0, colour1); // Draw White ellipse

		PCB.draw_ellipse(480, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(500, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(520, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(540, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(560, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(580, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(600, 600, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(620, 600, 6, 12, 0, colour1); // Draw White ellipse

		PCB.draw_ellipse(110, 160, 6, 12, 0, colour1); // Draw White ellipse
		PCB.draw_ellipse(90, 160, 6, 12, 0, colour1); // Draw White ellipse
		
		PCB.display(display); // Display PCB layout interface

		/*display.wait(); // Wait for mouse click
		if (display.button() && display.mouse_y() >= 0 && display.mouse_x() >= 0) {
			const int y = display.mouse_y();
			const int x = display.mouse_x();
			PCB.draw_rectangle(x, y, 500, 500, colour1); // Draw rectangle
		}
		PCB.display(display); // Display the rectangle*/

	}
	return 0;
}