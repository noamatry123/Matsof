//a queue node.
typedef struct Q_Node {
	int value;
	struct Q_Node* next;
	struct queue* holder;
}Q_Node;
typedef struct queue {
	int length;
	Q_Node* head;
	Q_Node* tail;
}queue;
//Seif 1:
void Qinit(queue* que);
//Seif 2:
void Qdestruct(queue* que);
//Seif 3:
void Qpush_back(queue* que, int value);
//Seif 4:
int Qpop_back(queue* que);
//Seif 5:
int Qget_length(queue* que);
//Seif 6:
int Qpeek(queue* que);
