#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "greedy.h"

int main()
{
    struct activity *activities;//declaratia structurii activity care se identifica in functie cu activities
    int no_activities, i;//varialule intregi :numarul de activitati, itertaorul i

     for(i=1; i<=10; i++)//contor pentru fisierele urilizate
    {
        char temp_name_in[20];
        char temp_name_out[20];

        sprintf(temp_name_in, "teste\\test_%d.in", i);//se specifica un de se gasesc fisierele
        sprintf(temp_name_out, "teste\\test_%d.out", i);

        FILE* test_in = fopen(temp_name_in, "r");//fisier deschis dor pentru citire
        FILE* test_out = fopen(temp_name_out, "wt");//fisier deschis pentru scriere, daca nu exista va fi creat (suprascriere)

        if(!test_in)
        {
            return -1;//se verifica daca fisierul in exista
        }

    fscanf(test_in, "%d",&no_activities);//se citeste numarul de activitati
    activities = malloc(no_activities*sizeof(struct activity));//se aloca spatiu pentru toate activitatile
    generate_activities(activities, no_activities, i);//apelul functiei de generare a activitatilor(citire)
    sort_activities_by_end_time(activities, no_activities);//apelul functiei de sortare a activivtatilor
    fprintf(test_out,"\n=== Sorted activities ===");//se scrie in fisier
    print_activities_file(activities, no_activities, i);//apelul functiei care printeaza activitatile sortate in fisier
    greedy_file(activities, no_activities, i);//apelul functie pentru alegerea solutiei optime a problemei

    fclose(test_in);//inchide fisierul
    fclose(test_out);//inchide fisierul
    }

    return 0;
}
