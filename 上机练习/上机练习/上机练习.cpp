#include<iostream>
#include<string>
using namespace std;
class FlightNode
{
public:
	char name[20];
	char ID[20];
	FlightNode * next;
	FlightNode(char* na, char* id,FlightNode* nt=0)
	{
		strcpy(name,na);
		strcpy(ID,id);
		next = 0;
	}

};
class Flight
{
private:
	FlightNode * flight;
	int num; // the capacity of the flight
	int current;//the current number of the passengers
public:
	Flight(int total = 100){
		flight = 0;
		num = total;
		current = 0;
	}
	void ReserveTicket(char * na,char *id);//3'
	bool CancelReserve(char *id); //3'
	bool CheckReserve(char* id); //1'
	void display();//1'
	~Flight();//2'
};
void Flight::ReserveTicket(char * na,char * id)
{
	FlightNode * p=new FlightNode(na,id,0);
	if(flight==0)
		flight=p;
	else
	{
		p->next=flight->next;
		flight->next=p;
	}
}
bool Flight::CancelReserve(char * id)
{
	FlightNode * p=0,* q=0;
	for(p=flight;p!=0;q=p,p=p->next)
	{
		if(!strcmp(p->ID,id))
		{
			if(q==0)
			{
				flight=flight->next;
				delete p;
			}
			else
			{
				q->next=p->next;
				delete p;
			}
			return true;
		}
	}
	return false;
}
bool Flight::CheckReserve(char* id)
{
	FlightNode * p=flight;
	while(p!=0)
	{
		if(!strcmp(p->ID,id))
			return true;
		else
			p=p->next;
	}
	return false;
}
void Flight::display()
{
	FlightNode * p=flight;
	while(p!=0)
	{
		cout<<p->name<<"   ";
		cout<<p->ID<<endl;
		p=p->next;
	}
}
Flight::~Flight()
{
	FlightNode * p, * q;
	p=flight;
	while(p!=0)
	{
		q = p->next;
		delete p;
		p = q;
	}
}
int main()
{
	int i;
	cout<<"请输入航班的容量：";
	cin>>i;
	Flight myflight(i);
	for(int n=0;n<i;n++)
	{
		char name[20],ID[20];
		cout<<"请输入订票人的信息："<<endl;
		cin>>name;
		cin>>ID;
		myflight.ReserveTicket(name,ID);
	}
	cout<<"请输入取消订票的人的ID："<<endl;
	char ID[20];
	cin>>ID;
	if(myflight.CancelReserve(ID))
		cout<<"退订成功"<<endl;
	else
		cout<<"退订失败"<<endl;
	cout<<"请输入查票的人的ID："<<endl;
	cin>>ID;
	if(myflight.CancelReserve(ID))
		cout<<"查询成功"<<endl;
	else
		cout<<"查询失败"<<endl;
	myflight.display();
	return 0;
}
