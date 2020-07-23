/*
Name: Richard Haynes III
Assignment: COP 3502c Midterm assignment 2
Date: 6/15/19
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *createNode(int val);
int findSurvivor(struct node **ptr, int killed);
struct node *initialize(struct node *ptr);

struct node *createNode(int val)
{
	struct node *temp = initialize(temp);
	temp->data = val;
	temp->next = NULL;
	return temp;
}
int findSurvivor(struct node **ptr, int killed)
{
	int i;
	struct node *temp = initialize(temp);
	struct node *temp2 = initialize(temp2);

	temp = temp2 = *ptr;
	while(temp->next != temp)
	{
		for(i = 0; i < killed - 1; i++)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = temp->next;
	  	free(temp);
		temp = temp2->next;
	}
	return temp->data;
}
struct node *initialize(struct node *ptr)
{
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->data = 0;
	return ptr;
}
int main(void)
{
	int killedOff, numPrisoners, survivor, i;
	printf("How many prisoners are there?\n");
	scanf("%d", &numPrisoners);
	printf("How many do you want to skip?\n");
	scanf("%d", &killedOff);

	struct node *head = NULL;
	struct node *rear = initialize(rear);
	// Create circular linked list
	for(i = 1; i <= numPrisoners; i++)
	{
		// Create a temp node
		struct node *temp = createNode(i);

		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			rear->next = temp;
		}
		rear = temp;
		// rear gets temp this is cause were putting our rear pointer to be temp
		// 1,2,3,4,5   6
		// h       r   t
	}
	// Creates our circular linked list.
	rear->next = head;
	// Find survivor
	survivor = findSurvivor(&head, killedOff);
	printf("The prisoner to survive: %d\n", survivor);
}
