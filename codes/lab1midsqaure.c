#include<stdio.h>

int generateRandom(int xi, int a, int c, int m) {
    return (a * xi + c) % m;
}

int main() {
    int xi = 27;
    int a = 17;
    int c = 43;
    int m = 100;
    int RandNum[m];

    printf("The random numbers are: \n");

    for (int i = 0; i < 2 * m; i++) {
        RandNum[i % m] = generateRandom(xi, a, c, m);
        xi = RandNum[i % m];
        printf("%d \n", RandNum[i % m]);

        if (i > 0 && RandNum[i % m] == RandNum[0]) {
            printf("Now the pattern repeats.\n");
            break;
        }
    }

    // Additional printf statement
    printf("Name: Hari Prasad Gyawali, Symbol No: 26443/077\n");

    return 0;
}
