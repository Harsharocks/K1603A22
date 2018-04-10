#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
struct Process
{
	ll Burst_Time;
	ll Priority;
	ll Arrival_Time;
};
struct Queue
{
	struct Process P1[100];
};
ll i;
ll j;
void PP_sorting_Arr(struct Process P1[],ll PP)
{
	
	for( i=0;i<PP-1;i++)
	{
		for( j=0;j<PP-i-1;j++)
		{
			if(P1[j].Arrival_Time>P1[j+1].Arrival_Time)
			{
				struct Process P2=P1[j];
				P1[j]=P1[j+1];
				P1[j+1]=P2;
			}
		}
	}
}
void RR_sorting_Arr(struct Process P1[],ll RR)
{
	for( i=0;i<RR-1;i++)
	{
		for( j=0;j<RR-i-1;j++)
		{
			if(P1[j].Arrival_Time>P1[j+1].Arrival_Time)
			{
				struct Process P2=P1[j];
				P1[j]=P1[j+1];
				P1[j+1]=P2;
			}
		}
	}
}
void FF_sorting_Arr(struct Process P1[],ll FF)
{
	for( i=0;i<FF-1;i++)
	{
		for( j=0;j<FF-i-1;j++)
		{
			if(P1[j].Arrival_Time>P1[j+1].Arrival_Time)
			{
				struct Process P2=P1[j];
				P1[j]=P1[j+1];
				P1[j+1]=P2;
			}
		}
	}
}
void PP_Prior_sorting_Arr(struct Process P1[],ll PP)
{
	for( i=0;i<PP-1;i++)
	{
		for( j=0;j<PP-i-1;j++)
		{

			if(P1[j].Priority>P1[j+1].Priority && P1[j].Arrival_Time>=P1[j+1].Arrival_Time)
			{
				struct Process P2=P1[j];
				P1[j]=P1[j+1];
				P1[j+1]=P2;
			}
		}
	}
}

void view_Pocessing(struct Process P1[],ll PP)
{
	for( i=0;i<PP;i++)
	{
		printf("Process %lld\n",i+1);
		printf("Priority of Process %lld\n",P1[i].Priority);
		printf("Burst_Time of Process %lld\n",P1[i].Burst_Time);
	}
}
ll FC_lo=0,set=1;
ll Turn_Around_FF[100];
ll PQ_lo=0,set1=1;
ll Turn_Around_PP[100];
ll Turn_Around_RR[100];
ll RR_lo=0,set2=1;
void First_come_first_serve(struct Process P1[],ll FF,ll loop)
{
	printf("loop %lld\n",loop);
	for( i=1;i<=loop+1;i++)
	{
		if(FC_lo>FF)
		{
			return;
		}
		if(P1[FC_lo].Burst_Time!=0)
		{
			P1[FC_lo].Burst_Time-=1;
		}
		if(P1[FC_lo].Burst_Time==0)
		{
			if(FC_lo>=FF)
			{
				return;
			}
			else
			{
				printf("Process P%lld Completed \n",FC_lo+1);
				Turn_Around_FF[FC_lo]=set;
				printf("Turn around Time %lld  %lld\n",Turn_Around_FF[FC_lo],FC_lo);
			}
			FC_lo++;
		}
		set++;
		set1++;
		set2++;
	}
	printf("Process P%lld Remaining Burst Time %lld\n",FC_lo+1,P1[FC_lo].Burst_Time);
}
void Priority_Q(struct Process P1[],ll PP,ll loop)
{
	for( i=1;i<=loop+1;i++)
	{
		if(PQ_lo>PP)
		{
			return;
		}
		if(P1[PQ_lo].Burst_Time!=0)
		{
			P1[PQ_lo].Burst_Time-=1;
		}
		if(P1[PQ_lo].Burst_Time==0)
		{
			if(PQ_lo>=PP)
			{
				return;
			}
			else
			{
				printf("Process P%lld Completed \n",PQ_lo+1);
				Turn_Around_PP[PQ_lo]=set1;
				printf("Turn around Time %lld\n",Turn_Around_PP[PQ_lo]);
			}
			PQ_lo++;
		}
		set1++;
		set++;
		set2++;
	}
	printf("Process P%lld Remaining Burst Time %lld\n",PQ_lo+1,P1[PQ_lo].Burst_Time);
}
ll qq=0;
void Round_Robin_Q(struct Process P1[],ll RR,ll loop)
{
	ll tem_p=0;
	printf("loop %lld\n",loop );
	for( i=1;i<=loop+1;i++)
	{
		if(tem_p==4)
		{
			printf("Process P%lld Remaining Burst Time %lld\n",RR_lo+1,P1[RR_lo].Burst_Time);
			P1[qq]=P1[RR_lo];
			qq++;
		}
		if(RR_lo>RR)
		{
			return;
		}
		if(P1[RR_lo].Burst_Time!=0)
		{
			P1[RR_lo].Burst_Time-=1;
		}
		if(P1[RR_lo].Burst_Time==0)
		{
			if(RR_lo>=RR)
			{
				return;
			}
			else
			{
				printf("Process P%lld Completed \n",RR_lo+1);
				Turn_Around_RR[RR_lo]=set2;
				printf("Turn around Time %lld\n",Turn_Around_RR[RR_lo]);
			}
			RR_lo++;
		}
		set2++;
		set1++;
		set++;
		tem_p++;
	}
	printf("Process P%lld Remaining Burst Time %lld\n",RR_lo+1,P1[RR_lo].Burst_Time);
}
int main()
{
	memset(Turn_Around_FF,0,sizeof(Turn_Around_FF));
	memset(Turn_Around_PP,0,sizeof(Turn_Around_PP));
	memset(Turn_Around_RR,0,sizeof(Turn_Around_RR));
	struct Queue Round_Robin,Priority_Queue,FCFS_Queue;
	ll Nu_proc;
	printf("Enter number of process");
	scanf("%lld",&Nu_proc);
	printf("Enter Priority of the Process and Burst Time and Arrival Time\n");
	ll RR=0,FF=0,PP=0;
	for(i=0;i<Nu_proc;++i)
	{
		ll burst,proi,arri;
		scanf("%lld\n %lld\n %lld\n\n",&proi,&burst,&arri);
		if(proi<=5)
		{
			Round_Robin.P1[RR].Priority=proi;
			Round_Robin.P1[RR].Burst_Time=burst;
			Round_Robin.P1[RR].Arrival_Time=arri;
			RR++;
		}
		else if(proi>=6 && proi<=10)
		{
			Priority_Queue.P1[PP].Priority=proi;
			Priority_Queue.P1[PP].Burst_Time=burst;
			Priority_Queue.P1[PP].Arrival_Time=arri;
			PP++;
		}
		else 
		{
			FCFS_Queue.P1[FF].Priority=proi;
			FCFS_Queue.P1[FF].Burst_Time=burst;
			FCFS_Queue.P1[FF].Arrival_Time=arri;
			FF++;
		}
	}
	PP_sorting_Arr(Priority_Queue.P1,PP);
	RR_sorting_Arr(Round_Robin.P1,RR);
	FF_sorting_Arr(FCFS_Queue.P1,FF);
	PP_Prior_sorting_Arr(Priority_Queue.P1,PP);
	for( i=0;i<FF;i++)
	{
		printf("Process %lld\n",i+1);
		printf("Priority of Process %lld\n",Priority_Queue.P1[i].Priority);
		printf("Arrival_Time of Process %lld\n",FCFS_Queue.P1[i].Arrival_Time);
	}
	printf("SORTED\n");
	for( i=0;i<PP;i++)
	{
		printf("Process %lld\n",i+1);
		printf("Priority of Process  Arrival_Time of Process\n %lld    %lld\n",Priority_Queue.P1[i].Priority,Priority_Queue.P1[i].Arrival_Time);
	}
	ll a=0,b=0,c=0;
	ll good=0,bad=0,devil=0;
	qq=RR;
	while(1)
	{
		if(FC_lo<FF)
		{
			good=1;
			printf("............FIRST COME FIRST SERVE Queue Started\n");
			for( i=1;i<=10;i++)
			{
				if(FCFS_Queue.P1[FC_lo].Arrival_Time<set)
				{
					First_come_first_serve(FCFS_Queue.P1,FF,10-i);
					printf("break\n");
					break;
				}
				set++;
				set1++;
			}
			printf("............FIRST COME FIRST SERVE Queue Duration Completed\n");
		}
		else
		{
			good=0;
		}
		if(PQ_lo<PP)
		{
			bad=1;
			printf(".............Priority_Queue Started\n");
			for( i=1;i<=10;i++)
			{
				if(Priority_Queue.P1[PQ_lo].Arrival_Time<set1)
				{
					Priority_Q(Priority_Queue.P1,PP,10-i);
					printf("break\n");
					break;
				}
				set1++;
				set++;
			}
			printf(".............Priority_Queue Duration Completed\n");
		}
		else
		{
			bad=0;
		}
		if(RR_lo<RR)
		{
			devil=1;
			printf(".............Round Robin_Queue Started\n");
			for( i=1;i<=10;i++)
			{
				if(Round_Robin.P1[PQ_lo].Arrival_Time<set2)
				{
					Round_Robin_Q(Round_Robin.P1,RR,10-i);
					printf("break\n");
					break;
				}
				set1++;
				set++;
				set2++;
			}
			printf(".............Round Robin_Queue Completed\n");
		}
		else
		{
			devil=0;
		}
		if(devil==0)
		{
			break;
		}
		if(good==0 && bad==0)
		{
			break;
		}
	}
	
	return 0;
}
