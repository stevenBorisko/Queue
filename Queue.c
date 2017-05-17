#include "Queue.h"

#include <stdlib.h>

Queue Queue_init() {
	Queue ret;

	ret.front = NULL;
	ret.back = NULL;
	ret.count = 0;

	return ret;
}

Queue* Queue_create() {
	Queue* ret = malloc(sizeof(Queue));
	*ret = Queue_init();
	return ret;
}

void Queue_enqueue(Queue* queue, void* data) {
	struct QueueNode* newBack = malloc(sizeof(struct QueueNode));

	// Initialize the new node
	newBack->data = data;
	newBack->next = NULL;

	// set the back to the new node
	if(queue->back) queue->back->next = newBack;
	queue->back = newBack;

	// handle the case where this is the first node in the queue
	if(!queue->front) queue->front = newBack;

	++(queue->count);
}

void* Queue_dequeue(Queue* queue) {
	struct QueueNode* newFront = queue->front->next;
	void* ret = queue->front->data;

	free(queue->front);

	// Handle the case where this is the last node in the queue
	if(!newFront) queue->back = NULL;

	// move the front back a node
	queue->front = newFront;

	--(queue->count);

	return ret;
}

void* Queue_front(const Queue* queue) {
	return queue->front->data;
}

void* Queue_back(const Queue* queue) {
	return queue->back->data;
}

int Queue_isEmpty(const Queue* queue) {
	return !(queue->front);
}

unsigned int Queue_count(const Queue* queue) {
	return queue->count;
}

void Queue_clear(Queue* queue, void (*destroy)(void*)) {
	struct QueueNode* frontNext;
	while(queue->front) {
		// destroy the data inside the front node
		if(queue->front->data) (*destroy)(queue->front->data);
		// free the front node and set it to the next node
		frontNext = queue->front->next;
		free(queue->front);
		queue->front = frontNext;
	}

	// reset values
	queue->back = NULL;
	queue->count = 0;
}
