#include <stdio.h>
#include <math.h>

// Function to calculate the mean of an array
double calculateMean(double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += data[i];
    }
    return sum / n;
}

// Function to calculate the autocorrelation coefficient at a given lag
double autocorrelation(int lag, double data[], int n) {
    double mean = calculateMean(data, n);
    double numerator = 0.0;
    double denominator1 = 0.0;
    double denominator2 = 0.0;

    for (int i = 0; i < n - lag; ++i) {
        numerator += (data[i] - mean) * (data[i + lag] - mean);
        denominator1 += pow(data[i] - mean, 2);
        denominator2 += pow(data[i + lag] - mean, 2);
    }

    return numerator / sqrt(denominator1 * denominator2);
}

int main() {
    // User input for the number of data points
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Array to store the time series data
    double data[n];

    // User input for the time series data
    printf("Enter the time series data:\n");
    for (int i = 0; i < n; ++i) {
        printf("Data point %d: ", i + 1);
        scanf("%lf", &data[i]);
    }

    // User input for the lag at which autocorrelation is to be tested
    int lag;
    printf("Enter the lag for autocorrelation test: ");
    scanf("%d", &lag);

    // Perform the autocorrelation test
    double autocorrelationCoefficient = autocorrelation(lag, data, n);

    // Print the autocorrelation coefficient
    printf("Autocorrelation Coefficient at lag %d: %f\n", lag, autocorrelationCoefficient);

    // Additional printf statement
    printf("Name: Hari Prasad Gyawali, Symbol No: 26443/077\n");

    return 0;
}
