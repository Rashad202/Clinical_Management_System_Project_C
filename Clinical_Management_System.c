
#include <stdio.h>                                          
#include <stdlib.h>  
#include "STD_TYPES.h"       
#include "Clinical_Management_System.h" 

struct patient_node *head = NULL;   
u32 list_length = 0;                
u32 entered_password = NOT_ENTERED; 

u16 reservations[5] ;
/*--------------------------Admin Mode--------------------------------------*/

void admin_mode() 
{
    u32 tries = 1;               
    u8 password_correct = False; 

    if (entered_password == 404) //Asking for password if it hasn't been entered yet
    {
        printf("\nPlease enter your password: ");
        scanf("%d", &entered_password);
    }

    while (tries < 4) 
    {

        if (entered_password == admin_password) 
        {
            /*------------------------------Admin Menu----------------------------*/


            password_correct = True; //Raising a flag for correct password
            u16 feature_choice;

            printf("\nEnter 1 for Adding new patient record\n"
                   "Enter 2 for Editing patient record\n"
                   "Enter 3 for Reserving a slot with the doctor\n"
                   "Enter 4 for Canceling reservation\n"
                   "Your choice: ");

            scanf(" %hu", &feature_choice);

            switch (feature_choice)
            {
            case 1:
                add_new_patient();
                break;

            case 2:
                edit_patient_record();
                break;

            case 3:
                doctor_reservation();
                break;

            case 4:
                cancel_reservation();
                break;

            default:
                printf("Wrong input\n\n");
                break;
            }
            break;
        }

        else if (tries < 3) 
        {
            password_correct = False; //Raising a flag for wrong password
            printf("Try again: ");
            scanf("%d", &entered_password);
        }

        tries++; 
    }

    if (password_correct == False) 
    {
        printf("\nIncorrect password for 3 times. No more tries\n");
        exit(0);
    }
}

void add_new_patient() 
{
    u8 unique_id = True; 

    if (list_length == EMPTY) 
    {

        head = (struct patient_node *)malloc(sizeof(struct patient_node)); 

        /*---------------------------- User data -----------------------------*/
        printf("\nEnter patient's name: ");
        scanf(" %s", &(head->name));
        printf("Enter patient's age: ");
        scanf(" %hu", &(head->age));
        printf("Enter patient's gender (m/f): ");
        scanf(" %c", &(head->gender));
        printf("Enter patient's id: ");
        scanf(" %hu", &(head->id));

        head->next = NULL; 
        list_length++;     
    }

    else
    {
        struct patient_node *current = (struct patient_node *)malloc(sizeof(struct patient_node)); 
        struct patient_node *ptr = head;                                                          

        /*---------------------------- User data -----------------------------*/
        printf("\nEnter patient's name: ");
        scanf(" %s", &(current->name));
        printf("Enter patient's age: ");
        scanf(" %hu", &(current->age));
        printf("Enter patient's gender (m/f): ");
        scanf(" %c", &(current->gender));
        printf("Enter patient's id: ");
        scanf(" %hu", &(current->id));

        /*-------------------Checking for unique_id using linear Searching algorithm------------------------------*/

        for (u8 i = 1; i <= list_length; i++)
        {
            if (current->id == ptr->id)
            {
                printf("Id is not unique\n");
                unique_id = False;
                printf("Enter patient's id: ");
                scanf(" %d", &(current->id));
                ptr = head;
                i = 0;
            }

            else
            {
                unique_id = True;
                ptr = ptr->next;
            }
        }

        ptr = head; 

        current->next = NULL; 
        while (ptr->next != NULL) 
        {
            ptr = ptr->next; 
        }
        ptr->next = current; 
        list_length++;      
    }

    printf("\nPatient Added!\n\n"); 
}

void edit_patient_record() 

{
    if (list_length == EMPTY) 
    {
        printf("\nNo patient records yet, Add a patient first\n\n");
    }

    else
    {
        struct patient_node *ptr = head;        
        struct patient_node *found_node = NULL; 

        u16 entered_id;      
        u8 id_found = False; 
        u16 edit_choice;     

        /*-------------------checking if entered ID exists-------------------------------*/
        while (id_found == False)
        {
            printf("Enter patient's id: ");
            scanf(" %hu", &entered_id);

            for (u8 i = 1; i <= list_length; i++) 
            {
                if (entered_id == ptr->id) 
                {
                    id_found = True;
                    found_node = ptr; 
                    break;            
                }

                else 
                {
                    id_found = False; 
                    ptr = ptr->next;  
                }
            }

            ptr = head; 

            if (id_found == False) 
            {
                printf("ID not found\n"); 
            }
        }

        /*-------------------Edit options-------------------------------*/

        while (edit_choice != 5)
        {
            printf("Enter 1 to edit patient's name\n"
                   "Enter 2 to edit patient's age\n"
                   "Enter 3 to edit patient's gender (m/f)\n"
                   "Enter 4 to edit patient's id\n"
                   "Enter 5 to go back\n"
                   "Your choice: ");

            scanf(" %hu", &edit_choice);

            switch (edit_choice)
            {
            case 1:
                printf("\nEnter patient's name: ");
                scanf(" %s", &(found_node->name));
                break;

            case 2:
                printf("Enter patient's age: ");
                scanf(" %hu", &(found_node->age));
                break;

            case 3:
                printf("Enter patient's gender (m/f): ");
                scanf(" %c", &(found_node->gender));
                break;

            case 4:
                printf("Enter patient's id: ");
                scanf(" %hu", &(found_node->id));
                break;

            default:
                printf("\nWrong input\n\n");
                break;
            }
            printf("\nData edited successfully\n\n"); 
        }
    }
}

void doctor_reservation() 
{
    if (list_length == EMPTY)
    {
        printf("\nNo patient records yet, Add a patient first\n\n");
    }
    else
    {
        struct patient_node *ptr = head;         
        struct patient_node *chosen_node = NULL; 

        u16 entered_id;     
        u8 id_found = False;
        u16 res_choice;    
        /*-------------------Printing out Avalivable Reservation Slots-------------------*/
        printf("\nAvalivable reservation slots: \n");

        if (reservations[0] == EMPTY)
        {
            printf("Enter 1 for (2pm to 2:30pm)\n");
        }
        if (reservations[1] == EMPTY)
        {
            printf("Enter 2 for (2:30pm to 3pm)\n");
        }
        if (reservations[2] == EMPTY)
        {
            printf("Enter 3 for (3pm to 3:30pm)\n");
        }
        if (reservations[3] == EMPTY)
        {
            printf("Enter 4 for (4pm to 4:30pm)\n");
        }
        if (reservations[4] == EMPTY)
        {
            printf("Enter 5 for (4:30pm to 5pm)\n");
        }

        //Admin reservation choice
        printf("Your choice: ");
        scanf(" %hu", &res_choice);

        while (reservations[res_choice - 1] != EMPTY) 
        {
            printf("Slot not empty\n");
            printf("choose another slot: ");
            scanf(" %d", &res_choice);
        }

        while (id_found == False)
        {
            printf("Enter patient's id: ");
            scanf(" %hu", &entered_id);

            for (u8 i = 1; i <= list_length; i++) 
            {
                if (entered_id == ptr->id) 
                {
                    id_found = True;   
                    chosen_node = ptr; 
                    break;
                }

                else
                {
                    id_found = False; 
                    ptr = ptr->next;  
                }
            }

            ptr = head; 

            if (id_found == False) 
            {
                printf("ID not found\n");
            }
        }

        reservations[res_choice - 1] = chosen_node->id; 
    }
    printf("\nSlot reserved successfully\n\n"); 
}

void cancel_reservation() 
{
    if (list_length == EMPTY) 
    {
        printf("\nNo patient records yet, Add a patient first\n\n");
    }
    else
    {
        u16 entered_id;        
        u16 res_found = False; 

        printf("Enter patient's id: ");
        scanf(" %hu", &entered_id);

        for (u16 i = 0; i <= 4; i++) 
        {
            if (entered_id == reservations[i]) 
            {
                reservations[i] = EMPTY;                  
                printf("\nReservation deleted successfully\n\n"); 
                res_found = True;
            }
        }
        if (res_found == False) 
        {
            printf("\nNo reservations found for entered id\n\n"); 
        }
    }
}

/*--------------------------User Mode--------------------------------------*/

void user_mode() 
{
    u16 feature_choice; 

    /*-----------------------User main menu-----------------------------*/

    printf("\nEnter 1 for Viewing patient record\n"
           "Enter 2 for Viewing today's reservations.\n"
           "Your choice: ");

    scanf(" %hu", &feature_choice);

    switch (feature_choice)
    {
    case 1:
        view_patient_record();
        break;

    case 2:
        view_today_reservation();
        break;

    default:
        printf("Wrong input\n\n");
        break;
    }
}

void view_patient_record() 
{
    if (list_length == EMPTY) 
    {
        printf("\nNo patient records yet, Add a patient first\n\n"); 
    }

    else
    {
        struct patient_node *ptr = head;        
        struct patient_node *found_node = NULL; 

        u16 entered_id;      
        u8 id_found = False; 

        while (id_found == False) 
        {
            printf("Enter patient's id: ");
            scanf(" %hu", &entered_id);

            for (u8 i = 1; i <= list_length; i++) 
            {
                if (entered_id == ptr->id) 
                {
                    id_found = True;  
                    found_node = ptr; 
                    break;
                }

                else 
                {
                    id_found = False; 
                    ptr = ptr->next;  
                }
            }

            ptr = head; 

            if (id_found == False) 
            {
                printf("ID not found\n"); 
            }
        }

        /*--------------------------Printing patient record-------------------------------------*/

        printf("\n-----------------------\n"
               "Patient record:\n"
               "Name:   %s\n"
               "Age:    %hu\n"
               "Gender: %c\n"
               "ID:     %hu\n"
               "-----------------------\n\n",
               found_node->name, found_node->age, found_node->gender, found_node->id);
    }
}

void view_today_reservation()
{
    u8 empty_reservation_num = EMPTY; 

    for (u8 i = 0; i <= 4; i++) 
    {
        if (reservations[i] == EMPTY)
        {
            empty_reservation_num++;
        }
    }

    /*-----------------------Printing reserved slots--------------------*/

    if (reservations[0] != EMPTY)
    {
        printf("\n(2pm to 2:30pm), Patient ID: %hu\n", reservations[0]);
    }
    if (reservations[1] != EMPTY)
    {
        printf(" (2:30pm to 3pm), Patient ID: %hu\n", reservations[1]);
    }
    if (reservations[2] != EMPTY)
    {
        printf(" (3pm to 3:30pm), Patient ID: %hu\n", reservations[2]);
    }
    if (reservations[3] != EMPTY)
    {
        printf(" (4pm to 4:30pm), Patient ID: %hu\n", reservations[3]);
    }
    if (reservations[4] != EMPTY)
    {
        printf(" (4:30pm to 5pm), Patient ID: %hu\n\n", reservations[4]);
    }

    if (empty_reservation_num == 5) 
    {
        printf("\nThere are no reservations\n\n");
    }
    else
    {
        printf("\n\n"); 
    }
}