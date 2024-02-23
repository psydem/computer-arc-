#include <stdio.h>

#define CPU 0
#define MEMORY 1
#define IO 2

int main() {
    int bus;

    bus = CPU;
    printf("CPU requesting access to the bus...\n");
    if (bus == MEMORY) {
        printf("Memory is waiting while CPU uses the bus.\n");
    }
 
    else if (bus == IO) {
        printf("IO is waiting while CPU uses the bus.\n");
    }
    
    else {
        printf("CPU is using the bus.\n");
    }

    bus = MEMORY;
    printf("Memory requesting access to the bus...\n");

    if (bus == CPU) {
        printf("CPU is waiting while Memory uses the bus.\n");
    }

    else if (bus == IO) {
        printf("IO is using the bus while Memory waits.\n");
    }
    else {
        printf("Memory is using the bus.\n");
    }

    bus = IO;
    printf("IO requesting access to the bus...\n");
    if (bus == CPU) {
        printf("CPU is using the bus while IO waits.\n");
    }
    else if (bus == MEMORY) {
        printf("Memory is using the bus while IO waits.\n");
    }
    else {
        printf("IO is using the bus.\n");
    }
    return 0;
}
