#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double monteCarloPi(int iterations) {
    int insideCircle = 0;

    // Seed for random number generation
    srand(time(NULL));

    for (int i = 0; i < iterations; ++i) {
        // Generate random coordinates in the unit square
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        // Check if the point is inside the unit circle
        if (x * x + y * y <= 1.0) {
            insideCircle++;
        }
    }

    // Calculate the estimated value of PI
    double pi = 4.0 * insideCircle / iterations;

    return pi;
}

int main() {
    int iterations;
    printf("Enter the number of iterations for Monte Carlo simulation: ");
    scanf("%d", &iterations);

    // Calculate PI using Monte Carlo simulation
    double estimatedPi = monteCarloPi(iterations);

    // Print the result
    printf("Estimated value of PI after %d iterations: %f\n", iterations, estimatedPi);

    // Additional printf statement
    printf("Name: Hari Prasad Gyawali, Symbol No: 26443/077\n");

    return 0;
}
