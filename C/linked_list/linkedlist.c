#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
void init(linkedList* list)
{
	list->head = 0; //VS wont let me use nullptr ;p
	list->length = 0;
	list->sum = 0;
	list->tail = 0; //same^
}
void destruct(linkedList* list)
{
	LL_Node* currNode = list->head;
	while (currNode)
	{
		LL_Node* to_destruct = currNode;
		currNode = currNode->next;
		free(to_destruct);
	}
}
void push_back(linkedList* list,  int value) //most of the work is on this function
{
	LL_Node* newNode = (LL_Node*)malloc(sizeof(LL_Node));
	newNode->prev = list->tail;
	newNode->holder = list;
	newNode->next = 0;
	newNode->value = value;
	if (list->tail) //check if it is NOT the first item appended
		list->tail->next = newNode;
	else //update HEAD if its the first item.
		list->head = newNode;
	list->tail = newNode;

	//remember to update sum and length for easier calculation.
	list->sum += value;
	list->length++;
}
void remove_specific(LL_Node* node) //alot of "edge cases" (better translation?)
{
	linkedList* holder = node->holder; //for calculations.
	holder->sum -= node->value;
	holder->length--;
	if (node->next && node->prev) //from somewhere in the center.
		node->next->prev = node->prev, node->prev->next = node->next, free(node); //make sure to free memory.
	else if (node->next && !node->prev) //deleting the HEAD
		holder->head = node->next, node->next->prev = 0, free(node);
	else if (node->prev && !node->next) //deleting the TAIL
		holder->tail = node->prev, node->prev->next = 0, free(node);

}
int get_length(linkedList* list)
{
	return list->length;
}
LL_Node* get_head(linkedList* list)
{
	return list->head;
}
LL_Node* get_tail(linkedList* list)
{
	return list->tail;
}
LL_Node* get_next(LL_Node* node)
{
	return node->next;
}
LL_Node* get_prev(LL_Node* node)
{
	return node->prev;
}
int get_value(LL_Node* node)
{
	return node->value;
}
float get_avg(linkedList* list)
{
	return (float)list->sum / list->length;
}