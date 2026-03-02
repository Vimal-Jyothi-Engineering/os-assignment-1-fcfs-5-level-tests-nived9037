#include <stdio.h>
#include <string.h>

typedef struct{
    char pid[10];
    int at, bt, wt, tat;
} Process;

int main(){

    int n;
    scanf("%d",&n);

    Process p[n];

    for(int i=0;i<n;i++)
        scanf("%s%d%d",p[i].pid,&p[i].at,&p[i].bt);

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].at > p[j+1].at ||
              (p[j].at==p[j+1].at &&
               strcmp(p[j].pid,p[j+1].pid)>0)){
                Process t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }

    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    for(int i=0;i<n;i++){

        int start_time = current_time;

        if(start_time < p[i].at)
            start_time = p[i].at;

        p[i].wt = start_time;
        p[i].tat = start_time + p[i].bt;

        current_time = p[i].tat;

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    float avg_wt = total_wt/n;
    float avg_tat = total_tat/n;

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].wt);

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].tat);

    printf("Average Waiting Time: %.2f\n",avg_wt);
    printf("Average Turnaround Time: %.2f",avg_tat);

    return 0;
}
