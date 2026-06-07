#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val){

    unsigned char *pixels;

    FILE *archivo;
    archivo = fopen(filename, "r");


    // verifica que el archivo exista
    if (archivo == NULL) return NULL;

    fscanf(archivo, "%*[^\n]\n");

    // Se salta una segunda linea en caso de comentarios
    // fscanf(archivo, "%*[^\n]\n");


    // lee el tamano de la imagen
    fscanf(archivo, "%i %i", width, height);
    fscanf(archivo, "%i", max_val);


    // reserva memoria
    pixels = (unsigned char*)malloc(*height * *width * sizeof(unsigned char));
    if (pixels == NULL) return NULL;

    
    // guarda los datos de cada pixel
    for(int i = 0; i < *height * *width; i++){
            fscanf(archivo, "%hhu", (pixels + i));
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

    unsigned char *negative;
    negative = (unsigned char*)malloc(total * sizeof(unsigned char));

    if(negative == NULL) {
        printf("No se pudo encontrar un archivo");
        return NULL;
    }

    for(int i = 0; i < total; i++){
        *(negative + i) = 255 - *(pixels + i);
    }

    return negative;
}

void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val){

    FILE *archivo = fopen(filename, "w");

    if (archivo == NULL) return;

    fprintf(archivo, "P2\n");
    fprintf(archivo, "%d %d\n", width, height);
    fprintf(archivo, "%d\n", max_val);
    for(int i = 0; i < width*height; i++){
        fprintf(archivo, "%i ", (int)*(pixels +i));   
    }

    fclose(archivo);

}

void print_stats(unsigned char *original, unsigned char *thresholded, int total){

    int prom = 0;
    int blanco = 0;
    int negro = 0;

    for(int i = 0; i < total; i++){
        prom += (int)*(original + i);
        if((int)*(thresholded + i) == 0) negro ++;
        else blanco ++;
    }

    printf("Cantidad de pixeles blancos: %d\nCantidad de pixeles negros: %d\nValor promedio de los pixeles: %d\n", blanco, negro, prom/total);

}

int main(void){

    const char *filename = "input.pgm";

    int width, height, max_val, threshold;
    unsigned char *original = NULL;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;

    // leer archivo
    original = read_pgm(filename, &width, &height, &max_val);
    if(original == NULL){
        printf("Erro al abrir el archivo");
        return 1;
    }
    int total = width*height;

    // copia original en pixels
    pixels = (unsigned char*)malloc(total * sizeof(unsigned char));
    for(int i = 0; i < total; i++){
        *(pixels + i) = *(original + i);
    }

    // aplicar filtros
    negative = make_negative(pixels, total);
    if(negative == NULL) {
        printf("Error al guardar memoria");
        return 1;
    }

    printf("Ingrese el valor del threshold que desea aplicar: ");
    scanf("%i", &threshold);
    apply_threshold(pixels, total, threshold);

    // guardar archivos
    write_pgm("output_threshold.pgm", pixels, width, height, max_val);
    write_pgm("output_negative.pgm", negative, width, height, max_val);

    print_stats(original, pixels, total);

    // liberar espacio
    free(original);
    free(pixels);
    free(negative);

    return 0;
}
