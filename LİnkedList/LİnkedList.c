#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *Next;
}*head=NULL;

void createNodeList(int new_data)
{
	struct Node * new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node *last=head;
	new_node->data=new_data;
	new_node->Next=NULL;
	
	
	if(head==NULL)
	{
		head=new_node;
		return;	
	}
	while(last->Next!=NULL)
	{
		last=last->Next;
	}
	last->Next=new_node;
}

void displayList()
{
	struct Node*temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->Next;
	}
}

void MiddleNodeDeletion(int pos)
{
	int i;
	struct Node* temp=head;
	
	if(pos==0)
	{
		head=head->Next;
		temp->Next=NULL;
		free(temp);
	}
	else
	{
		for(i = 1 ; i <pos-1 ; i++)
		{
			temp=temp->Next;
		}
		
		struct Node *del=temp->Next;
		temp->Next=del->Next;
		free(del);
	}
	
}





int main()
{
	int n,num,i;
	printf("Pls enter number : ");
	scanf("%d",&n);
	
	if(n%2 == 0)
	{
		printf("Enter Odd number pls\n");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf("Input data for node %d : ",i+1);
			scanf("%d",&num);
			createNodeList(num);
		}
		
		displayList();
		MiddleNodeDeletion((n/2)+1);
		printf("------after delete-------\n");
		displayList();
	}
	
}
