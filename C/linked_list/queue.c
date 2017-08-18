#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
void Qinit(queue* que)
{
	que->head = 0; //VS wont let me use nuQptr ;p
	que->length = 0;
	que->tail = 0;
}
void Qdestruct(queue* que)
{
	Q_Node* currNode = que->head;
	while (currNode)
	{
		Q_Node* to_destruct = currNode;
		currNode = currNode->next;
		free(to_destruct);
	}
}
void Qpush_back(queue* que,  int value) //most of the work is on this function
{
	Q_Node* newNode = (Q_Node*)malloc(sizeof(Q_Node));
	newNode->holder = que;
	newNode->next = 0;
	newNode->value = value;
	if (que->tail) //check if it is NOT the first item appended
		que->tail->next = newNode;
	else //update HEAD if its the first item.
		que->head = newNode;
	que->tail = newNode;

	//remember to update length for easier calculation.
	que->length++;
}
int Qpop_back(queue* que) //alot of "edge cases" (better translation?)
{
	int returnval = -1;
	que->length--;
	if (que->head) //make sure i dont kill null.
	{
		Q_Node* node = que->head;
		if (que->head->next) //if its not the only item
			que->head = que->head->next;
		returnval = node->value;
		free(node);
	}
	return returnval;
}
int Qget_length(queue* que)
{
	return que->length;
}
int Qpeek(queue* que)
{
	return que->head->value;
}