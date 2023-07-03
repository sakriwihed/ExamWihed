#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exam_header.h"

int main()
{
    int choice=0;
    float c;
    listt l;
    stackk st;
    patient p;
    int nb_under_treatment,nb_recovered,nb_deceased;
    float percentage_under_treatment;
    do{
    do{
        printf("-------------MENU----------------");
        printf("1-add a patient to the list \n");
        printf("2- display the patients in the list\n");
        printf("3-display the average age of the patients saved in the list \n");
        printf("4- display the percentage of patients whose health status is undertreatment\n");
        printf("5- push the patients under treatment followed by the recovered patients into a stack \n");

        printf("0- Quit \n");
        scanf("%d",&choice);
        }while(choice>5||choice<0);
        switch(choice)
        {
        case 1:
            enter_patient(&p);
            l=add_patient(l,p);
            break;

        case 2:
            display_list(l);

            break;

        case 3:
            c=calculate_average_age(l,count_patients(l));
            printf("the average age of the patients is %f.2\n",c);

            break;

        case 4:
            calculate_patient_percentage(l,&nb_under_treatment,&nb_recovered,&nb_deceased,&percentage_under_treatment);
            printf("the percentage of the patients whose health status is undertreatment is %f.2",percentage_under_treatment);
            break;

        case 5:
            st= push_patients_treatrecover(st,l);

            break;
        }
    }while(choice!=0);
    return 0;
}
