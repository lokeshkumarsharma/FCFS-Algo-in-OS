#include<stdio.h> 
int n,i,j;
float avgtat=0,avgwt=0;
struct fcfs
{
int at,st,ct,tat,wt;      //'st' stands for schedule time which means burst time
char pname[20];
float ntat;
}temp;

void ca(struct fcfs aaa[]);

void display(struct fcfs a[])
{
for(i=0;i<n;i++)
{
a[i].tat=a[i].ct-a[i].at;
a[i].wt=a[i].tat-a[i].st;
a[i].ntat=(float)a[i].tat/a[i].st;
avgtat+=a[i].tat;
avgwt+=a[i].wt;
}
avgtat=avgtat/n;
avgwt=avgwt/n;
printf("pname\tat\tst\tct\ttat\twt\tntat\n");
for(i=0;i<n;i++)
{
printf("%s\t%d\t%d\t%d\t%d\t%d\t%f\n",a[i].pname,a[i].at,a[i].st,a[i].ct,a[i].tat,a[i].wt,a[i].ntat);
}
printf("avgtat=%f\navgwt=%f\n",avgtat,avgwt);
}


main()
{
printf("enter the no of process\n");
scanf("%d",&n);
struct fcfs a[n];
for(i=0;i<n;i++)
{
printf("enter the name of process,at,st\n");
scanf("%s",&a[i].pname);
scanf("%d%d",&a[i].at,&a[i].st);
}
for(i=0;i<n;i++)
{
for(j=i;j>=1;j--)
{
if(a[j].at<a[j-1].at)
{
temp=a[j-1];
a[j-1]=a[j];
a[j]=temp;
}
}
}


ca(a);
}

void ca(struct fcfs aaa[])
{
int stt=aaa[0].at,tempi;
aaa[0].ct=stt+aaa[0].st;
stt=aaa[0].ct;
for(i=1;i<n;i++)
{
tempi=aaa[i].at;
if(tempi>stt)
stt=tempi;
aaa[i].ct=stt+aaa[i].st;
stt=aaa[i].ct;
}
display(aaa);
}

