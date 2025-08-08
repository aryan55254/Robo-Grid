#include <iostream>
#include <string>
#include <vector>

// robo class is to definig the coordinates of where robo is on the grid and functions to get its coordinates
class robo
{
    int x;
    int y;

public:
    robo(int start_x, int start_y) : x(start_x), y(start_y) {};
    int get_x()
    {
        return x - 1;
    };
    int get_y()
    {
        return y - 1;
    };
};
// grid class is to define the height and width of the grid and has vector of char vector to make grid also provides public functions to display grid and place robot
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

    void place_robot(robo &robot)
    {
        int x = robot.get_x();
        int y = robot.get_y();
        if (y >= 0 && y <= height && x >= 0 && x <= width)
        {
            data[y][x] = 'R';
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

int main()
{
    Grid grido1(10, 10);
    robo robbie(2, 4);
    grido1.place_robot(robbie);
    grido1.display();
    return 0;
}