#include<iostream>
using namespace std;
class node
{
public:
	int num;
	int time;
	int min;
	int fir;
};
class work
{
private:
	node * job;
	int len;
public:
	work()
	{
		job=new node[10];
		len=0;
	}
	/*void create()
	{
		cout<<"请输入进程数："<<endl;
		cin>>len;
		cout<<"请设置进程属性："<<endl;
		for(int i=0;i<len;i++)
		{
			cin>>job[i].num;
			cin>>job[i].time;
			cin>>job[i].min;
			cin>>job[i].fir;
		}
	}*/
	void create()
	{
		len=5;
		job[0].num=1;
		job[0].time=800;
		job[0].min=110;
		job[0].fir=0;
		job[1].num=2;
		job[1].time=900;
		job[1].min=350;
		job[1].fir=0;
		job[2].num=3;
		job[2].time=950;
		job[2].min=100;
		job[2].fir=1;
		job[3].num=4;
		job[3].time=1000;
		job[3].min=50;
		job[3].fir=0;
		job[4].num=5;
		job[4].time=1000;
		job[4].min=200;
		job[4].fir=2;
	}
	void change(int & x,int & y)
	{
		int temp;
		temp=x;
		x=y;
		y=temp;
	}
	void fcfs();
	void mfs();
};
void work::mfs()
{
    int time=job[0].time;
	int m=0,n=0;
	while(m<len)
	{
		if(job[m].time>time)
		{
			time++;
		}
		else if(job[m].time<job[m+1].time&&job[m+1].time>time)
		{
			time=time+job[m].min;
			m++;
		}
		else 
		{
			for(n=m;n<len;n++)
			{
				if(job[n].time<=time);
				else break;
			}
			int max=m;
			for(int p=m;p<n;p++)
			{
				max=p;
				for(int q=p;q<n;q++)
				{
					if(job[q].fir>job[max].fir)
						max=q;
				}
				change(job[p].num,job[max].num);
				change(job[p].time,job[max].time);
				change(job[p].min,job[max].min);
				change(job[p].fir,job[max].fir);
			}
			for(int x=m;x<n;x++)
			{
				if(job[x].fir==job[x+1].fir)
					if(job[x].min>job[x+1].min)
					{
						change(job[x].num,job[x+1].num);
						change(job[x].time,job[x+1].time);
						change(job[x].min,job[x+1].min);
						change(job[x].fir,job[x+1].fir);
					}
			}
			for(int k=m;k<n;k++)
				time=time+job[k].min;
			m=n;
		}

	}
    time=job[0].time;
	for(int l=0;l<len;l++)
	{
		cout<<job[l].num<<ends;
		cout<<time<<'-'<<time+job[l].min<<endl;	
		time=time+job[l].min;
	}

}
void work::fcfs()
{
	int time=job[0].time;
	int m=0,n=0;
	while(m<len)
	{
        if(job[m].time>time)
		{
			time++;
		}
		else if(job[m].time<job[m+1].time)
		{
			time=time+job[m].min;
			m++;
		}
		else if(job[m].time==job[m+1].time)
		{
			if(job[m].fir>=job[m+1].fir);
			else if(job[m].fir<job[m+1].fir)
			{
				change(job[m].num,job[m+1].num);
				change(job[m].time,job[m+1].time);
				change(job[m].min,job[m+1].min);
				change(job[m].fir,job[m+1].fir);
			}
			m=m+2;
		}

	}
    time=job[0].time;
	for(int l=0;l<len;l++)
	{
		cout<<job[l].num<<ends;
		cout<<time<<'-'<<time+job[l].min<<endl;	
		time=time+job[l].min;
	}

}
int main()
{
	work mywork;
	mywork.create();
	//mywork.fcfs();
	mywork.mfs();
	return 0;
}