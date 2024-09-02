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
    int max, arraySize;
    srand(time(0));

    // take in user input
    printf("Size of array?\n");
    scanf("%d", &arraySize);
    printf("Max X & Y coordinate?\n");
    scanf("%d", &max);

    // changes if they are not in the designated range
    if(arraySize > max) arraySize = max;
    if(arraySize < 0) arraySize = 0;
    if(max > MAX_INT) max = MAX_INT;
    if(max < 0) max = DEFAULT;

    // creates new array, prints it
    struct point* values = createRandomPoints(arraySize, max);
    printPoints(values, arraySize);

    // frees memory
    free(values);
    system("pause");
    return 0;
}

struct point createRandomPoints(int size, int maxVal) {
    struct point* temp;
    temp = (struct point*)malloc(size * sizeof(struct point));

    for(int i = 0; i < size; i++) {

}
