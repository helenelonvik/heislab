#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "light.h"
#include "logic.h"
#include "order.h"
#include "door.h"


static void sigint_handler(int sig){
    (void)(sig);
    printf("Terminating elevator to heaven --> going to hell\n");
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    exit(0);
}


int main(){
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
    
    signal(SIGINT, sigint_handler);

    printf("=== Elevator to heaven, by Lønvik and Veglo ===\n");

    start_condition();

    while(1){
	   order_handling();

    }
} 
