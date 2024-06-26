# parallel-game-of-life

> Parallel **Game of Life** explores parallel programming techniques using **OpenMP** and **MPI** to optimize the simulation of the classic Game of Life across **shared and distributed memory systems**.

## Authors

- [110817 André Páscoa](https://github.com/devandrepascoa)
- [110860 André Jesus](https://github.com/andre-j3sus)
- [110893 Nyckollas Brandão](https://github.com/Nyckoka)

@IST<br>
Master in Computer Science and Computer Engineering<br>
Parallel and Distributed Computing - Group 03<br>
Summer  Semester of 2023/2024

## About the Project ℹ️

The project focuses on gaining experience in parallel programming on shared and distributed memory systems, utilizing OpenMP and MPI, respectively. The task involves implementing sequential and parallel versions of the 3D Game of Life.

## Repository Structure 📂

- `serial/`: Contains the source code files for the serial implementation, along with a Makefile for compilation. Additional source files are included.

- `omp/`: Contains the source code files for the OpenMP implementation, along with a Makefile for compilation. Similar to the serial directory, additional source files and a report are included.

- `mpi/`: Contains the source code files for the MPI implementation, along with a Makefile for compilation. Additional source files and a report are included as in the other directories.


## Instructions 📝

To compile and run the code, enter in the respective directory of the version you want to run.

To compile the code, use the provided Makefile. Ensure you have the necessary dependencies installed.

To run the code:
- For the serial implementation: `./life3d <parameters>`
- For the OpenMP implementation: `./life3d <parameters>`
- For the MPI implementation: `mpirun -np <num_processes> ./life3d <parameters>`

Replace `<parameters>` with the required input parameters.
