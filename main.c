/*
 * main.c
 *
 *  Created on: 27 Aug 2023
 *      Author: Rashad
 */


#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Clinical_Management_System.h"

void main()
{
    while (1)
    {
        u16 mode_choice;

        //--------------->> Mode Menu
        printf("\n\n--------------->> Welcome to Clinical Management System <<---------------\n\n");
        printf("Enter 1 for admin mode :\n");
        printf("Enter 2 for user mode :\n");
        printf("Enter 3 to exit the system :\n");
        printf("Your choice : ");

        scanf(" %d", &mode_choice);

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
            printf("\nWrong input\n");
            break;
        }
    }
}
