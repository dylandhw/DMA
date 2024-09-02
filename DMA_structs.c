// test code for dynamic memory allocation with structs
// week 1 review for cs1 (data structs & alg.)

/* NOTES
------------------------------------------------------------------------------------------------------------------------

Line 16: struct point* createRandomPoints(int size, int maxVal);
'struct point*' of return type 'struct point,' since we are returning a pointer
it is 'struct point*'

Line 47: temp = (struct point*)malloc(size*sizeof(struct point));
Things of note: dynamically allocates memory for an array of struct points
casting to type 'struct point*' which is a pointer to 'struct point'
temp is a pointer to this instance of struct point

Other: remember to always free memory
*/

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

struct point* createRandomPoints(int size, int maxVal) {
    struct point* temp;
    temp = (struct point*)malloc(size * sizeof(struct point));

    for(int i = 0; i < size; i++) {
        temp[i].x = 1 + rand()%maxVal; // fills in each coordinate within desired range (1, maxVal | inclusive)
        temp[i].y = 1 + rand()%maxVal;
    }
    return temp;
}

void printPoints(struct point array[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d, %d\n", array[i].x, array[i].y);
    printf("(%d, %d)\n", array[size-1].x, array[size-1].y);
}

