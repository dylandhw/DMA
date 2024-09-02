// test code for dynamic memory allocation with structs
// week 1 review for cs1 (data structs & alg.)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ABSOLUTE_MAX 100000
#define MAX_INT 32767
#define DEFAULT 10

struct point {
    int x;
    int y;
};

struct point* createRandomPoints(int size, int maxVal);
void printPoints(struct point array[], int size);

int main() {
    return 0;
}
