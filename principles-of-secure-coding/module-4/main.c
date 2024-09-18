#include <stdio.h>
#include "qlib.h"

// Compile command:  gcc -o main main.c qlib.c
int main() {
    QTICKET q;  // Queue ticket
    int result;

    // Create a queue
    q = create_queue();
    if (q < 0) {
        printf("Error creating queue: %s\n", qe_errbuf);
        return 1;
    } else {
        printf("Queue created with ticket: %u\n", q);
    }

    // Add some elements to the queue
    result = put_on_queue(q, 10);
    if (result != QE_NONE) {
        printf("Error adding element to queue: %s\n", qe_errbuf);
        return 1;
    }
    result = put_on_queue(q, 20);
    if (result != QE_NONE) {
        printf("Error adding element to queue: %s\n", qe_errbuf);
        return 1;
    }
    result = put_on_queue(q, 30);
    if (result != QE_NONE) {
        printf("Error adding element to queue: %s\n", qe_errbuf);
        return 1;
    }

    printf("Added elements to queue.\n");

    printf("Queue elements:");    
    list_queue(q);


    // Remove elements from the queue
    int element;
    element = take_off_queue(q);
    if (element < 0) {
        printf("Error removing element from queue: %s\n", qe_errbuf);
        return 1;
    }
    printf("Removed element: %d\n", element);

    element = take_off_queue(q);
    if (element < 0) {
        printf("Error removing element from queue: %s\n", qe_errbuf);
        return 1;
    }
    printf("Removed element: %d\n", element);

    // Clean up and delete the queue
    result = delete_queue(q);
    if (result != QE_NONE) {
        printf("Error deleting queue: %s\n", qe_errbuf);
        return 1;
    }

    printf("Queue deleted successfully.\n");

    return 0;
}