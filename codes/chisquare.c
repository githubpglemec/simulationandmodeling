#include <stdio.h>
#include <math.h>

// Function to calculate the Chi-Square statistic
double chiSquareTest(int observed[], int expected[], int categories) {
    double chiSquare = 0.0;

    for (int i = 0; i < categories; ++i) {
        chiSquare += pow(observed[i] - expected[i], 2) / (double)expected[i];
    }

    return chiSquare;
}

int main() {
    // User input for the number of categories
    int categories;
    printf("Enter the number of categories: ");
    scanf("%d", &categories);

    // Arrays to store observed and expected frequencies
    int observed[categories], expected[categories];

    // User input for observed frequencies
    printf("Enter the observed frequencies for each category:\n");
    for (int i = 0; i < categories; ++i) {
        printf("Category %d: ", i + 1);
        scanf("%d", &observed[i]);
    }

    // User input for expected frequencies
    printf("Enter the expected frequencies for each category:\n");
    for (int i = 0; i < categories; ++i) {
        printf("Category %d: ", i + 1);
        scanf("%d", &expected[i]);
    }

    // Perform the Chi-Square test
    double chiSquare = chiSquareTest(observed, expected, categories);

    // Print the Chi-Square statistic
    printf("Chi-Square Statistic: %f\n", chiSquare);

    // Determine the critical value from Chi-Square distribution table (adjust for degrees of freedom if necessary)
    // For demonstration, using a critical value of 7.815 at 0.05 significance level (adjust as needed)
    double criticalValue = 7.815;

    // Compare the Chi-Square statistic with the critical value
    if (chiSquare > criticalValue) {
        printf("Reject the null hypothesis: There is a significant association between variables.\n");
    } else {
        printf("Fail to reject the null hypothesis: No significant association between variables.\n");
    }

    // Additional printf statement
    printf("Name: Hari Prasad Gyawali, Symbol No: 26443/077\n");

    return 0;
}
