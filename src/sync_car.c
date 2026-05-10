#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



typedef struct Station {
    int passageiros;
    int assentos_livres;
    int passageiros_embarcados;
    pthread_mutex_t station_mutex;
    pthread_cond_t esperar_carro;  //condition para um passageiro esperar o próximo assento
    pthread_cond_t confirmar_saida;  //condition para um carro esperar todos os passageiros estarem prontos
} Station;


void station_init(Station *station){
    station->passageiros = 0;
    station->assentos_livres = 50;
    station->passageiros_embarcados = 0;

    pthread_mutex_init(&station->station_mutex, NULL);
    pthread_cond_init(&station->esperar_carro, NULL);
    pthread_cond_init(&station->confirmar_saida, NULL);

}

void station_wait_for_car(Station *station){
    pthread_mutex_lock(&station->station_mutex);
    station->passageiros++;

    while(station->assentos_livres == 0){
        pthread_cond_wait(&station->esperar_carro, &station->station_mutex);
    }

    station->assentos_livres--;
    pthread_mutex_unlock(&station->station_mutex);
}
