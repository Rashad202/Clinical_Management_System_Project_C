
#ifndef __CLINICAL_MANAGEMENT_SYSTEM_H__
#define __CLINICAL_MANAGEMENT_SYSTEM_H__

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


/*----------------------User defined types----------------------------------------*/

typedef enum 
{
    True,
    False,
    NOT_ENTERED = 0,
    admin_password = 1234,
    EMPTY = 0
} Enut_CMS;

struct patient_node 
{
    u8 name[20];
    u16 age;
    u8 gender;
    u16 id;
    struct patient_node *next;
};


//u16 reservations[] = {0 /*2pm to 2:30pm*/, 0 /*2:30pm to 3pm*/, 0 /*3pm to 3:30pm*/, 0 /*4pm to 4:30pm*/, 0 /*4:30pm to 5pm*/};

#endif /*__CLINICAL_MANAGEMENT_SYSTEM_H__*/