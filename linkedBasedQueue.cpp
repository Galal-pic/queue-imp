#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    Quque q ;
    new_queue(&q) ;
    enqueu(&q, 5) ;
    enqueu(&q, 6) ;
    enqueu(&q, 7) ;
    cout<<_deque(&q)<<endl;
    traverse(&q, show) ;
    return 0;
}
