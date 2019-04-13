#include<iostream>
#include<time.h>
using namespace std;
# define MAX 10
 
class node
{
	public:
		int data;
		node *next;
		node()
		{
			next=NULL;
		}
};
class lgraph
{
	//public:
	protected:
	int i,j,ver1,ver2;
	public:
		int d[10][10],ver;
		node *head[MAX];
		int ele;
		lgraph()
		{
			for(i=0;i<MAX;i++)
			{
				head[i]=NULL;
			}
		}
		void get();
		void display();
		void getdata();
		void adjmatrix();
};
void lgraph::get()
{
	node *temp;
	cout<<"\n Enter Total Number Of Vertices: ";
	cin>>ver1;
	for(i=0;i<ver1;i++)
	{
 
	cout<<"\n Enter Total Number Of Vertex Which Are Attached To vertex "<<i+1<<" : ";
	
		cin>>ver2;
		for(j=0;j<ver2;j++)
		{
			cout<<"\n Enter Vertex which is attached to  vertex "<<i+1<<" : ";
 
			cin>>ele;
			if(head[i]==NULL)
			{
				node *newnode;
				newnode=new node;
				newnode->data=ele;
				newnode->next=NULL;
				head[i]=newnode;
				temp=head[i];
			}
			else
			{
				node *newnode;
				newnode=new node;
				newnode->data=ele;
				newnode->next=NULL;
				temp->next=newnode;
				temp=newnode;
			}
		}
	}
}
void lgraph::display()
{
	node *temp1;
	cout<<"\n\n\n Using Adjency list\n";
	for(i=0;i<ver1;i++)
	{
		cout<<"s["<<i+1<<"] -->";
		temp1=head[i];
		while(temp1->next!=NULL)
		{
			cout<<"s["<<temp1->data<<"]-->";
			temp1=temp1->next;
		}
		cout<<"s["<<temp1->data<<"]";
		cout<<"\n";
	}
}
void lgraph::getdata()
{
	int v1,v2;
	cout<<"\n Enter Total Of Vertices: ";
	cin>>ver;

   for(i=0;i<ver;i++)
   {
    for(j=0;j<ver;j++)
    	d[i][j]=0;
   }

	for(i=0;i<ver;i++)
	{
		cout<<"\nEnter vertex pair of edge "<<i+1;
   	  	cout<<"\nV1 : ";
   	  	cin>>v1;
   	  	cout<<"V2 : ";
   	  	cin>>v2;

   	  	d[v1-1][v2-1]=1;
   	  	d[v2-1][v1-1]=1;
		
	}
}

void lgraph::adjmatrix()
{
   cout<<"\nUsing Adjency matrix :\n  ";
   for(i=0;i<ver;i++)
   	cout<<"  "<<i+1;

   for(i=0;i<ver;i++)
   {
   	cout<<"\n "<<i+1;
   	for(j=0;j<ver;j++)
   	{
   		cout<<"  "<<d[i][j];
   	}
   }
   cout<<"\n";

}

int main()
{
	lgraph g;
	char ans;
	int ch;
	double execution_time;
	clock_t time;
	do
	{
		cout<<"\n MENU:\n1.Using Adjency Matrix\n2.Using Adjency List\n3.Runtime of Adjency matrix\n4.Runtime of Adjency list\nEnter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.getdata();
				g.adjmatrix();
				break;
			case 2:
				g.get();
				g.display();
				break;
			case 3:
 
				time=clock();
				g.getdata();
				time=clock()-time;
				execution_time=(double(time))/CLOCKS_PER_SEC;
		        cout<<"\nTime of execution of function getdata() for matrix is:\t"<<execution_time<<" sec\n\n";
				break;
			case 4:
 
				time=clock();
				g.get();
				time=clock()-time;
				execution_time=(double(time))/CLOCKS_PER_SEC;
		        cout<<"\nTime of execution of function get() for adjacency list is:\t"<<execution_time<<" sec\n\n";
				break;
			default:
				cout<<"\n Enter Correct option";
		}
		cout<<"\n Do You Want To Continue(y/n): ";
		cin>>ans;
	}
	while(ans=='y');
}
