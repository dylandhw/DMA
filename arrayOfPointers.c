// test code for dynamic memory allocation of array of pointers to structs
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

struct point** createRandPoints(int size, int maxVal);
void print(struct point* array[], int size);

int main() {

    int max, arraySize;

    srand(time(0));

    // Read in user input.
    printf("How big do you want your array?\n");
    scanf("%d", &arraySize);
    printf("What is the maximum x or y coordinate you want?\n");
    scanf("%d", &max);

    // Changes user values if they are not in the designated range.
    if (arraySize < 0) arraySize = DEFAULT;
    if (arraySize > ABSOLUTE_MAX) arraySize = ABSOLUTE_MAX;
    if (max < 0) max = DEFAULT;
    if (max > MAX_INT) max = MAX_INT;

    // Create a new array and print it!
    struct point** values = createRandPoints(arraySize, max);
    print(values, arraySize);

    // Free the array memory; note that this time we loop through and free
    // each struct first, THEN free the array itself.
    int i;
    for (i=0; i<arraySize; i++)
        free(values[i]);
    free(values);


    system("pause");
    return 0;
}

struct point** createRandPoints(int size, int maxVal)  {

    // Allocate the correct amount of memory for the array.
    struct point** temp;
    temp = (struct point**)malloc(size*sizeof(struct point*));
    int i;

    // Allocate space for each point, then fill it with a random (x,y).
    for (i=0; i<size; i++) {

        // Allocate the space for this one struct here.
        temp[i] = (struct point*)malloc(sizeof(struct point));

        // Note the use of the array here, in filling in these values.
        temp[i]->x = 1 + rand()%maxVal;
        temp[i]->y = 1 + rand()%maxVal;
    }

    return temp;
}

void print(struct point* array[], int size) {
    int i;

    // Print all but the last, followed by a comma.
    for (i=0; i<size-1; i++)
        printf("(%d,%d), ", array[i]->x, array[i]->y);

    // Print the last without a comma!
    printf("(%d,%d).\n", array[size-1]->x, array[size-1]->y);
}
