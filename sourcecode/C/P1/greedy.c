#include <stdio.h>
#include <stdlib.h>
#include "greedy.h"

void generate_activities(struct activity *activities, int no_activities,int i){//algoritm oentru generarea activitatilor (citirea lor din fisierul de intrare)
    FILE* test_in;
    int iterator;
    char temp_name_in[20];

    sprintf(temp_name_in, "teste\\test_%d.in", i);

    test_in=fopen(temp_name_in, "r");//fisierul este doar citit iar daca nu exista nu va fi creat

    fscanf(test_in,"%d", &no_activities);//se citeste numarul de activitati

    for(iterator = 0; iterator < no_activities; iterator++){//reprezinta fiecare activitate (0, 1....)
        activities[iterator].id = iterator;//id-ul activitatii este reprezentat de numarul ei in lista initiala
        fscanf(test_in, "%d", &activities[iterator].time_start);//citirea din fisier a timpului de start si introducerea in structura
        fscanf(test_in, "%d", &activities[iterator].time_end);//citirea din fisier a timpului de finish si introducerea in structura activitatii
    }
    fclose(test_in);
}

void print_activities_file(struct activity *activities, int no_activities, int i){//printarea listei de activitati in fisier (parametrul i indica fisierul utilizat)
    FILE* test_out;
    int iterator;
    char temp_name_out[20];
    sprintf(temp_name_out, "teste\\test_%d.out", i);

    test_out=fopen(temp_name_out, "at");//se scrie in continuarea textului deja existent in fisier

    fprintf(test_out,"\n Activities:");//se scrie in fisier
    for (iterator = 0; iterator < no_activities ; iterator++) {//contorul activitatilor
        fprintf(test_out,"\n id: %d time start: %d time end: %d ",activities[iterator].id, activities[iterator].time_start, activities[iterator].time_end);//scrierea in fisier a datelor referitoare la fiecare activitate
    }
}

void sort_activities_by_end_time(struct activity *activities, int no_activities){//sortarea activitatilor in functie de timpul de finish
    int iterator_1;
    int iterator_2;
    int index_max;//indexul unde se gaseste timpul de finish maxim
    int aux_time_start;
    int aux_id;
    int aux_time_end;

    for(iterator_1 = 0; iterator_1 < no_activities - 1; iterator_1++){
        index_max = iterator_1;//iteratorul maximului ia valoarea primului elem  apoi al 2-lea....
        for(iterator_2 = iterator_1 + 1; iterator_2 < no_activities; iterator_2++){//compararea se face cu elementele din fata elementului la care ne aflam
            if ( activities[index_max].time_end > activities[iterator_2].time_end){//daca se gaseste un timp mai mic decat timpul maxim atunci acel timp devine maxim
                index_max = iterator_2;
            }
        }
        if (index_max != iterator_1){//daca indexul maximului s-a modificat se face interschimbarea activitatilor

            aux_time_start = activities[index_max].time_start;
            aux_id = activities[index_max].id;//auxiliarele primesc valorile corespunzatoare ale activitatii maxime
            aux_time_end = activities[index_max].time_end;

            activities[index_max].time_start = activities[iterator_1].time_start;
            activities[index_max].id = activities[iterator_1].id;//se interschimba elementele activitatii maxime cu cea la care ne aflam
            activities[index_max].time_end = activities[iterator_1].time_end;

            activities[iterator_1].time_start = aux_time_start;
            activities[iterator_1].id = aux_id;//activitatea curenta primeste elementele de structura ale celei maxime
            activities[iterator_1].time_end = aux_time_end;
        }
    }
}

void greedy_file(struct activity *activities, int no_activities, int i)//algoritmul de determinare a solutiei optime
{
    FILE* test_out;
    int iterator_1;
    int iterator_2=2;
    int ultim=0;
    char temp_name_out[20];
    sprintf(temp_name_out, "teste\\test_%d.out", i);

    test_out=fopen(temp_name_out, "at");

    fprintf(test_out, "\nSpectacolul nr 1 (id: %d) incepe la %d %d si se termina la %d %d", activities[0].id, activities[0].time_start/60, activities[0].time_start%60, activities[0].time_end/60, activities[0].time_end%60);
//se scrie in fisier prima activitate care se termina cel mai devreme deci ramane destul timp pentru celelelte
//timpurile sunt convertite din minute in ore si minute prin impartirea la 60 de minute cat are o ora si determinarea restului de minute ramase
    for(iterator_1=1;iterator_1<no_activities;iterator_1++)//se compara pe rand activitatile cu prima scrisa
    {
        if(activities[iterator_1].time_start>=activities[ultim].time_end)
        {
            fprintf(test_out,"\nSpectacolul nr %d (id: %d) incepe la %d %d si se termina la %d %d", iterator_2, activities[iterator_1].id, activities[iterator_1].time_start/60, activities[iterator_1].time_start%60, activities[iterator_1].time_end/60, activities[iterator_1].time_end%60);
            //daca timpul de start al unei activitati este mai mare decat cel de finish a ultimei activitati luate in considerere
            //se ia in considereare prima activitate gasita in lista cati aceasta se termina cel mai devreme dintre toate variantele posibile
            //datorita modului lor de aranjare si se scrie in fisier
            //se transforma timpul din minute in ore si minute
            iterator_2++;
            ultim=iterator_1;//activitatea scrisa devine ultima activitate luata in considereare
        }
    }
}
