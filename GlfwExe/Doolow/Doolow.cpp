#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include "math.h"

const int width = 640;
const int height = 480;

float* pixels = new float[width * height * 3];

void drawPixel(const int& x, const int& y, const float& red, const float& green, const float& blue);
void drawLine(const int& start_x, const int& start_y, const int& end_x, const int& end_y, const float& red, const float& green, const float& blue);

class Line
{
private:
    int start_x, start_y;
    int end_x, end_y;

public:
    void initialize(int _start_x, int _start_y, int _end_x, int _end_y)
    {
        start_x = _start_x;
        start_y = _start_y;
        end_x = _end_x;
        end_y = _end_y;
    }

    void draw()
    {
        drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
    }


};

class Square
{
private:
    int start_x, start_y;
    int end_x, end_y;

public:
    void initialize(int _start_x, int _start_y, int _end_x, int _end_y)
    {
        start_x = _start_x;
        start_y = _start_y;
        end_x = _end_x;
        end_y = _end_y;
    }

    void drawEmptySquare()
    {
        drawLine(start_x, start_y, start_x, end_y, 1.0f, 0.0f, 0.0f);
        drawLine(start_x, end_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
        drawLine(start_x, start_y, end_x, start_y, 1.0f, 0.0f, 0.0f);
        drawLine(end_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
    }

    void drawFilledSquare()
    {
        for (int j = start_y; j < end_y; j++)
        {
            for (int i = start_x; i < end_x; i++)
                drawPixel(i, j, 0.0f, 0.0f, 1.0f);
        }
    }
};

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
    const int num_lines = 15;
    Line* my_lines = new Line[num_lines];

    for (int i = 0; i < num_lines; i++)
    {
        my_lines[i].initialize(50 * i + 10, 10, 50 * i + 10, 60);
    }

    for (int i = 0; i < num_lines; i++)
        my_lines[i].draw();
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Welcome to Dool's wolrd!", NULL, NULL);
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
        
        clearBackground();
        drawLines;

        const int i = rand() % width, j = rand() % height;
        drawPixel(i, j, 1.0f, 1.0f, 1.0f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

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

