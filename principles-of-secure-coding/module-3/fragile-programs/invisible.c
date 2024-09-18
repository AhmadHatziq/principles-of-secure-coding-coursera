#include <stdio.h>
#include "fqlib.h"

int main() {
    QUEUE *myQueue;
    int num;

    // Initial size of the queue
    int initial_size = 5;
    int new_size = 3;

    // Create a queue with size 5
    printf("Creating a queue of size %d...\n", initial_size);
    qmanage(&myQueue, 1, initial_size);

    // Add some integers to the queue
    printf("Adding integers 1, 2, 3, 4, 5 to the queue...\n");
    put_on_queue(myQueue, 1);
    put_on_queue(myQueue, 2);
    put_on_queue(myQueue, 3);
    put_on_queue(myQueue, 4);
    put_on_queue(myQueue, 5);

    // Show current queue status
    printf("Current queue count: %d\n", myQueue->count);

    // Now, manually decrease the size of the queue
    printf("Decreasing the queue size from %d to %d...\n", initial_size, new_size);
    myQueue->size = new_size; // Forcefully decrease the size
    
    // Try removing all elements from the queue
    printf("Attempting to remove all elements from the queue...\n");
    while (myQueue->count > 0) {
        take_off_queue(myQueue, &num);
        printf("Removed: %d\n", num);
    }

    // Check if the queue still contains any invisible elements
    printf("Final queue count: %d\n", myQueue->count);

    // Delete the queue
    printf("Deleting the queue...\n");
    qmanage(&myQueue, 0, 0);

    return 0;
}
