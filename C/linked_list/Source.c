#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "queue.h" //i padded all the functions with "Q" for distinction. come to think of it i couldve just overloaded them.
int main()
{
	printf("Starting up..\n");
	//new linkedlist
	linkedList list;
	init(&list);
	//push back couple items.
	push_back(&list, 1);
	push_back(&list, 2);
	push_back(&list, 3);
	push_back(&list, 4);
	//remove stuff
	remove_specific(list.head->next->next);
	//check average.
	printf("Average is: %f\n",get_avg(&list));
	//destruct
	destruct(&list);
	getchar();


	//Queue
	printf("Queue test.\n");
	queue que;
	Qinit(&que);
	//push back couple items
	Qpush_back(&que, 1);
	Qpush_back(&que, 2);
	Qpush_back(&que, 3);
	Qpush_back(&que, 4);
	//peek and pop.

	//the commented line below doesnt work and i spent way too much time on it. apparently printf calls functions in reverse order.
	//printf("peeking at first: \n%d\npopping back 2 elements:\n%d\n%d", Qpeek(&que), Qpop_back(&que), Qpop_back(&que));

	printf("peeking at first:\n%d\n", Qpeek(&que));
	printf("pop:\n%d\n", Qpop_back(&que));
	printf("pop:\n%d\n", Qpop_back(&que));
	// FOR DEBUGGER: 'que' should now be only w elements.
	return 0;
}