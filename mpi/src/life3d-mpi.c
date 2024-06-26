#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <omp.h>
#include <mpi.h>

#include "constants.h"
#include "grid.h"

/**
 * @brief Entry point of the program.
 *
 * Receives the input parameters and runs the simulation.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return 0 if the program exits successfully, 1 otherwise.
 */
int main(int argc, char *argv[])
{
    // Initialize MPI
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <number of generations> <number of cells per side of the cube> <density of the initial population> <seed for the random number generator>\n", argv[0]);
        MPI_Finalize();
        return 1;
    }

    int32_t num_generations = atoi(argv[1]);
    int32_t num_cells = atoi(argv[2]);
    double density = atof(argv[3]);
    int seed = atoi(argv[4]);

    double exec_time;

    // Calculate the range of x-coordinates for this process
    int32_t start_x = (rank * num_cells) / size;
    int32_t end_x = ((rank + 1) * num_cells) / size;

    // Generate initial grid for this process
    char ***grid = gen_initial_grid_partial(num_cells, density, seed, start_x, end_x);

    int64_t *max_counts = (int64_t *)calloc(N_SPECIES + 1, sizeof(long));
    int32_t *max_generations = (int32_t *)calloc(N_SPECIES + 1, sizeof(int));

    exec_time = -omp_get_wtime();

    // Run the simulation
    simulation(grid, num_cells, max_counts, max_generations, num_generations, start_x, end_x, rank, size);

    exec_time += omp_get_wtime();

    // Print execution time
    if (rank == 0)
        fprintf(stderr, "%.1f\n", exec_time);

    // Print the result to stdout
    if (rank == 0)
        print_result(max_counts, max_generations);

    MPI_Finalize();
    return 0;
}
