#include <stdio.h>
#include <stdlib.h>
#include<iterator>
#include<map>
struct noder
{
	int value;
	noder* next;
	noder* random;
};
using namespace std;
noder* clone(noder* head){
	map < noder*, noder* > cmap;
	noder* nhead = (noder*)malloc(sizeof(noder));
	nhead->value = head->value;
	nhead->next = NULL;
	cmap.insert(pair<noder*, noder*>(head, nhead));
	noder* curr1,*curr2;
	curr1 = head->next;
	curr2 = nhead;
	while (curr1 != NULL)
	{
		noder* newnode = (noder*)malloc(sizeof(noder));
		newnode->value = curr1->value;
		newnode->next = NULL;
		cmap.insert(pair<noder*, noder*>(curr1, newnode));
		curr2->next = newnode;
		curr2 = curr2->next;
		curr1 = curr1->next;
	}
	curr1 = head;
	curr2 = nhead;
	while (curr1 != NULL)
	{
		curr2->random = cmap[curr1->random];
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return nhead;
}

noder* clone2(noder* head){
	noder* curr1, *curr2;
	noder* nhead = (noder*)malloc(sizeof(noder));
	nhead->value = head->value;
	nhead->next = head->next;
	curr1 = head->next;
	head->next = nhead;
	
	while (curr1 != NULL)
	{
		noder* newnode = (noder*)malloc(sizeof(noder));
		newnode->value = curr1->value;
		newnode->next = curr1->next;
		curr1->next = newnode;
		curr1 = newnode->next;
	}
	curr1 = head;
	curr2 = nhead;
	while (curr2 != NULL)
	{
		if (curr1->random==NULL)
		{
			curr2->random = NULL;
		}
		else
		{
			curr2->random = curr1->random->next;
		}
		curr1 = curr1->next->next;
		curr2 = curr2->next;
		if(curr2!=NULL)
			curr2=curr2->next;
	}
	curr1 = head;
	curr2 = nhead;
	while (curr2->next != NULL)
	{
		curr1->next = curr2->next;
		curr1 = curr1->next;
		curr2->next = curr1->next;
		curr2 = curr2->next;
		
	}
	return nhead;
}

noder* createrandom()
{
	noder* head = (noder*)malloc(sizeof(noder));
	head->value = 1;
	noder* newnode2 = (noder*)malloc(sizeof(noder));
	head->next = newnode2;
	newnode2->value = 2;
	noder *curr = newnode2;
	noder* newnode3 = (noder*)malloc(sizeof(noder));
	curr->next = newnode3;
	newnode3->value = 3;
	curr = newnode3;
	noder* newnode4 = (noder*)malloc(sizeof(noder));
	curr->next = newnode4;
	newnode4->value = 4;
	curr = newnode4;
	noder* newnode5 = (noder*)malloc(sizeof(noder));
	curr->next = newnode5;
	newnode5->value = 5;
	curr = newnode5;
	newnode5->next = NULL;


	head->random = newnode4;
	newnode2->random = newnode3;
	newnode3->random = NULL;
	newnode4->random = NULL;
	newnode5->random = newnode3;

	return head;
}

void testrandom()
{
	noder*head = createrandom();
	noder *clonehead = clone(head);
	noder *clonehead2 = clone2(head);
}