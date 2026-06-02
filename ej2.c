#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val){

    unsigned char *pixeles;

    FILE *archivo;
    archivo = fopen(*filename, "r");


    // verifica que el archivo exista
    if (archivo == NULL) return NULL;

    fscanf(archivo, "%*[^\n]\n");
    fscanf(archivo, "%i %i", width, height);
    fscanf(archivo, "%i", max_val);


    // reserva memoria
    pixeles = (unsigned char*)malloc(*height * *width * sizeof(unsigned char));

    for(int i = 0; i < *height * *width; i++){
            fscanf(archivo, "%c", *(pixeles + i));
    }

    fclose(archivo);

    return pixeles;

}

void apply_threshold(unsigned char *pixels, int total, int threshold){

}

unsigned char *make_negative(unsigned char *pixels, int total){

}

void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val){

}

void print_stats(unsigned char *original, unsigned char *thresholded, int total){

}

int main(void){


    FILE *archivo;
    archivo = fopen("/home/chelo/Plataformas/Laboratorio-4/imagen.pgm", "r");

    if (archivo == NULL) return 0;

    unsigned char *pixeles;




    int width, height, max_val, threshold;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;

    fscanf(archivo, "%*[^\n]\n");
    fscanf(archivo, "%i %i", &width, &height);
    fscanf(archivo, "%i", &max_val);


    // reserva memoria
    pixeles = (unsigned char*)malloc(height * width * sizeof(unsigned char));

    for(int i = 0; i < height * width; i++){
            fscanf(archivo, "%c", (pixeles + i));
    }

    for(int i = 0; i < height * width; i++){
            printf("%c", *(pixeles + i));
    }

    fclose(archivo);

    return 0;
}