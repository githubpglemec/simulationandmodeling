#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HAND_SIZE 5  // Size of each poker hand

// Function to perform the Poker Test
void pokerTest(int sequence[], int length) {
    int totalHands = length / HAND_SIZE;
    int distinctHands[100] = {0};  // Array to track occurrences of distinct poker hands

    // Process each poker hand in the sequence
    for (int i = 0; i < totalHands; ++i) {
        // Extract a poker hand from the sequence
        int hand[HAND_SIZE];
        for (int j = 0; j < HAND_SIZE; ++j) {
            hand[j] = sequence[i * HAND_SIZE + j];
        }

        // Update occurrences of the poker hand
        distinctHands[i]++;
    }

    // Calculate observed frequencies
    int observedFrequencies = 0;
    for (int i = 0; i < 100; ++i) {
        if (distinctHands[i] > 0) {
            observedFrequencies++;
        }
    }

    // Calculate expected frequencies (assuming uniform distribution)
    int expectedFrequency = totalHands / observedFrequencies;

    // Calculate Chi-Square statistic
    double chiSquare = 0.0;
    for (int i = 0; i < 100; ++i) {
        if (distinctHands[i] > 0) {
            chiSquare += pow(distinctHands[i] - expectedFrequency, 2) / expectedFrequency;
        }
    }

    // Print the Chi-Square statistic
    printf("Chi-Square Statistic: %f\n", chiSquare);

    // Additional printf statement
    printf("Name: Hari Prasad Gyawali, Symbol No: 26443/077\n");
}

int main() {
    // Example sequence: 20 numbers (4 poker hands of size 5)
    int sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // Perform the simplified Poker Test
    pokerTest(sequence, 20);

    return 0;
}
