#ifndef QUEUE_H
#define QUEUE_H

/*
var	data	(void*)
	the data stored in the queue
var	next	(struct QueueNode*)
	one node closer to the back of the queue
	i.e. the next node in line

Wrapper struct for storing data in a Queue
*/
struct QueueNode {
	void* data;
	struct QueueNode* next;
};

/*
var	front	(struct QueueNode*)
	the front of the queue, i.e. the next element to be dequeued
var	back	(struct QueueNode*)
	the back of the queue, i.e. the last element that was enqueued
var	count	(unsigned int)
	the number of elements in the queue

FIFO data structure. Functions found below
*/
typedef struct {
	struct QueueNode* front;
	struct QueueNode* back;
	unsigned int count;
}Queue;

/*
return		(Queue)
	initialized Queue

Creates a Queue and initializes it to an empty queue
*/
Queue Queue_init();

/*
return		(Queue*)
	malloc'ed and initialized Queue

Allocates space for and initializes a Queue
*/
Queue* Queue_create();

/*
param	queue	(Queue*)
	queue to which p:data will be enqueued
param	data	(void*)
	data to be enqueued to p:queue
return		(void)

Inserts a new element to the back of the queue
*/
void Queue_enqueue(Queue* queue, void* data);

/*
param	queue	(Queue*)
	queue from which the return value will be dequeued
return		(void*)
	data dequeued from p:queue

Removes the element at the front of the queue and returns it
*/
void* Queue_dequeue(Queue* queue);

/*
param	queue	(const Queue*)
	queue to be inspected
return		(void*)
	the next object to be dequeued from p:queue

Returns the front of the queue
*/
void* Queue_front(const Queue* queue);

/*
param	queue	(const Queue*)
	queue to be inspected
return		(void*)
	the last object that was enqueued to p:queue

Returns the back of the queue
*/
void* Queue_back(const Queue* queue);

/*
param	queue	(const Queue*)
	queue to be inspected
return		(int)
	whether the p:queue contains any elements

Returns whether the queue is empty
*/
int Queue_isEmpty(const Queue* queue);

/*
param	queue	(const Queue*)
	queue to be inspected
return		(unsigned int)
	count of all the elements in p:queue

Returns the number of elements in the queue
*/
unsigned int Queue_count(const Queue* queue);

/*
param	queue	(Queue*)
	queue to be cleared
param	destroy	(void (void*))
	function that handles the freeing of v:data in each element of p:queue

Empties the queue
*/
void Queue_clear(Queue* queue, void (*destroy)(void*));

#endif
