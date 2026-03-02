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

    // sort by arrival time, then PID
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].at > p[j+1].at ||
              (p[j].at==p[j+1].at &&
               strcmp(p[j].pid,p[j+1].pid)>0)){
                Process t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }

    float aw=0,at=0;

    p[0].wt=0;
    p[0].tat=p[0].bt;

    aw+=p[0].wt;
    at+=p[0].tat;

    for(int i=1;i<n;i++){
        p[i].wt=p[i-1].wt+p[i-1].bt;
        p[i].tat=p[i].wt+p[i].bt;

        aw+=p[i].wt;
        at+=p[i].tat;
    }

    aw/=n;
    at/=n;

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].wt);

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].tat);

    printf("Average Waiting Time: %.2f\n",aw);
    printf("Average Turnaround Time: %.2f",at);

    return 0;
}