#include<unistd.h>
#include<stdio.h>
void fcfs(int bt[],int at[],int n)
{int ct[n],tat[n],wt[n],ttat=0,twt=0;
ct[0]=at[0]+bt[0];
tat[0]=ct[0]-at[0];
wt[0]=tat[0]-bt[0];
for(int i=1;i<n;i++)
{if(ct[i-1]>at[i])
  {ct[i]=ct[i-1]+bt[i];
  }
else
  {ct[i]=at[i]+bt[i];
  }
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}
printf("\nProcess\tArrival time\tBurst time\tCompletion time\t Turn around time\tWait time\n");
for(int i=0;i<n;i++){
printf("p%d\t%d\t\t%d\t\t%d \t\t %d   \t\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
ttat+=tat[i];
twt+=wt[i];}
printf("\nTotal Turn around time = %d",ttat);
printf("\nTotal Waiting time =%d\n",twt);
}
void sjf(int bt[],int at[],int n)
{
	int ct[n],tat[n],wt[n],ttat=0,twt=0;
	ct[0]=at[0]+bt[0];
	tat[0]=ct[0]-at[0];
	wt[0]=tat[0]-bt[0]; 
	int p[n];
	for(int i =0;i<n;i++)
	{p[i] =i+1;}

	int index;
	int temp;
	for(int j=1;j<n;j++){
	index = j;
	  for(int i=j+1;i<n;i++)
	  {if(bt[i]<bt[index])
	  { index = i;}} 
	   temp = bt[j];
	bt[j] = bt[index];
	bt[index]=temp;
	temp = p[j];
	p[j]=p[index];
	p[index]= temp;
	}
	printf("\nProcess\tArrival time\tBurst time\tCompletion time\t Turn around time\tWait time\n");
	for(int i = 1;i<n+1;i++)
	{wt[i]=0;
	ct[i]=ct[i-1]+bt[i];
	   for(int j =0;j<i;j++)
	   wt[i]+=bt[j];
	tat[i]=bt[i]+wt[i]; 
	printf("p%d\t%d\t\t%d\t\t%d \t\t %d   \t\t\t%d\n",p[i-1],at[i-1],bt[i-1],ct[i-1],tat[i-1],wt[i-1]);}
	
}
void rr(int bt[],int at[],int n)
{
        int ct[n],tat[n],wt[n],ttat=0,twt=0;
       	int done = 0,time=0;
	int tempBT[n];
	for(int i=0;i<n;i++){
	tempBT[i]=bt[i];}
	while(1){
	for(int i=0;i<n;i++)
	{
	if(tempBT[i]!=0)
	{tempBT[i]-=2;
	time+=2; 
	}
	else{
	ct[i] =time;
	done++;}
	}
	if(done == n)
	{break;}
	}
	for(int i = 0;i<n;i++){
	tat[i] =ct[i]-i*2;
	wt[i]=tat[i]-bt[i];}
	 printf("\nProcess\tArrival time\tBurst time\tCompletion time\t Turn around time\tWait time\n");
	for(int i=0;i<n;i++){
	printf("p%d\t%d\t\t%d\t\t%d \t\t %d   \t\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	ttat+=tat[i];
	twt+=wt[i];}
	printf("\nTotal Turn around time = %d",ttat);
	printf("\nTotal Waiting time =%d\n",twt);
}
void main()
{
int n;
printf("Enter number of process = ");
scanf("%d",&n);
int bt[n],at[n],ct[n],p[n];
int i=0;
printf("Enter arrival time, burst time and priority for each process:");
for(i=0;i<n;i++){
printf("\nArrival time of process %d = ",i+1);
scanf("%d",&at[i]);
printf("\nBurst time of process %d = ",i+1);
scanf("%d",&bt[i]);
printf("Priority of process %d =",i+1);
scanf("%d",&p[i]);
}
int ch;
printf("Select Scheduling Algorithm:\n1.FCFS\t2.SJF\t3.RR");
scanf("%d",&ch);
switch(ch){
case 1:fcfs(bt,at,n);
break;
case 2:sjf(bt,at,n);
break;
case 3:rr(bt,at,n);
break;
default:printf("Invaild input");
}
}
