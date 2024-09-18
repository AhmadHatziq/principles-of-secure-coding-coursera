#include <stdio.h>
#include "fqlib.h"

int main() {
    QUEUE *myQueue;
    int size = -1;  // Small queue size
    int num;

    // Create a queue with a small size (e.g., 3)
    printf("Creating a queue of size %d...\n", size);
    qmanage(&myQueue, 1, size);

    // Add more elements than the queue size to trigger a crash
    printf("Adding integers 1, 2, 3 to the queue...\n");
    put_on_queue(myQueue, 1);
    put_on_queue(myQueue, 2);
    put_on_queue(myQueue, 3);

    // Attempt to add a 4th element (buffer overflow situation)
    printf("Adding integer 4 to the queue (expecting crash)...\n");
    put_on_queue(myQueue, 4);  // This will overflow the queue and may cause a crash

    // This will likely not be reached due to the crash
    printf("Removing elements from the queue...\n");
    while (myQueue->count > 0) {
        take_off_queue(myQueue, &num);
        printf("Removed: %d\n", num);
    }

    // Delete the queue (likely unreachable)
    printf("Deleting the queue...\n");
    qmanage(&myQueue, 0, 0);

    return 0;
}
