
/*
 * Clinical_Management_System.h
 *
 *  Created on: 27 Aug 2023
 *      Author: Rashad
 */

#ifndef CLINICAL_MANAGEMENT_SYSTEM_H_
#define CLINICAL_MANAGEMENT_SYSTEM_H_

#include "STD_TYPES.h"

/*--------------------------Funtions Prototypes----------------------------------*/

void admin_mode();


void add_new_patient();


void edit_patient_record();


void doctor_reservation();


void cancel_reservation();


void user_mode();


void view_patient_record();


void view_today_reservation();


//------------------>> User defined types

typedef enum
{
    True,
    False,
    NOT_ENTERED = 4,
    admin_password = 1234,
    EMPTY = 0
} Check_Status_CMS;

struct patient_node
{
    u8 name[20];
    u16 age;
    u8 gender;
    u16 id;
    struct patient_node *next;
};






#endif /* CLINICAL_MANAGEMENT_SYSTEM_H_ */
