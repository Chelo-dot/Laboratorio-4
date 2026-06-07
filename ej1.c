#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findLargestLine(int **matrix, int size, int *result){

    int unos = 1;
    int anterior = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){

            if (*(*(matrix + i) + j) == 1 && anterior){
                unos ++;
                if (unos > *result) *result = unos;
            }

            else if(*(*(matrix + i) + j) == 1) anterior = 1;
            
            else {
                anterior = 0;
                unos = 1;
            }
        }
    }

}

void allocateMatrix(int ***matrix, int size){

    *matrix = (int **)malloc( size * sizeof(int*) );

    for(int i = 0; i < size; i++){
        *(*matrix + i) = (int *)malloc(size * sizeof(int));
    }

}

void fillMatrix(int **matrix, int size){

    // Generar matriz random

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            *(*(matrix + i) + j) = rand()%2;
        }
    }

}

void printMatrix(int **matrix, int size){
    printf("Matriz (%dx%d) \n", size, size);
    
    
    
    for (int i = 0; i < size; i ++){
        for (int j = 0; j < size; j++){
            printf("%d", *(*(matrix + i) + j));
        }

    printf("\n");

    
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
    largestLine = 1; 

    printf("Ingrese el tamanoo de la matriz:");
    scanf("%d", &size);

    allocateMatrix(&matrix, size);

    fillMatrix(matrix, size);

    printMatrix(matrix, size);

    findLargestLine(matrix, size, &largestLine);

    freeMatrix(matrix, size);
    
    printf("El tamanoo de la secuencia de 1s mas grande es: %d\n",largestLine);

    return 0;
}