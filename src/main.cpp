#include <bits/stdc++.h>

#define ARRAY_BASED_QUEUE
#include "queue.cpp"

using namespace std;

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