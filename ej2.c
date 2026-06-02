#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val){

    unsigned char *pixels;

    FILE *archivo;
    archivo = fopen("/home/chelo/Plataformas/Laboratorio-4/imagen.pgm", "r");


    // verifica que el archivo exista
    if (archivo == NULL) return NULL;

    fscanf(archivo, "%*[^\n]\n");
    fscanf(archivo, "%*[^\n]\n");
    // lee el tamano de la imagen
    fscanf(archivo, "%i %i", width, height);
    fscanf(archivo, "%i", max_val);


    // reserva memoria
    pixels = (unsigned char*)malloc(*height * *width * sizeof(unsigned char));

    
    //guarda los datos de cada pixel
    for(int i = 0; i < *height * *width; i++){
            fscanf(archivo, "%i", (pixels + i));
    }

    fclose(archivo);

    return pixels;

}

void apply_threshold(unsigned char *pixels, int total, int threshold){

    for(int i = 0; i < total; i++){
        if((int)*(pixels + i) >= threshold) *(pixels + i) = 255;
        else *(pixels + i) =  0;

    }

}

unsigned char *make_negative(unsigned char *pixels, int total){

}

void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val){

    FILE *archivo = fopen("threshold.pgm", "w");

    if (archivo == NULL) return;

    fprintf(archivo, "P2\n");
    fprintf(archivo, "%d %d\n", width, height);
    fprintf(archivo, "%d\n", max_val);
    for(int i = 0; i < width*height; i++){
            fprintf(archivo, "%i ", (int)*(pixels +i));
            if (i % width == 0) fprintf(archivo, "\n");
    }


}

void print_stats(unsigned char *original, unsigned char *thresholded, int total){

}

int main(void){

    char *filename = "/home/chelo/Plataformas/Laboratorio-4/imagen.pgm";

    int width, height, max_val, threshold;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;

    pixels = read_pgm("/home/chelo/Plataformas/Laboratorio-4/imagen.pgm", &width, &height, &max_val);

    int total = width*height;

    
    apply_threshold(pixels, total, 75);
    write_pgm("threshold.pgm", pixels, width, height, max_val);




    return 0;
}