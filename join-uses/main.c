#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int contador = 0;
int cantidad_sumadores = 1;
int cantidad_duplicadores = 1;

void sumar (int id){
    contador++;
    printf("Sumador %d: contador = %d", id, contador);
}
void multiplicar (int id){
    contador = contador * 2;
    printf("Duplicador %d: contador = %d", id, contador);
}
void crear_hilos () {
    for (int i = 0; i < cantidad_sumadores; i++) {
        pthread_t * sumador = malloc(sizeof(pthread_t));
        pthread_create(sumador, NULL, sumar, i+1);
        pthread_detach(sumador);
    }
    for (int i = 0; i < cantidad_duplicadores; i++) {
        pthread_t * multiplicador = malloc(sizeof(pthread_t));
        pthread_create(multiplicador, NULL, multiplicar, i+1);
        pthread_detach(multiplicador);
    }
}
int main() {
    crear_hilos();
    while(1){
        sleep(1);
    }
}
