#include <bits/stdc++.h>
using namespace std;
# define Maxsize 100
typedef struct queue
{
    int _front,_rear,_count;
    int arr [Maxsize];
 
} Queue;
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
int main()
{
    Queue q;
    new_Queue(&q);
    enqueue(1, &q);
    enqueue(2, &q);
    cout<<QueueSiz(&q)<<"\n";
    enqueue(3, &q);
    cout<<QueueSiz(&q)<<"\n";
 
    return 0;
}