#ifndef SYNC_CAR_H
#define SYNC_CAR_H


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct station {
    int passageiros;
    int assentos_livres;
    int passageiros_embarcados;
    pthread_mutex_t station_mutex;
    pthread_cond_t esperar_carro;  //condition para um passageiro esperar o próximo assento
    pthread_cond_t confirmar_saida;  //condition para um carro esperar todos os passageiros estarem prontos
} station;


void station_init(station *station);
void station_wait_for_car(station *station);
void station_load_car(station *station, int count);
void station_on_board(station *station);


#endif