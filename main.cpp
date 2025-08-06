#include <iostream>
#include <string>
#include <vector>

class Grid
{
    int width;
    int height;
    std::vector<std::vector<char>> data;

public:
    Grid(int w, int h) : width(w), height(h)
    {
        data.resize(height);
        for (int i = 0; i < height; i++)
        {
            data[i].resize(width, '.');
        }
    };
    void display()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

class robo
{
    int x;
    int y;

public:
    robo(int start_x, int start_y) : x(start_x), y(start_y) {};
};
int main()
{
    Grid grido1(10, 10);
    grido1.display();
    return 0;
}