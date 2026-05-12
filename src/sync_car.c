
#include "sync_car.h"


void station_init(station *station){
    station->passageiros = 0;
    station->assentos_livres = 0;
    station->passageiros_embarcados = 0;

    pthread_mutex_init(&station->station_mutex, NULL);
    pthread_cond_init(&station->esperar_carro, NULL);
    pthread_cond_init(&station->confirmar_saida, NULL);

}

void station_wait_for_car(station *station){
    pthread_mutex_lock(&station->station_mutex);
    station->passageiros++;

    while(station->assentos_livres == 0){
        pthread_cond_wait(&station->esperar_carro, &station->station_mutex);
    }

    station->assentos_livres--;
    station->passageiros--;
    pthread_mutex_unlock(&station->station_mutex);
}


void station_load_car(station *station, int count){  //count é o número de vagas para cada vagão
    int alocados = count;
    pthread_mutex_lock(&station->station_mutex);
    if (count == 0){
        pthread_mutex_unlock(&station->station_mutex);
        return;
    }
    
    if (station->passageiros > count){
        alocados = count;
    }else {
        alocados = station->passageiros;
    }

    station->assentos_livres = count;
    pthread_cond_broadcast(&station->esperar_carro);

    while(station->passageiros_embarcados < alocados){
        pthread_cond_wait(&station->confirmar_saida, &station->station_mutex);
    }

    station->assentos_livres = 0;
    station->passageiros_embarcados = 0;
    pthread_mutex_unlock(&station->station_mutex);

}

void station_on_board(station *station){
    pthread_mutex_lock(&station->station_mutex);
    station->passageiros_embarcados++;
    pthread_cond_signal(&station->confirmar_saida);
    pthread_mutex_unlock(&station->station_mutex);
}
