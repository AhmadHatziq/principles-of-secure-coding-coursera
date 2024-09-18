#include <stdio.h>
#include "fqlib.h"

int main() {
    QUEUE *myQueue;
    int size = 5;  // Set the size of the queue
    int num;

    // Create a queue
    printf("Creating a queue of size %d...\n", size);
    qmanage(&myQueue, 1, size);

    // Add some integers to the queue
    printf("Adding integers 10, 20, 30 to the queue...\n");
    put_on_queue(myQueue, 10);
    put_on_queue(myQueue, 20);
    put_on_queue(myQueue, 30);

    // Take one integer off the queue
    printf("Removing an integer from the queue...\n");
    take_off_queue(myQueue, &num);
    printf("Removed: %d\n", num);

    // Add more integers to the queue
    printf("Adding integers 40, 50 to the queue...\n");
    put_on_queue(myQueue, 40);
    put_on_queue(myQueue, 50);

    // Take off all elements from the queue
    printf("Removing all elements from the queue...\n");
    while (myQueue->count > 0) {
        take_off_queue(myQueue, &num);
        printf("Removed: %d\n", num);
    }

    // Delete the queue
    printf("Deleting the queue...\n");
    qmanage(&myQueue, 0, 0);

    return 0;
}
