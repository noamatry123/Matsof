//a linkedList node.
typedef struct LL_Node {
	int value;
	struct LL_Node* next;
	struct LL_Node* prev;
	struct linkedList* holder;
}LL_Node;
typedef struct linkedList {
	int sum;
	int length;
	LL_Node* head;
	LL_Node* tail;
}linkedList;
//Seif 1:
void init(linkedList* list);
//Seif 2:
void destruct(linkedList* list);
//Seif 3:
void push_back(linkedList* list, int value);
//Seif 4:
void remove_specific(LL_Node* node);
//Seif 5:
int get_length(linkedList* list);
//Seif 6:
LL_Node* get_head(linkedList* list);
//Seif 7:
LL_Node* get_tail(linkedList* list);
//Seif 8:
LL_Node* get_next(LL_Node* node);
//Seif 9:
LL_Node* get_prev(LL_Node* node);
//Seif 10:
int get_value(LL_Node* node);
//Seif 11:
float get_avg(linkedList* list);
//phew.