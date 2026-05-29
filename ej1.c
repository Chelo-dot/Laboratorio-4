#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findLargestLine(int **matrix, int size, int *result){

}

void allocateMatrix(int ***matrix, int size){


}

void fillMatrix(int **matrix, int size){

    // General matriz random

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            *(*(matrix + i) + j) = rand()%2;
        }
    }

}

void printMatrix(int **matrix, int size){
    printf("Matriz (%dx%d) \n", size, size);

    for (int i = 0; i < size * size; i++){
        printf("%d", *(*matrix + i));


    }
            printf("\n");
    
    
    for (int i = 0; i < size; i ++){
        for (int j = 0; j < size; j++){
            printf("%d", *(*(matrix + i) + j));
        }

    
    }
}


void freeMatrix(int **matrix, int size){
    for(int i = 0; i < size; i++){
        free(*(matrix + i));
    }
    free(matrix);
}

int main(void){

    srand(time(NULL));

    int size, largestLine;
    int **matrix = NULL;

    size = 4;

    allocateMatrix(&matrix, size);

    fillMatrix(matrix, size);

    printMatrix(matrix, size);

    freeMatrix(matrix, size);



    return 0;
}