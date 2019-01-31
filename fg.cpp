#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}Node;

void create(Node* head[])
{
	for(int i=0; i<5; i++) head[i]=NULL;
}

struct node* add(Node* head,int data)
{
	int c=0;
	Node* tmp=head;
	Node* cur=new Node;
	while(tmp!=NULL)
	{
		if(tmp->data==data)
		c=1;
		tmp=tmp->next;
	}
	tmp=head;
	if(c==1)
	cout<<"Already Present\n";
	else if(tmp==NULL)
	{
		cur->data=data;
		cur->next=NULL;
		tmp=cur;
		head=tmp;
	}
	else
	{
		while(tmp->next!=NULL)
			tmp=tmp->next;
		cur->data=data;
		cur->next=NULL;
		tmp->next=cur;
	}
	return head;
}

void build(Node* head[],int arr[],int n)
{
	int i=0;
	while(i<n)
	{
		head[arr[i]%5]=add(head[arr[i]%5],arr[i]);
		i++;
	}
}

int is_element_of(int v,Node* head[])
{
	for(int i=0; i<5; i++)
	{
		while(head[i]!=NULL)
		{
			if(head[i]->data==v)
			return 1;
			head[i]=head[i]->next;
		}
	}
	return 0;
}

int is_empti(Node* head[])
{
	for(int i=0; i<10; i++)
	{
		if(head[i]!=NULL)
		return 1;
	}
	return 0;
}

int size(Node* head[])
{
	Node* tmp[10];
	for(int i=0; i<5; i++)
	tmp[i]=head[i];
	int cnt=0;
	for(int i=0; i<5; i++)
	{
		while(tmp[i]!=NULL)
		{
			tmp[i]=tmp[i]->next;
			cnt++;
		}
	}
	return cnt;
}

void enumerate(Node* head[])
{
	Node* tmp[5];
	for(int i=0;i<5;i++)
	tmp[i]=head[i];
	if(!is_empti(head))
	{
		cout<<"Empty\n";
		return;
	}
	for(int i=0;i<5;i++)
	{
		while(tmp[i]!=NULL)
		{
			cout<<tmp[i]->data<<" ";
			tmp[i]=tmp[i]->next;
		}
	}
	cout<<"\n";
}

Node* removed(Node* head[],int val)
{
	int c=0;
	struct node* tmp[5];
	for(int i=0; i<5; i++)
	tmp[i]=head[i];
	if(tmp[val%5]!=NULL && tmp[val%5]->data==val && tmp[val%5]->next==NULL)
	tmp[val%5]=NULL;
	else if(tmp[val%10]!=NULL && tmp[val%10]->data==val && tmp[data%10]->next!=NULL)
	tmp[val%10]=tmp[val%10]->next;
	else
	{
		while(tmp[x%10]!=NULL && tmp[val%10]->next!=NULL)
		{
			if(tmp[x%10]->next->x==x)
			{
				tmp[x%10]->next=tmp[x%10]->next->next;
				free(tmp[x%10]->next);
				c=1;
				break;
			}
			tmp[x%10]=tmp[x%10]->next;
		}

		if(!c)
		cout<<"Not Present\n";
	}
	return tmp[x%10];
}

void Union(Node* hd1[],Node* hd2[],int size1,int size2,Node* unin[])
{
	struct node* tmp1[5],*tmp2[5];
	for(int i=0; i<5; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	int X[size1+size2];
	int n=0,c=0,n1;
	for(int i=0; i<5; i++)
	{
		while(tmp1[i]!=NULL)
		{
			X[n++]=tmp1[i]->data;
			tmp1[i]=tmp1[i]->next;
		}
	}
	n1=n;
	for(int i=0; i<5; i++)
	{
		while(tmp2[i]!=NULL)
		{
			c=0;
			for(int j=0; j<n1; j++)
			{
				if(X[j]==tmp2[i]->data)
				{
				c=1;
				break;
				}
			}
			if(c==0)
			X[n++]=tmp2[i]->data;
			tmp2[i]=tmp2[i]->next;
		}
	}
	build(unin,X,n);
}

void Intersection(Node* hd1[],Node* hd2[],Node* intrsctn[])
{
	int X[size(hd1)];
	int Y[size(hd1)];
	int nx=0,ny=0,c=0;
	Node* tmp1[5],*tmp2[5];
	for(int i=0; i<5; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	for(int i=0;i<5;i++)
	{
		while(tmp1[i]!=NULL)
		{
			Y[ny++]=tmp1[i]->data;
			tmp1[i]=tmp1[i]->next;
		}
	}
	for(int j=0; j<5; j++)
	{
		while(tmp2[j]!=NULL)
		{
			c=0;
			for(int i=0; i<ny; i++)
			{
				if(Y[i]==tmp2[j]->data)
				c=1;
			}
			if(c==1)
			X[nx++]=tmp2[j]->data;
			tmp2[j]=tmp2[j]->next;
		}
	}
	build(intrsctn,X,nx);
}

void difference(Node* hd1[],Node* hd2[],Node* diff[])
{
	int X[size(hd1)];
	int Y[size(hd1)];
	int nx=0,ny=0,c=0;
	struct node* tmp1[5],*tmp2[5];
	for(int i=0; i<5; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	for(int i=0; i<5; i++)
	{
		while(tmp2[i]!=NULL)
		{
			Y[ny++]=tmp2[i]->data;
			tmp2[i]=tmp2[i]->next;
		}
	}
	for(int j=0; j<5; j++)
	{
		while(tmp1[j]!=NULL)
		{
			c=0;
			for(int i=0; i<ny; i++)
			{
				if(Y[i]==tmp1[j]->data)
				c=1;
			}
			if(c==0)
			X[nx++]=tmp1[j]->data;
			tmp1[j]=tmp1[j]->next;
		}
	}
	build(diff,X,nx);
}

int subset(Node* hd1[],Node* hd2[])
{
	int c=0;
	struct node* tmp1[5],*tmp2[5];
	for(int i=0; i<5; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	for(int i=0; i<5; i++)
	{
		while(tmp1[i]!=NULL)
		{
			c=0;
			for(int k=0; k<5; k++)
			tmp2[k]=hd2[k];
			for(int j=0; j<5; j++)
			{
				while(tmp2[j]!=NULL)
				{
					if(tmp1[i]->data==tmp2[j]->data)
					c=1;
					tmp2[j]=tmp2[j]->next;
				}
			}
			if(!c)
			return c;
			tmp1[i]=tmp1[i]->next;
		}
	}
	return c;
}

int main(){
    Node* set1[10],*set2[10],*set3[10],*set4[10],*set5[10];
	create(set1),create(set2),create(set3),create(set4),create(set5);
	int n,v,c=1;

	cout<<"Enter number of elements to enter in first set : ";
	cin>>n;
	int A[n];
	cout<<"Enter the elements for first set : ";
	for(int i=0; i<n; i++)
	cin>>A[i];
	build(set1,A,n);
	int size_set1=size(set1);
	cout<<"First set : ";
	enumerate(set1);

	cout<<"Enter number of elements to enter in second set : ";
	cin>>n;
	int B[n];
	cout<<"Enter the elements for second set : ";
	for(int i=0; i<n; i++)
	cin>>B[i];
	build(set2,B,n);
	int size_set2=size(set2);
	cout<<"Second set : ";
	enumerate(set2);

	Union(set1,set2,size_set1,size_set2,set3);
	cout<<"Union of set1 and set2 : ";
	enumerate(set3);

	Intersection(set1,set2,set4);
	cout<<"Intersection of set1 and set2 : ";
	enumerate(set4);

	difference(set1,set2,set5);
	cout<<"Difference of set1 and set2 : ";
	enumerate(set5);

	if(subset(set1,set2))
	cout<<"First set is a subset of second\n";
	else
	cout<<"First set is not a subset of second\n";

	c=1;
	while(c)
	{
	cout<<"Enter the element to remove from set1 : ";
	cin>>v;
	set1[v%10]=removed(set1,v);
	enumerate(set1);
	cout<<"Enter 0 to exit : ";
	cin>>c;
	}
}
