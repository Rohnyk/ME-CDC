#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_num=0;
pthread_mutex_t t_mutex;

void *print_even_nos(void *ptr);
void *print_odd_nos(void *ptr);


int main (
        void)
{
    pthread_t tid[2];

    pthread_create(&tid[0], 0, &print_even_nos, 0);
    pthread_create(&tid[1], 0, &print_odd_nos, 0);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}


void *print_even_nos(
        void *ptr)
{
    while (1) {
        pthread_mutex_lock(&t_mutex);
        if (shared_num > 100) {
            pthread_mutex_unlock(&t_mutex);
            break;
        }

        if ((shared_num % 2)==0) {
            printf("even thread = [%d]\n", shared_num);
            shared_num++;
        }
        pthread_mutex_unlock(&t_mutex);
    };

    return NULL;
}


void *print_odd_nos(
        void *ptr)
{
    while (1) {
        pthread_mutex_lock(&t_mutex);
        if (shared_num > 100) {
            pthread_mutex_unlock(&t_mutex);
            break;
        }

        if ((shared_num % 2) == 1) {
            printf("odd thread = [%d]\n", shared_num);
            shared_num++;
        }
        pthread_mutex_unlock(&t_mutex);
    };

    return NULL;
}
