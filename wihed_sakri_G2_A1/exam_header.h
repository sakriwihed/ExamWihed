#ifndef EXAM_HEADER_H_INCLUDED
#define EXAM_HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int id;
char fullname[10];
char status[10];
int age;

}patient;
typedef struct node node ;

typedef struct node
{
patient data;
struct node *next;
}node;
typedef struct node * listt;
typedef struct node * stackk;

void enter_patient(patient *p);
struct node *search_patient(listt l,int identifier);
listt add_patient(listt l,patient p);
void display_list(listt l);
int count_patients(listt l);
float calculate_average_age(listt l,int nb_patients);
void calculate_patient_percentage(listt l , int *nb_under_treatment,int *nb_recovered,int *nb_deceased,float *percentage_under_treatment);
listt delete_deceased_patients(listt l,char filename[]);
void push_patient(stackk*s,patient pat);
void pop_patient(stackk*s);
stackk push_patients_treatrecover(stackk s,listt l);




#endif // EXAM_HEADER_H_INCLUDED
