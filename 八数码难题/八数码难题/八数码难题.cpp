#include <iostream>
using namespace std;

int number=0;
void set(int item[3][3])
{
	cout<<"请输入："<<endl;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			cin>>item[i][j];
		}
}
void output(int item[3][3])
{
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<item[i][j]<<ends;
		}
		cout<<endl;
	}
	
}
int line(int num,int item[3][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(item[i][j]==num)
				return i;
		}
}
int row(int num,int item[3][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(item[i][j]==num)
				return j;
		}
}
void temp(int &x,int &y,int item[3][3])
{
	int mytemp=0;
	mytemp=x;
	x=y;
	y=mytemp;
	number++;
	output(item);
}
void move(int x,int y,int item[3][3])
{
	while(row(0,item)<y)
		temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
	while(row(0,item)>y)
		temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
	while(line(0,item)>x)
		temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
	while(line(0,item)<x)
		temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
}
void ToLine(int i,int item[3][3])
{
	temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
	if(line(i,item)!=(i-1)/3)
	{
		if(row(0,item)<2)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
		}
		else
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
		}
	}
}
void ToRow(int i,int item[3][3])
{
	temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
	if(row(i,item)!=(i-1)-(i-1)/3*3)
	{
		if(line(0,item)<2)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
		}
		else
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
		}
	}
}
void ALG(int item[3][3])
{
	temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
	temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
}
void solution(int item[3][3])
{
	//移动1到位
	if(item[0][0]==1);
	else
	{
		move(0,0,item);
		if(line(1,item)==0)
		{
			move(line(1,item),row(1,item)-1,item);
			ToRow(1,item);
		}
		else if(row(1,item)==0)
		{
			move(line(1,item)-1,row(1,item),item);
			ToLine(1,item);
		}
		else 
		{
			move(line(1,item)-1,row(1,item),item);
			ToLine(1,item);
			move(line(1,item),row(1,item)-1,item);
			ToRow(1,item);
		}
	}
	
	//移动2到位
	if(item[0][1]==2);
	else
	{
		move(0,1,item);
		if(line(2,item)==0)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
		}
		else if(row(2,item)==1)
		{
			move(line(2,item)-1,row(2,item),item);
			ToLine(2,item);
		}
		else 
		{
			if(row(2,item)==2)
			{
				move(line(2,item)-1,row(2,item),item);
				ToLine(2,item);
				move(line(2,item),row(2,item)-1,item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
			}
			else
			{
				move(line(2,item),row(2,item)+1,item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				if(line(2,item)==2)
				{
					temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
					ToLine(2,item);
				}
				else
				{
					temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				}
			}
		}
	}
	
	//移动3到位
	if(item[0][2]==3);
	else
	{
		move(0,2,item);
		if(row(3,item)==2)
		{
			if(line(3,item)==1)
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			else
			{
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				ALG(item);
			}

		}
		else 
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			move(line(3,item),row(3,item)+1,item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			if(row(3,item)!=2)
			{
				if(line(0,item)<2)
				{
					temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);

				}
				else
				{
					temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
					temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				}
			}
			if(line(0,item)<2)
			{
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			}
			else
			{
				temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				ALG(item);
			}

		}
	}
	
	//移动4到位
	if(item[1][0]==4);
	else
	{
		if(line(4,item)==1)windows
		{
			move(line(4,item),row(4,item)-1,item);
			ToRow(4,item);
		}
		else if(row(4,item)==0)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
		}
		else 
		{
			move(line(4,item)-1,row(4,item),item);
			ToLine(4,item);
			move(line(4,item),row(4,item)-1,item);
			ToRow(4,item);
		}
	}
	
	//移动5到位
	if(item[1][1]==5);
	else
	{
		move(1,1,item);
		if(line(5,item)==1)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
		}
		else if(row(5,item)==1)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
		}
		else 
		{
			if(row(5,item)==2)
			{
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			}
			else
			{
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
				temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);

			}
		}
	}
	
	//移动6到位
	if(line(6,item)==1);
	else 
	{
		move(1,2,item);
	    if(row(6,item)==2)
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
		else if(row(6,item)==0)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
		}
		else if(row(6,item)==1)
		{
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)+1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)-1][row(0,item)],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)][row(0,item)-1],item);
			temp(item[line(0,item)][row(0,item)],item[line(0,item)+1][row(0,item)],item);
		}
	}
	//移动7、8到位
	move(2,2,item);
}
int main()
{
	int check[3][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			check[i][j]=0;
		}
	set(check);
	output(check);
	solution(check);
	cout<<endl<<"共"<<number<<"步"<<endl;
	return 0;
}