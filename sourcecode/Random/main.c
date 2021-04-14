#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, timp_start, timp_end;
    char temp_name_in[20];
    time_t t;
    srand((unsigned) time(&t));

    for(j=1;j<=10;j++)
        {
    sprintf(temp_name_in, "teste\\test_%d.in", j);
    FILE* test_in = fopen(temp_name_in, "wt");

        n=rand()%30;
        while(n<=0)
        {
            n=rand()%30;
        }
        fprintf(test_in, "%d\n", n);
        for(i=1; i<=n; i++)
        {
            timp_end=rand()%1440+1;
            while(timp_end<=0)
            {
                timp_end=rand()%1440+1;
            }
            timp_start=rand()%timp_end+1;
            while(time_start<0 || time_start=1440)
            {
                timp_start=rand()%timp_end+1;
            }
            fprintf(test_in, " %d ", timp_start);
            fprintf(test_in, "%d \n", timp_end);
        }

        fclose(test_in);
    }

    return 0;
}

