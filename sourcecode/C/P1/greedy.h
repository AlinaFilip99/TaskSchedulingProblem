#ifndef CODE_GREEDY
#define CODE_GREEDY

struct activity{
    int id;
    int time_start;//structura unei activitati care contine numarul de identificare a activitatii, timpul de start si timpul de finish
    int time_end;
};

void generate_activities(struct activity *activities, int no_activities, int i);//i are rolul de a indica cu ce fisier se va lucra
void print_activities_file(struct activity *activities, int no_activities, int i);//declaratiile functiilor existente in greedy.c
void sort_activities_by_end_time(struct activity *activities, int no_activities);
void greedy_file(struct activity *activities, int no_activities, int i);//i este transmis de functia main

#endif //CODE_GREEDY
