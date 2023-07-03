#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exam_header.h"


void enter_patient(patient *p)
{   
    printf("enter the identifier of the patient\n");
    scanf("%d",&p->id);
    
    printf("enter the name of the patient\n");
    fflush(stdin);
    gets(p->fullname);
    printf("enter the status of the patient\n");
    fflush(stdin);
    gets(p->status);
    printf("enter the age of the patient\n");
    scanf("%d",&p->age);

}
struct node *search_patient(listt l,int identifier)
{

int found=0;
struct node* p=l,*result=NULL;

    while(p!=NULL && found==0)
    {
        if(p->data.id==identifier){
            found=1;
            result=p;
        }
    }
return result;
}
listt add_patient(listt l,patient p)
{
	listt newn;
	newn=malloc(sizeof( struct node));
	newn->data=p;
	newn->next=NULL;
	if(l==NULL)
	{
		l=newn;
	}
	else
	{
		newn->next=l;
      	l=newn;
	}
	return l;
}
void display_list(listt l)
{
	listt tmp=NULL;
	tmp=l;
	if(l==NULL)
		printf("empty ");
	else
   	{
       	while(tmp!=NULL)
        	{
            	printf("%d %s %s %d ",tmp->data.id,tmp->data.fullname,tmp->data.status,tmp->data.age);
            	tmp=tmp->next;
       	}
   	}
}
int count_patients(listt l)
{
   listt tmp=NULL;
	tmp=l;
	int num=0;
	while(tmp!=NULL)
        	{
            	num++;
            	tmp=tmp->next;
            }
   	return num;
}
float calculate_average_age(listt l,int nb_patients)
{
    listt tmp=l;
    float result;
    if (tmp==NULL)
        result=(float)0;
    else{
        result=calculate_average_age(tmp,nb_patients);
        tmp=tmp->next;
    }
   return result;
}
void calculate_patient_percentage(listt l , int *nb_under_treatment,int *nb_recovered,int *nb_deceased,float *percentage_under_treatment)
{
   *nb_under_treatment=0;*nb_recovered=0;*nb_deceased=0;*percentage_under_treatment =0;
    listt tmp=NULL;
	tmp=l;
	while(tmp!=NULL)
        	{   if (strcmp(tmp->data.status,"undertreatment")==0)
                    *nb_under_treatment++;
                else{
                    if(strcmp(tmp->data.status,"recovered")==0)
                        *nb_recovered++;
                    else
                        *nb_deceased++;
                    }
            tmp=tmp->next;
            }
  *percentage_under_treatment=(float)(*nb_under_treatment/count_patients(l));

}

listt delete_deceased_patients(listt l,char filename[])
{
struct node *del,*prev,*current;
FILE *f=NULL;
f=fopen("filename.txt","w");
while((l!=NULL)&&(strcmp(l->data.status,"deceased")==0))
{
    del=l;
    if (f!=NULL)
        fprintf(f,"%d %s %s %d \n",del->data.id,del->data.fullname,del->data.status,del->data.age);
    l=l->next;
    free(del);
}
if (l!=NULL){
    prev=l;
    current=l->next;
    while(current!=NULL){
        while (current!=NULL&& strcmp(current->data.status,"deceased")==0)
        {
        del=current;
        if (f!=NULL)
            fprintf(f,"%d %s %s %d \n",del->data.id,del->data.fullname,del->data.status,del->data.age);
        current=current->next;
        prev->next=current;
        free(del);
        }
    if (current!=NULL)
    {
        prev=current;
        current=current->next;
    }
    }
}

fclose(f);
return l;

}
void push_patient(stackk*s,patient pat)
{
    stackk nw=NULL;
    nw=malloc(sizeof(struct node));
    nw->data=pat;
    nw->next=*s;
    *s=nw;
}
void pop_patient(stackk*s)
{
    stackk del;
	if(s!=NULL)
   	{
            del=s;
     		s=s->next;
     		free(del);
   	}
	else
		printf("empty ");
}

stackk push_patients_treat_recov(stackk s,listt l)
{
    char filename[100];

    l=delete_deceased_patients(l,filename);
    listt tmp=NULL;
	tmp=l;
	if(l==NULL)
		printf("empty ");
	else
   	{
       	while(tmp!=NULL)
        	{
            	if (strcmp(tmp->data.status,"undertreatment")==0)
                {
                    push_patient(&s,tmp->data);
                }
            	tmp=tmp->next;
            }
        tmp=l;
        while(tmp!=NULL)
        	{
            	if (strcmp(tmp->data.status,"recovered")==0)
                {
                    push_patient(&s,tmp->data);
                }
            	tmp=tmp->next;
            }

   	}
    return s;
}

