#include <iostream>
#include <math.h>
using namespace std;
void machine()
{
	int i=0,j=0,m=0,n=0,token=0;

	char * id;
	char * program;

	program = new char[100];

	for(int num=0;num<100;num++){
		program[num]='#';
	}
	cout<<"ÇëÊäÈëÒ»¶Î³ÌÐò£º";
	cin.getline(program,100);
	cout<<program<<endl;
	do
	{
		if(program[i]=='f'&&program[i+1]=='o'&&program[i+2]=='r')
		{
			token=1;
			id="for";
			i=i+3;
		}
		else if(program[i]=='i'&&program[i+1]=='f')
		{
			token=2;
			id="if";
			i=i+2;
		}
		else if(program[i]=='t'&&program[i+1]=='h'&&program[i+2]=='e'&&program[i+3]=='n')
		{
			token=3;
			id="then";
			i=i+4;
		}
		else if(program[i]=='e'&&program[i+1]=='l'&&program[i+2]=='s'&&program[i+3]=='e')
		{
			token=4;
			id="else";
			i=i+4;
		}
		else if(program[i]=='w'&&program[i+1]=='h'&&program[i+2]=='i'&&program[i+3]=='l'&&program[i+4]=='e')
		{
			token=5;
			id="while";
			i=i+5;
		}
		else if(program[i]=='d'&&program[i+1]=='o')
		{
			token=6;
			id="do";
			i=i+2;
		}
		else if(program[i]=='+')
		{
			token=13;
			id="+";
			i++;
		}
		else if(program[i]=='-')
		{
			token=14;
			id="-";
			i++;
		}
		else if(program[i]=='*')
		{
			token=15;
			id="*";
			i++;
		}
		else if(program[i]=='/')
		{
			token=16;
			id="/";
			i++;
		}
		else if(program[i]=='=')
		{
			token=25;
			id="=";
			i++;
		}
		else if(program[i]==';')
		{
			token=26;
			id=";";
			i++;
		}
		else if(program[i]=='(')
		{
			token=27;
			id="(";
			i++;
		}
		else if(program[i]==')')
		{
			token=28;
			id=")";
			i++;
		}
		else if(program[i]=='#')
		{
			token=0;
			id="#";
			i++;
		}
		else if(program[i]==':'&&program[i+1]!='=')
		{
			token=17;
			id=":";
			i++;
		}
		else if(program[i]==':'&&program[i+1]=='=')
		{
			token=18;
			id=":=";
			i=i+2;
		}
		else if(program[i]=='<'&&program[i+1]!='>'&&program[i+1]!='=')
		{
			token=20;
			id="<";
			i++;
		}
		else if(program[i]=='<'&&program[i+1]=='>')
		{
			token=21;
			id="<>";
			i=i+2;
		}
		else if(program[i]=='<'&&program[i+1]=='=')
		{
			token=22;
			id="<=";
			i=i+2;
		}
		else if(program[i]=='>'&&program[i+1]!='=')
		{
			token=23;
			id=">";
			i++;
		}
		else if(program[i]=='>'&&program[i+1]=='=')
		{
			token=24;
			id=">=";
			i=i+2;
		}
		else if((program[i]>=65&&program[i]<=90)||(program[i]>=97&&program[i]<=122))	
		{
			j=0;
			id = new char[10];
			while((program[i]>=65&&program[i]<=90)||(program[i]>=97&&program[i]<=122)||(program[i]>=48&&program[i]<=57))
			{i++;j++;}
			token=10;	
			for(m=i-j,n=0;m<i;m++,n++)
				id[n]=program[m];
		}
		else if(program[i]>=48&&program[i]<=57)
		{
			j=0;
			id = new char[10];
			while(program[i]>=48&&program[i]<=57)
			{i++;j++;}
			token=11;	
			for(m=i-j,n=0;m<i;m++,n++)
				id[n]=program[m];
		}
		else
		{
			token=12;
			i++;
		}

		switch(token)
		{
		case 10:printf("(%d,",token);
			    for(int temp=0;temp<n;temp++)
				{
					printf("%c",id[temp]);
				}
				printf(")");
				break;
		case 11:printf("(%d,",token);
			    for(int temp=0;temp<n;temp++)
				{
					printf("%c",id[temp]);
				}
				printf(")");
				break;
		case 12:break;
		case -1:printf("error!\n");break;
		default:printf("(%d,%s)",token,id);break;
		}
	}  while(program[i]!='#');
}
int main()
{
	machine();
	cout<<endl;
	return 0;
}