#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

class robo
{
private:
    int x;
    int y;

public:
    robo(int start_x, int start_y) : x(start_x), y(start_y) {}

    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }

    virtual char get_marker()
    {
        return 'R';
    }

    virtual void move(int grid_width, int grid_height)
    {
        int direction = rand() % 4;
        switch (direction)
        {
        case 0: // Move Up
            if (y > 0)
                y--;
            break;
        case 1: // Move Down
            if (y < grid_height - 1)
                y++;
            break;
        case 2: // Move Left
            if (x > 0)
                x--;
            break;
        case 3: // Move Right
            if (x < grid_width - 1)
                x++;
            break;
        }
    }
};

class Grid
{
private:
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
    }

    int get_width()
    {
        return width;
    }

    int get_height()
    {
        return height;
    }

    void place_robot(robo &robot)
    {
        int x = robot.get_x();
        int y = robot.get_y();
        if (y >= 0 && y < height && x >= 0 && x < width)
        {
            data[y][x] = robot.get_marker();
        }
    }

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

class ScoutRobot : public robo
{
public:
    ScoutRobot(int start_x, int start_y) : robo(start_x, start_y) {}

    char get_marker() override
    {
        return 'S';
    }
};

class Simulator
{
private:
    Grid grid;
    std::vector<robo *> robots;

public:
    Simulator(int grid_width, int grid_height) : grid(grid_width, grid_height)
    {
        robots.push_back(new robo(0, 0));
        robots.push_back(new ScoutRobot(5, 5));
    }

    ~Simulator()
    {
        for (robo *r : robots)
        {
            delete r;
        }
    }

    void run()
    {
        for (int turn = 0; turn < 15; ++turn)
        {
            for (robo *r : robots)
            {
                r->move(grid.get_width(), grid.get_height());
            }

            grid = Grid(grid.get_width(), grid.get_height());

            for (robo *r : robots)
            {
                grid.place_robot(*r);
            }

            std::cout << "--- Turn " << turn + 1 << " ---" << std::endl;
            grid.display();

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

int main()
{
    srand(time(0));
    Simulator sim(10, 10);
    sim.run();
    return 0;
}