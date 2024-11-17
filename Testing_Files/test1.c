 #include <stdio.h>
#include <pthread.h>

// Structure to pass the range of numbers to each thread
typedef struct {
    int start;
    int end;
} Range;

// Thread function to count from start to end
void* count(void* arg) {
    Range* range = (Range*) arg;
    
    for (int i = range->start; i <= range->end; i++) {
        printf("Thread %d counting: %d\n", range->start / 25 + 1, i);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    Range ranges[4] = {
        {1, 25},   // Thread 1: Count from 1 to 25
        {26, 50},  // Thread 2: Count from 26 to 50
        {51, 75},  // Thread 3: Count from 51 to 75
        {76, 100}  // Thread 4: Count from 76 to 100
    };
    
    // Create threads for each range
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, count, (void*)&ranges[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished counting.\n");
    
    return 0;
}