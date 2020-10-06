#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>

const int width = 1024;
const int height = 768;


// color = (red, green, blue)
float* pixels = new float[width * height * 3]; //=malloc



void drawPixel(const int& x, const int& y, const float& red, const float& green, const float& blue)
{
	pixels[(x + width * y) * 3 + 0] = red;
	pixels[(x + width * y) * 3 + 1] = green;
	pixels[(x + width * y) * 3 + 2] = blue;
}

void drawLine(const int& start_x, const int& start_y, const int& end_x, const int& end_y, const float& red, const float& green, const float& blue)
{
	if (end_x == start_x)
	{
		for (int y = start_y; y <= end_y; y++)
			drawPixel(start_x, y, red, green, blue);
	}
	else
	{
		for (int i = start_x; i <= end_x; i++)
		{
			const int j = (end_y - start_y) * (i - start_x) / (end_x - start_x) + start_y;
			drawPixel(i, j, red, green, blue);
		}
	}
}

class Line
{
private: // access modifier (3 types: public, private, protected)
	int start_x, start_y; // member variables
	int end_x, end_y;
	//int red, green, blue;

public:
	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}
	void draw() // member function
	{
		// draw lines
		drawLine(start_x, start_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
	}
};

class Square
{
public:
	int start_x, start_y;
	int end_x, end_y;

	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}

	void draw()
	{
		// draw square
		drawLine(start_x, start_y, start_x, end_y, 0.0f, 0.0f, 1.0f);
		drawLine(start_x, end_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
		drawLine(start_x, start_y, end_x, start_y, 0.0f, 0.0f, 1.0f);
		drawLine(end_x, start_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
	}

	void drawFill()
	{
		for (int j = start_y; j < end_y; j++)
		{
			for (int i = start_x; i < end_x; i++)
				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
		}
	}
};

//class Circle
//{
//public:
//	float center_x, center_y;
//	float radius;
//	int num_segments;
//
//	void initialize(const int& _center_x, const int& _center_y, const int& _radius)
//	{
//		center_x = _center_x;
//		center_y = _center_y;
//		radius = _radius;
//	}
//
//	void draw()
//	{
//		// draw circle
//	}
//};

//void drawEmptySquare()
//{
//	drawLine(200, 400, 250, 400, 0.0f, 0.0f, 1.0f);
//	drawLine(200, 350, 250, 350, 0.0f, 0.0f, 1.0f);
//	drawLine(200, 350, 200, 400, 0.0f, 0.0f, 1.0f);
//	drawLine(250, 350, 250, 400, 0.0f, 0.0f, 1.0f);
//}

void clearBackground()
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
			drawPixel(i, j, 1.0f, 1.0f, 1.0f);
	}
}

void drawLines()
{
	const int num_lines = 10;
	Line* my_lines = new Line[num_lines];

	// initialize lines
	for (int i = 0; i < num_lines; i++)
	{
		my_lines[i].initialize(30 * i + 10, 10, 30 * i + 50, 50);
	}

	// draw lines
	for (int i = 0; i < num_lines; i++)
		my_lines[i].draw();

	delete[] my_lines;
}

void drawEmptySquare()
{
	const int num_squares = 10;
	Square* my_squares = new Square[num_squares];

	// initialize squares
	for (int i = 0; i < num_squares; i++)
	{
		my_squares[i].initialize(50 * i + 10, 150, 50 * i + 30, 200);
	}

	// draw emptysquares
	for (int i = 0; i < num_squares; i++)
		my_squares[i].draw();

	delete[] my_squares;
}

void drawfilledSquare()
{
	const int num_filledsquares = 10;
	Square* my_filledsquares = new Square[num_filledsquares];

	// initialize
	for (int i = 0; i < num_filledsquares; i++)
	{
		my_filledsquares[i].initialize(50 * i + 30, 250, 50 * i + 60, 300);
	}

	// draw filledsquares
	for (int i = 0; i < num_filledsquares; i++)
		my_filledsquares[i].drawFill();

	delete my_filledsquares;
}

//void drawCircle()
//{
//	const int num_circles = 10;
//	Circle* my_circles = new Circle[num_circles];
//
//	// initialize
//	for (int i = 0; i < num_circles; i++)
//	{
//		my_circles[i].initialize(50 * i + 50, 350, 15);
//	}
//
//	//draw circles
//	for (int i = 0; i < num_circles; i++)
//		my_circles[i].draw();
//}



void draw()
{
	/*사선*/
	//for (int i = 50; i >= 46; i--)
	//{
	//	static int y = 350;

	//	for (int j = 0; j < 3; j++)
	//	{
	//		drawLine(i, y + j, i + 50, (y + j) + 50, 0.0f, 0.0f, 1.0f);
	//	}

	//	y += 2;
	//	if (y >= 360)
	//		y = 350;
	//}

	/*삼각형*/
	//drawLine(50, 50, 100, 100, 0.0f, 0.0f, 1.0f);
	//drawLine(100, 100, 150, 50, 0.0f, 0.0f, 1.0f);
	//drawLine(50, 50, 150, 50, 0.0f, 0.0f, 1.0f);


	/*오각형*/
	//drawLine(170, 50, 200, 80, 0.0f, 0.0f, 1.0f);
	//drawLine(200, 80, 230, 50, 0.0f, 0.0f, 1.0f);
	//drawLine(170, 50, 180, 30, 0.0f, 0.0f, 1.0f);
	//drawLine(220, 30, 230, 50, 0.0f, 0.0f, 1.0f);
	//drawLine(180, 30, 220, 30, 0.0f, 0.0f, 1.0f);


	/*원*/
	//int u = 25;
	//for (int i = 0; i<u * 2; i++)
	//{
	//	for (int j = 0; j<u * 2; j++)
	//	{
	//		if (u*u > (i + 0.5 - u)*(i + 0.5 - u) + (j + 0.5 - u)*(j + 0.5 - u))
	//			drawPixel(i + 300, j + 10, 0.0f, 0.0f, 1.0f);
	//	}
	//}
	//u = 24;
	//for (int i = 0; i<u * 2; i++)
	//{
	//	for (int j = 0; j<u * 2; j++)
	//	{
	//		if (u*u > (i + 0.5 - u)*(i + 0.5 - u) + (j + 0.5 - u)*(j + 0.5 - u))
	//			drawPixel(i + 301, j + 11, 1.0f, 1.0f, 1.0f);
	//	}
	//}

	//drawLine(321, 80, 325, 80, 0.0f, 0.0f, 1.0f); drawLine(326, 80, 330, 80, 0.0f, 0.0f, 1.0f);
	//drawLine(317, 79, 320, 79, 0.0f, 0.0f, 1.0f); drawLine(331, 79, 334, 79, 0.0f, 0.0f, 1.0f);
	//drawLine(315, 78, 317, 78, 0.0f, 0.0f, 1.0f); drawLine(334, 78, 336, 78, 0.0f, 0.0f, 1.0f);
	//drawLine(313, 77, 314, 77, 0.0f, 0.0f, 1.0f); drawLine(337, 77, 338, 77, 0.0f, 0.0f, 1.0f);
	//drawLine(312, 76, 313, 76, 0.0f, 0.0f, 1.0f); drawLine(338, 76, 339, 76, 0.0f, 0.0f, 1.0f);
	//drawLine(310, 75, 311, 75, 0.0f, 0.0f, 1.0f); drawLine(340, 75, 341, 75, 0.0f, 0.0f, 1.0f);
	//drawLine(309, 74, 310, 74, 0.0f, 0.0f, 1.0f); drawLine(341, 74, 342, 74, 0.0f, 0.0f, 1.0f);
	//drawLine(308, 73, 309, 73, 0.0f, 0.0f, 1.0f); drawLine(342, 73, 343, 73, 0.0f, 0.0f, 1.0f);
	//drawLine(307, 72, 308, 72, 0.0f, 0.0f, 1.0f); drawLine(343, 72, 344, 72, 0.0f, 0.0f, 1.0f);
	//drawLine(306, 71, 307, 71, 0.0f, 0.0f, 1.0f); drawLine(344, 71, 345, 71, 0.0f, 0.0f, 1.0f);
	//drawLine(306, 70, 306, 70, 0.0f, 0.0f, 1.0f); drawLine(345, 70, 345, 70, 0.0f, 0.0f, 1.0f);
	//drawLine(305, 69, 305, 69, 0.0f, 0.0f, 1.0f); drawLine(346, 69, 346, 69, 0.0f, 0.0f, 1.0f);
	//drawLine(304, 68, 305, 68, 0.0f, 0.0f, 1.0f); drawLine(346, 68, 347, 68, 0.0f, 0.0f, 1.0f);
	//drawLine(304, 67, 304, 67, 0.0f, 0.0f, 1.0f); drawLine(347, 67, 347, 67, 0.0f, 0.0f, 1.0f);
	//drawLine(303, 64, 303, 66, 0.0f, 0.0f, 1.0f); drawLine(348, 64, 348, 66, 0.0f, 0.0f, 1.0f);
	//drawLine(302, 61, 302, 64, 0.0f, 0.0f, 1.0f); drawLine(349, 61, 349, 64, 0.0f, 0.0f, 1.0f);
	//drawLine(301, 56, 301, 60, 0.0f, 0.0f, 1.0f); drawLine(350, 56, 350, 60, 0.0f, 0.0f, 1.0f);

	//drawLine(301, 51, 301, 55, 0.0f, 0.0f, 1.0f); drawLine(350, 51, 350, 55, 0.0f, 0.0f, 1.0f);
	//drawLine(302, 47, 302, 50, 0.0f, 0.0f, 1.0f); drawLine(349, 47, 349, 50, 0.0f, 0.0f, 1.0f);
	//drawLine(303, 45, 303, 47, 0.0f, 0.0f, 1.0f); drawLine(348, 45, 348, 47, 0.0f, 0.0f, 1.0f);
	//drawLine(304, 44, 304, 44, 0.0f, 0.0f, 1.0f); drawLine(347, 44, 347, 44, 0.0f, 0.0f, 1.0f);
	//drawLine(304, 43, 305, 43, 0.0f, 0.0f, 1.0f); drawLine(346, 43, 347, 43, 0.0f, 0.0f, 1.0f);
	//drawLine(305, 42, 305, 42, 0.0f, 0.0f, 1.0f); drawLine(346, 42, 346, 42, 0.0f, 0.0f, 1.0f);
	//drawLine(306, 41, 306, 41, 0.0f, 0.0f, 1.0f); drawLine(345, 41, 345, 41, 0.0f, 0.0f, 1.0f);
	//drawLine(306, 40, 307, 40, 0.0f, 0.0f, 1.0f); drawLine(344, 40, 345, 40, 0.0f, 0.0f, 1.0f);
	//drawLine(307, 39, 308, 39, 0.0f, 0.0f, 1.0f); drawLine(343, 39, 344, 39, 0.0f, 0.0f, 1.0f);
	//drawLine(308, 38, 309, 38, 0.0f, 0.0f, 1.0f); drawLine(342, 38, 343, 38, 0.0f, 0.0f, 1.0f);
	//drawLine(309, 37, 310, 37, 0.0f, 0.0f, 1.0f); drawLine(341, 37, 342, 37, 0.0f, 0.0f, 1.0f);
	//drawLine(310, 36, 311, 36, 0.0f, 0.0f, 1.0f); drawLine(340, 36, 341, 36, 0.0f, 0.0f, 1.0f);
	//drawLine(312, 35, 313, 35, 0.0f, 0.0f, 1.0f); drawLine(338, 35, 339, 35, 0.0f, 0.0f, 1.0f);
	//drawLine(313, 34, 314, 34, 0.0f, 0.0f, 1.0f); drawLine(337, 34, 338, 34, 0.0f, 0.0f, 1.0f);
	//drawLine(315, 33, 317, 33, 0.0f, 0.0f, 1.0f); drawLine(334, 33, 336, 33, 0.0f, 0.0f, 1.0f);
	//drawLine(317, 32, 320, 32, 0.0f, 0.0f, 1.0f); drawLine(331, 32, 334, 32, 0.0f, 0.0f, 1.0f);
	//drawLine(321, 31, 325, 31, 0.0f, 0.0f, 1.0f); drawLine(326, 31, 330, 31, 0.0f, 0.0f, 1.0f);

}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Welcome to Dool's World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// background clearing 
		clearBackground();

		// lines 
		drawLines();

		// emptySquare 
		drawEmptySquare();

		// filledSquare
		//drawfilledSquare();

		//assign all pixels red color
		//draw();

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */	
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	delete[] pixels; //=free

	return 0;
}