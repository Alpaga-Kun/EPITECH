/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-team.bodzen
** File description:
** init
*/

#include "../includes/inc.h"

static pthread_mutex_t priv_villagers = PTHREAD_MUTEX_INITIALIZER;
static sem_t semdruid;
static sem_t semvillagers;
data_t data = {0};

void init(char **av)
{
    data.id = -1;
    data.nb_villagers = atol(av[1]);
    data.pot_size = atol(av[2]);
    data.pot_max = data.pot_size;
    data.nb_fights = atol(av[3]);
    data.nb_refills = atol(av[4]);
}

void *action_druid(void *content)
{
    (void)content;
    dstart();
    sem_wait(&semdruid);
    if (data.nb_refills > 0) {
        data.pot_size = data.pot_max;
        data.nb_refills--;
        drefill(data.nb_refills);
        dfinish();
    }
    sem_post(&semvillagers);
    return NULL;
}

void *action_villagers(void *content)
{
    int fighting = data.nb_fights;
    int id = *((int *)content);

    vilstart(id);
    pthread_mutex_lock(&priv_villagers);
    while (fighting > 0) {
        vdrink(id, data.pot_size);
        if (data.pot_size > 0) {
            data.pot_size--;
            fighting--;
            vfight(id, fighting);
        } else {
            vrefill(id);
            sem_post(&semdruid);
            sem_wait(&semvillagers);
        }
    }
    vfinish(id);
    pthread_mutex_unlock(&priv_villagers);
    pthread_mutex_destroy(&priv_villagers);
    return NULL;
}

int process(void)
{
    pthread_t people[data.nb_villagers + 1];
    sem_init(&semdruid, 0, 0);
    sem_init(&semvillagers, 0, 0);

    for (int i = 0; i <= data.nb_villagers; i++) {
        if (i == 0)
            pthread_create(&people[i], NULL, action_druid, NULL);
        else {
            pthread_create(&people[i], NULL, action_villagers, &data.id);
            data.id++;
        }
    }
    for (int j = 0; j != data.nb_villagers; j++)
        pthread_join(people[j], NULL);
    return (0);
}
