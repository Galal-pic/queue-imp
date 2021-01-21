#ifdef ARRAY_BASED_QUEUE

# define Maxsize 100
typedef struct queue
{
    int _front,_rear,_count;
    int arr [Maxsize];
 
} Queue;
void new_Queue(Queue *q);
bool isempty(Queue* q);
bool isfull(Queue* q);
int QueueSiz(Queue* q);
void enqueue (int  ele, Queue* q);
void dequeue(int *pe, Queue* q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *QueuePtr, void(*pf)(int));

#else

#define Maxsize 10000
struct QuqueNode
{
    int  value ;
    QuqueNode* Next ;
};
struct Quque
{
    QuqueNode* _front ;
    QuqueNode* _rear ;
    int _size ;
};

void new_queue(Quque *quque);
bool isempty(Quque *quque);
bool isfull(Quque *quque);
int QuqueSize(Quque *quque);
void enqueu( Quque *quque, int Value );
int _deque(Quque *quque);
void ClearQuque(Quque *quque);
void traverse(Quque *quque, void (*function)(int  element));
void show (int  value );

#endif