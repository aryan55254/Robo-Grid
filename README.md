# Robo-Grid
A simple command-line simulation of robots moving on a 2D grid, written in C++.

## Description

This program simulates the movement of different types of robots on a grid. The base `robo` class moves randomly, and specialized classes like `ScoutRobot` can be derived from it. The simulation runs for a fixed number of turns, displaying the state of the grid after each turn.

## Getting Started

### Prerequisites

You will need a C++ compiler (like G++) installed on your system.

### Compiling

To compile the program, navigate to the source directory and run the following command:

```sh
g++ -o simulator main.cpp -std=c++11
````

### Running

To execute the compiled program, use:

```sh
./simulator
```

## How It Works

  * The `Grid` class represents the 2D world.
  * The `robo` class is the base for all robots and implements random movement.
  * `ScoutRobot` is an example of a specialized robot type, inheriting from `robo`.
  * The `Simulator` class initializes the grid and robots and manages the main simulation loop.
  * The `main` function starts the simulation.

The output will show the 10x10 grid for 15 turns. The `R` marker represents a standard robot, and the `S` marker represents a Scout Robot.

```
```