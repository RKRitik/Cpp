#include <pthread.h>
#include <thread>
#include <iostream>
using namespace std;

int counter = 0;
pthread_mutex_t counterLock;

void* count(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&counterLock);
        counter++;
        pthread_mutex_unlock(&counterLock);
    }
    return NULL;
}

int main() {
    unsigned int cores = thread::hardware_concurrency();
    std::cout << "Number of hardware threads: " << cores << std::endl;
    pthread_t threads[8];
    pthread_mutex_init(&counterLock, NULL);
    int ids[5];

    for (int i = 0; i < 2; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, count, &ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    cout << "final value " << counter;
    return 0;
}