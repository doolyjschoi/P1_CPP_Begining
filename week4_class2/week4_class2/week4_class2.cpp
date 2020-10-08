#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>


//glfw
const int width = 640;
const int height = 480;

float* pixels = new float[width * height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
void drawThicknerLine(const int& thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawFilledSquare(int size, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawPolygon();
void drawCircle(const double& rad, const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawTriangle();
void drawEmptySquare(int size, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawOnPixelBuffer();

class GeometricObject
{
public:

	virtual void draw()
	{
		std::cout << "Geometric Draw" << std::endl;
	}
};


class Line : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;

	Line()
	{}

	Line(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		initialize(_start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;

	}
	void draw()
	{
		for (int i = start_x; i <= end_x; i++)
		{
			const int j = (end_y - start_y) * (i - start_x) / (end_x - start_x) + start_y;

			drawPixel(i, j, 0.0f, 0.3f, 0.8f);
		}
	}
};

class Box : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;
	int size;

	Box() // default constructor
	{}

	Box(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y, const int& _size) // constructor 
	{
		initialize(_start_x, _start_y, _end_x, _end_y, _size);
	}

	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y, const int& _size)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
		size = _size;
	}

	//void draw()
	//{
	//	std::cout << "Box::Draw" << std::endl;
	//}


	void drawFilledSquare() 
	{
		int i_center = (start_x + end_x) / 2;
		int j_center = (start_y + end_y) / 2;

		for (int j = j_center - size; j < j_center + size; j++) {
			for (int i = i_center - size; i < i_center + size; i++) {
				drawPixel(i, j, 0.7f, 0.5f, 0.8f);
			}
		}
	}

	void draw() 
	{
		int i_center = (start_x + end_x) / 2;
		int j_center = (start_y + end_y) / 2;

		for (int j = j_center - size; j <= j_center + size; j++) {
			for (int i = i_center - size; i <= i_center + size; i = i + size * 2)
				drawPixel(i, j, 0.3f, 0.6f, 0.7f);

		}
		for (int i = i_center - size; i <= i_center + size; i++) {
			for (int j = j_center - size; j <= j_center + size; j = j + size * 2)
				drawPixel(i, j, 0.3f, 0.6f, 0.7f);
		}
	}

};

class Circle
{
public:
	int center_x, center_y;
	double radius;

	void setup(const int& _center_x, const int& _center_y, const double& _radius)
	{
		center_x = _center_x;
		center_y = _center_y;
		radius = _radius;
	}

	void draw()
	{
		for (double i = 0.0; i < 360.0; i += 0.1)
		{
			double angle = i * M_PI / 180;

			int x = (int)(center_x + radius * cos(angle));
			int y = (int)(center_y + radius * sin(angle));

			drawPixel(x, y, 0.3f, 0.9f, 0.8f);
		}
	}

};

//void drawBoxes()
//{
//	const int num_boxes = 10;
//	Box* my_boxes = new Box[num_boxes];
//
//	for (int i = 0; i < num_boxes; i++)
//	{
//		my_boxes[i].initialize(80 * i + 0, 350, 80 * i + 50, 400, 30);
//	}
//	for (int i = 0; i < num_boxes; i++)
//	{
//		if (i % 2 == 0)
//		{
//			my_boxes[i].drawFilledSquare();
//		}
//		else
//		{
//			my_boxes[i].drawEmptySquare();
//		}
//	}
//}

void drawCircles()
{
	const int num_circles = 10;

	Circle* my_circles = new Circle[num_circles];

	for (int i = 0; i < num_circles; i++)
	{
		my_circles[i].setup(i * 50 + 0, 300, 40.0);
	}
	for (int i = 0; i < num_circles; i++)
		my_circles[i].draw();
}

//void drawLines()
//{
//	const int num_lines = 10;
//
//	Line* my_lines = new Line[num_lines];
//
//	for (int i = 0; i < num_lines; i++)
//	{
//		my_lines[i].initialize(50 * i + 0, 0, 50 * i + 50, 15);
//	}
//
//	for (int i = 0; i < num_lines; i++)
//		my_lines[i].draw();
//}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//GeometricObject *my_geo = new GeometricObject;
		//my_geo->draw();
		const int num_lines = 5;
		const int num_boxes = 7;
		const int num_objects = 12;

		// ① make pointer array
		//Line **my_lines = new Line*[num_lines];
		//Box **my_box = new Box*[num_boxes];
		GeometricObject **my_objects = new GeometricObject*[num_lines + num_boxes];



		// ② initialize pointer array
		for (int i = 0; i < num_lines; i++)
		{
			Line* temp = new Line;
			temp->start_x = 0 + 50 * i;
			temp->start_y = 100;
			temp->end_x = 50 + 50 * i;
			temp->end_y = 150;
			my_objects[i] = temp;
		}
		// use constructor
		//for (int i = 0; i < num_lines; i++)
		//{
		//	my_objects[i] = new Line(0 + 50 * i, 100, 50 + 50 * i, 150);
		//}

		for (int i = num_lines ; i < num_objects; i++)
		{
			my_objects[i] = new Box(0 + 50 * i, 0, 50 + 50 * i, 50, 15);
		}



		// ③ excute function
		//for (int i = 0; i < num_lines; i++)
		//	my_lines[i]->draw();
		//for (int i = 0; i < num_boxes; i++)
		//	my_box[i]->draw();


		for (int i = 0; i < num_lines + num_boxes; i++)
			my_objects[i]->draw();

		
		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width * j) * 3 + 0] = red;
	pixels[(i + width * j) * 3 + 1] = green;
	pixels[(i + width * j) * 3 + 2] = blue;
}
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0) * (i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
void drawThicknerLine(const int& thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0) * (i - i0) / (i1 - i0) + j0;

		for (int k = 0; k < thickness; k++) {
			drawPixel(i + k, j, red, green, blue);
		}
	}
}

void drawFilledSquare(int size, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	int i_center = (i0 + i1) / 2;
	int j_center = (j0 + j1) / 2;

	for (int j = j_center - size; j < j_center + size; j++) {
		for (int i = i_center - size; i < i_center + size; i++) {
			drawPixel(i, j, red, green, blue);
		}
	}
}
void drawEmptySquare(int size, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	int i_center = (i0 + i1) / 2;
	int j_center = (j0 + j1) / 2;

	for (int j = j_center - size; j <= j_center + size; j++) {
		for (int i = i_center - size; i <= i_center + size; i = i + size * 2)
			drawPixel(i, j, red, green, blue);

	}
	for (int i = i_center - size; i <= i_center + size; i++) {
		for (int j = j_center - size; j <= j_center + size; j = j + size * 2)
			drawPixel(i, j, red, green, blue);
	}
}
void drawPolygon() {
	
	//
	//int i_center = 420;
	//int j_center = 230;
	//int size = 10;
	//int j_start = j_center - size;
	//int j_end = j_center + size;
	//for (int j = j_start; j <= j_end + size; j++) {
	//	int i_start = i_center - size + (j / 5);
	//	int i_end = i_center + size - (j / 5);
	//	for (int i = i_start; i <= i_end; i++) {
	//		if(j == j_start || j == j_end || i == i_start || i == i_end)
	//		drawPixel(i, j, 0.0f, 0.0f, 1.0f);
	//	}
	//}
	
	drawLine(500, 200, 550, 200, 0.0f, 0.0f, 0.0f);
	drawLine(480, 250, 525, 290, 0.0f, 0.0f, 0.0f);
	drawLine(525, 290, 570, 250, 0.0f, 0.0f, 0.0f);

	drawLine(480, 250, 500, 200, 0.0f, 0.0f, 0.0f);
	drawLine(480, 251, 500, 201, 0.0f, 0.0f, 0.0f);

	drawLine(550, 200, 570, 250, 0.0f, 0.0f, 0.0f);
	drawLine(550, 201, 570, 251, 0.0f, 0.0f, 0.0f);
}
void drawCircle(const double& rad, const int& i0, const int& j0, const float& red, const float& green, const float& blue) {

	{
		for (double i = 0.0; i < 360.0; i += 0.1)
		{
			double angle = i * M_PI / 180;

			int x = (int)(i0 + rad * cos(angle));
			int y = (int)(j0 + rad * sin(angle));

			drawPixel(x, y, red, green, blue);
		}
	}

}
void drawTriangle() {

	int i_center = 100;
	int j_center = 100;
	int size = 70;
	int j_start = j_center - size;
	int j_end = j_center + size;

	for (int j = j_start; j <= j_end; j++) {
		int i_start = i_center - size + (j / 2);
		int i_end = i_center + size - (j / 2);

		for (int i = i_start; i <= i_end; i++) {
			if (j == j_start || j == j_end || i == i_start || i == i_end)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		}
	}
}
void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	//std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	// Èò»ö ¹è°æ
	for (int i = 0; i < width * height; i++) {
		pixels[i * 3 + 0] = 1.0f; // red 
		pixels[i * 3 + 1] = 1.0f; // green
		pixels[i * 3 + 2] = 1.0f; // blue
	}

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	//const int i0 = 100, i1 = 200;
	//const int j0 = 300, j1 = 400;
	//const int thickness = 10;
	//const int size = 50;
	//drawLine(i0 + 100, j0 - 100, i1 + 100, j1 - 100, 1.0f, 0.0f, 0.0f);
	//drawLines();
	drawCircles();
	//drawBoxes();


	//drawThicknerLine(thickness, i0, j0, i1, j1, 0.0f, 1.0f, 0.0f);
	//drawFilledSquare(size, i0 + 300, j0, i1 + 300, j1, 0.0f, 0.5f, 0.3f);
	//drawEmptySquare(size, i0 + 100, j0, i1 + 100, j1, 1.0f, 0.0f, 0.0f);
	//drawCircle(50, i0 + 100, i1 + 100, 0.0f, 1.0f, 0.0f);
	drawTriangle();
	//drawPolygon();
	//TODO: try moving object
}
