// test code for dynamic memory allocation of array of pointers to structs
// week 1 review for cs1 (data structs & alg.)

#include <stdio.h>
#include <time.h>

#define ABSOLUTE_MAX 100000
#define MAX_INT 32767
#define DEFAULT 10

struct point {
    int x;
    int y;
};

struct point** createRandPoints(int size, int maxVal);
void print(struct point* array[], int size);
