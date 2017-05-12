#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
	void* data;
	struct QueueNode* next;
	struct QueueNode* prev;
};

typedef struct {
	struct QueueNode* front;
	struct QueueNode* back;
	unsigned int count;
}Queue;

Queue Queue_create();

// Inserts a new element to the back of the queue
void Queue_enqueue(Queue* queue, void* data);

// Removes the element at the front of the queue and returns it
void* Queue_dequeue(Queue* queue);

// Returns the front of the queue
void* Queue_front(const Queue* queue);

// Returns the back of the queue
void* Queue_back(const Queue* queue);

// Returns whether the queue is empty
int Queue_isEmpty(const Queue* queue);

// Returns the number of elements in the queue
unsigned int Queue_count(const Queue* queue);

// Destroys all elements from the stack (freeing the data within the nodes)
// Second parameter is a function that destroys the 'data' member of elements
void Queue_clear(Queue* queue, void (*destroy)(void*));

#endif
