#include <stdio.h>

typedef struct{
    char pid[10];
    int at, bt, wt, tat;
}Process;

int main(){

    int n;
    scanf("%d",&n);

    Process p[n];

    for(int i=0;i<n;i++)
        scanf("%s%d%d",p[i].pid,&p[i].at,&p[i].bt);

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].at>p[j+1].at){
                Process t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }

    int time=0;
    float aw=0,at=0;

    for(int i=0;i<n;i++){
        if(time<p[i].at)
            time=p[i].at;

        p[i].wt=time-p[i].at;
        p[i].tat=p[i].wt+p[i].bt;

        time+=p[i].bt;

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