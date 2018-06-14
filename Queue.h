#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

//----------------------------------------------------------------------------//
// --- Structure Declarations ---
//----------------------------------------------------------------------------//

/*
--- struct QueueNode ---

data (void*)
	- The data stored in the queue
next (struct QueueNode*)
	- One node closer to the back of the queue
	- I.e. the next node in line

Wrapper struct for storing data in a Queue
*/
struct QueueNode {
	void* data;
	struct QueueNode* next;
};

/*
--- Queue ---

front (struct QueueNode*)
	- The front of the queue, i.e. the next element to be dequeued
back (struct QueueNode*)
	- The back of the queue, i.e. the last element that was enqueued
count (unsigned int)
	- The number of elements in the queue

FIFO data structure
*/
typedef struct {
	struct QueueNode* front;
	struct QueueNode* back;
	unsigned int count;
} Queue;

//----------------------------------------------------------------------------//
// --- Queue Function Declarations ---
//----------------------------------------------------------------------------//

/*
--- Queue_init ---

return (Queue)
	Initialized Queue

Creates a Queue and initializes it to an empty queue
*/
Queue Queue_init();

/*
--- Queue_enqueue ---

queue (Queue*)
	- Queue to which p:data will be enqueued
data (void*)
	- Data to be enqueued to p:queue

Inserts a new element to the back of the queue
*/
void Queue_enqueue(Queue* queue, void* data);

/*
--- Queue_preempt ---

queue (Queue*)
	- Queue preempted by p:data
data (void*)
	- Data to preempt p:queue

Inserts a new element to the front of the queue
*/
void Queue_preempt(Queue* queue, void* data);

/*
--- Queue_dequeue ---

queue (Queue*)
	- Queue from which the return value will be dequeued

return (void*)
	Data dequeued from p:queue

Removes the element at the front of the queue and returns it
*/
void* Queue_dequeue(Queue* queue);

/*
--- Queue_front ---

queue (const Queue*)
	- Queue to be inspected

return (void*)
	The next element to be dequeued from p:queue

Returns the front of the queue
*/
void* Queue_front(const Queue* queue);

/*
--- Queue_back ---

queue (const Queue*)
	- Queue to be inspected

return (void*)
	The last element that was enqueued to p:queue

Returns the back of the queue
*/
void* Queue_back(const Queue* queue);

/*
--- Queue_isEmpty ---

queue (const Queue*)
	- Queue to be inspected

return (int)
	Whether the p:queue contains any elements

Returns whether the queue is empty
*/
int Queue_isEmpty(const Queue* queue);

/*
--- Queue_count ---

queue (const Queue*)
	- Queue to be inspected

return (unsigned int)
	Count of all the elements in p:queue

Returns the number of elements in the queue
*/
unsigned int Queue_count(const Queue* queue);

/*
--- Queue_clear ---

queue (Queue*)
	- Queue to be cleared
destroy (void (void*))
	- Function that handles the freeing of v:data in each element of p:queue

Empties the queue
*/
void Queue_clear(Queue* queue, void (*destroy)(void*));

#endif
