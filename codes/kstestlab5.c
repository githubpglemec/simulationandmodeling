#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototype for comparison function
int compare(const void* a, const void* b);

// Function to simulate KS test
void ksTest(double* data, int n, double alpha) {
    // Sort the data in ascending order
    qsort(data, n, sizeof(double), compare);

    // Calculate the empirical distribution function (EDF)
    double edf[n];
    for (int i = 0; i < n; ++i) {
        edf[i] = (i + 1) / (double)n;
    }

    // Calculate the expected distribution function (ECDF) based on a uniform distribution
    double theoretical_cdf[n];
    for (int i = 0; i < n; ++i) {
        theoretical_cdf[i] = (i + 1) / (double)n;
    }

    // Calculate the KS test statistic (D)
    double d = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = fabs(edf[i] - theoretical_cdf[i]);
        if (diff > d) {
            d = diff;
        }
    }

    // Calculate the critical value based on the significance level (alpha)
    double critical_value = sqrt(-0.5 * log(alpha / 2.0) / n);

    // Print the results
    printf("KS Test Statistic (D): %f\n", d);
    printf("Critical Value at alpha=%.3f: %f\n", alpha, critical_value);

    // Compare the test statistic with the critical value
    if (d > critical_value) {
        printf("Reject the null hypothesis: The sample does not follow the theoretical distribution.\n");
    } else {
        printf("Fail to reject the null hypothesis: The sample follows the theoretical distribution.\n");
    }
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(double*)a - *(double*)b);
}

int main() {
    // User input for the number of data points
    int n;
    printf("Enter the number of data points (N): ");
    scanf("%d", &n);

    // User input for the significance level (alpha)
    double alpha;
    printf("Enter the significance level (alpha): ");
    scanf("%lf", &alpha);

    // User input for the data points
    double data[n];
    printf("Enter the data points:\n");
    for (int i = 0; i < n; ++i) {
        printf("Data point %d: ", i + 1);
        scanf("%lf", &data[i]);
    }

    // Perform the KS test
    ksTest(data, n, alpha);

    // Additional printf statement
    printf("Name: Hari Prasad Gyawali, Symbol No: 26443/077\n");

    return 0;
}
