#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drunkardsWalk(int n) {
    int x = 0, y = 0;
    srand(time(NULL));

    for (int i = 0; i < n; ++i) {
        int direction = rand() % 4;

        switch (direction) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
        }
    }

    printf("Final position after %d steps: (%d, %d)\n", n, x, y);
}

int main() {
    int steps;
    printf("Enter the number of steps for the Drunkard's Walk: ");
    scanf("%d", &steps);

    drunkardsWalk(steps);

    // Additional printf statement
    printf("Name: Hari Prasad Gyawali, Symbol No: 26443/077\n");

    return 0;
}
