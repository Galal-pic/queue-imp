#include "../include/queue.h"
using namespace std;

#ifdef ARRAY_BASED_QUEUE

void new_Queue(Queue *q)
{
    q->_front= 0;
    q->_rear= -1;
    q->_count=  0;
}
bool isempty(Queue* q)
{
    if(q->_count==0)
        return true;
    return false;
}
bool isfull(Queue* q)
{
    if(q->_count==Maxsize)
        return true;
    return false;
}
int QueueSiz(Queue* q)
{
    return q->_count;
}
/// push element
void enqueue (int  ele, Queue* q)
{
    q->_rear = (q->_rear +1 ) % Maxsize;
    q->arr[q->_rear] = ele;
    /// +1
    q->_count++;
}
///pop element
void dequeue(int *pe, Queue* q)
{
    *pe = q->arr[q->_front];
    q->_front = (q->_front + 1 ) % Maxsize;
    /// -1
    q->_count--;
}
void ClearQueue(Queue *q)
{
    q->_front = 0;
    q->_rear = -1;
    q->_count = 0;
}
void TraverseQueue(Queue *QueuePtr, void(*pf)(int))
{
    int pos, size;
    for (pos = QueuePtr->_front, size = 0; size < QueuePtr->_count; size++)
    {
        (*pf)(QueuePtr->arr[pos]);
        pos = (pos + 1) % Maxsize;
    }
}


#else
void new_queue(Quque *quque)
{
    quque->_front = NULL ;
    quque->_rear = NULL;
    quque->_size = 0;
}
bool isempty(Quque *quque)
{
    return quque->_size == 0 ;
}
bool isfull(Quque *quque)
{
    return quque->_size==Maxsize;
}
int QuqueSize(Quque *quque)
{
    return quque->_size ;
}
void enqueu( Quque *quque, int Value )
{
    QuqueNode* NewNode = new QuqueNode;
    NewNode->value = Value;
    NewNode->Next = NULL;
    if (!quque->_front)
    {
        quque->_front = NewNode;
        quque->_rear = NewNode;
    }
    else
    {
        quque->_rear->Next = NewNode;
        quque->_rear = NewNode;
    }
    quque->_size++ ;
}
int _deque(Quque *quque)
{
    quque->_size-- ;
    QuqueNode* PopedNode = new QuqueNode;
    PopedNode = quque->_front;
    quque->_front = quque->_front->Next;
    int  var =PopedNode->value ;
    delete PopedNode;
    if (!quque->_front)
        quque->_rear = NULL;
    return var ;
}
void ClearQuque(Quque *quque)
{
    QuqueNode *traversepointer =  quque->_front ;
    while(traversepointer)
    {
        QuqueNode *temppointer = traversepointer->Next ;
        delete traversepointer ;
        traversepointer = temppointer ;
    }
    quque->_front = NULL ;
    quque->_rear = NULL;
    quque->_size = 0;
}
void traverse(Quque *quque, void (*function)(int  element))
{
    QuqueNode* traverseptr =  quque->_front;
    while (traverseptr)
    {
        (*function)(traverseptr->value);
        traverseptr = traverseptr->Next;
    }
}
void show (int  value )
{
    cout<<value<<endl;
}

#endif