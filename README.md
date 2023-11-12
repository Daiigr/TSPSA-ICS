# Simulated Annealing for the Traveling Salesman Problem (TSPSA)

## Project Description
This project involves the implementation of a simulated annealing algorithm to solve the Traveling Salesman Problem (TSP), which is a classic optimization problem. The algorithm aims to find the shortest possible path that visits a number of cities exactly once and returns to the origin city. The main components of the solution are energy calculations, temperature cooling schedules, and stochastic acceptance of worse solutions to escape local minima.

here is the [project description](INSTRUCTIONS.md)

here is our report:[report](report/main.pdf)

## How It Works
The codebase consists of several modules:
- `IOManager.h`: Manages input and output operations, including file handling.
- `coordinate.h`: Defines the structure for city coordinates.
- `Path.h`: Defines the functionality to generate and manipulate paths.
- `Energy.h`: Contains the functions to calculate the "energy" or total distance of a path.
- `Temperature.h`: Contains functions related to the temperature aspect of simulated annealing.

The `main.c` file orchestrates the simulated annealing algorithm. It begins by initializing the city coordinates and choosing an initial random path. The annealing process involves generating new path permutations, evaluating their energy, and selectively accepting paths based on the temperature-dependent probability. Throughout the process, the temperature is gradually reduced until it reaches a near-zero value, at which point the algorithm terminates, and the best-found path is considered the solution.

## Interaction with the Project
To interact with the TSPSA project, follow these steps:

1. Compile the code using the provided Makefile with the command `make build`.
2. Run the compiled program with `make run ARGS="your-arguments-here"`, where "your-arguments-here" is replaced with any desired command-line arguments.
3. Command-line argument options are as follows:
   - `-n` or `-N`: To specify the number of cities.
   - `-t` or `-T`: To set the initial temperature for the simulated annealing algorithm.
   - `-c` or `-C`: To define the cooling rate at which the temperature decreases.
   - `-file` or `-FILE`: To read city coordinates from a specified file.
   - `-random` or `-RANDOM`: To generate random city coordinates.

Example usage:
```
make run ARGS="-n 50 -t 100 -c 0.99 -random"
```
This command runs the simulated annealing algorithm on a random set of 50 cities starting at a temperature of 100 and with a cooling rate of 0.99.

4. The program will output the progress of the algorithm, including the current path energy and other relevant information.
5. Upon completion, the program saves the final path to a file, and you can view the solution for the TSP.
## Graphs and Charts
The `graphs` folder contains the graphs and charts that are generated from the graph.IPYNB when the notebook is run. The graphs and charts are generated using the `matplotlib` and `plotly` libraries and are saved as `.png` files. 

if you want to run the notebook you need to install the following libraries:
- `matplotlib`
- `plotly`
- `pandas`
- `numpy`

## Clean Up
To clean up the compiled objects and executable, simply run `make clean`.


## Authors
- Daniel Grbac Bravo (d.grbac.bravo@student.rug.nl)
- Kealan Barry (k.barry@student.rug.nl)

This project is the culmination of our efforts in the "Introduction to Computer Science" course.

## Acknowledgments
We would like to thank our professors and teaching assistants for their guidance and assistance throughout the development of this project.