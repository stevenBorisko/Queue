#include "Queue.h"

#include <stdlib.h>

Queue Queue_create() {
	Queue ret;
	ret.front = NULL;
	ret.back = NULL;
	ret.count = 0;
	return ret;
}

void Queue_enqueue(Queue* queue, void* data) {
	struct QueueNode* newBack = malloc(sizeof(struct QueueNode));
	newBack->data = data;
	newBack->next = queue->back;
	newBack->prev = NULL;
	if(queue->back) queue->back->prev = newBack;
	queue->back = newBack;
	if(!queue->front) queue->front = newBack;
	++(queue->count);
}

void* Queue_dequeue(Queue* queue) {
	struct QueueNode* newFront = queue->front->prev;
	void* ret = queue->front->data;
	free(queue->front);
	if(newFront) newFront->next = NULL;
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
	return !(queue->count);
}

unsigned int Queue_count(const Queue* queue) {
	return queue->count;
}

void Queue_clear(Queue* queue, void (*destroy)(void*)) {
	struct QueueNode* backNext;
	while(queue->back) {
		if(queue->back->data) (*destroy)(queue->back->data);
		backNext = queue->back->next;
		free(queue->back);
		queue->back = backNext;
	}
	queue->front = NULL;
	queue->count = 0;
}
