#include <stdio.h>      
#include <stdlib.h>                                    
#include "STD_TYPES.h"       
#include "Clinical_Management_System.h" 

void main()
{
    while (1) 
    {
        u16 mode_choice; 

        /*----------------------------Mode Menu---------------------*/

        printf("Enter 1 for admin mode\n"
               "Enter 2 for user mode\n"
               "Enter 3 to exit the system\n"
               "Your choice: ");

        scanf(" %hu", &mode_choice);

        switch (mode_choice)
        {
        case 1:
            admin_mode();
            break;

        case 2:
            user_mode();
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Wrong input\n\n");
            break;
        }
    }
}
