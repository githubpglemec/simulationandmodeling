#include <stdio.h>

// Function to generate pseudo-random numbers using the mid-square method
unsigned int midSquareRandom(unsigned int seed, int digits) {
    // Calculate the square of the seed
    unsigned long long square = (unsigned long long)seed * seed;

    // Find the middle digits
    unsigned int middleDigits = (square / 100) % (unsigned int)pow(10, digits);

    return middleDigits;
}

int main() {
    // Seed value for the random number generator
    unsigned int seed = 3567;

    // Number of digits to extract from the middle
    int digits = 4;

    // Generate and print 10 pseudo-random numbers
    for (int i = 0; i < 10; ++i) {
        // Generate the next pseudo-random number
        seed = midSquareRandom(seed, digits);

        // Print the generated number
        printf("%d: %u\n", i + 1, seed);
    }

    return 0;
}
