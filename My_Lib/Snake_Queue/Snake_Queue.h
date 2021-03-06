/*
 * Snake_Queue.h
 *
 *  Created on: May 10, 2020
 *      Author: Bico
 */

#ifndef INC_SNAKE_QUEUE_H_
#define INC_SNAKE_QUEUE_H_

#define SQ SQ

#define USE_OPTIONAL_VARIABLE
#define USE_OPTIONAL_FUNCTION
//#define SQ_ONE_ELEMENT_UNIT_FOR_HEAD 1

typedef unsigned char SQ_ELEMENT_TYPE;
typedef unsigned long SQ_INDEX_TYPE;

typedef enum
{
	SQ_DEQUEUE_SUCCESS,
	SQ_NOT_AVAILABLE_TO_DEQUEUE
}SQ_Dequeue_State, SQ_Peek_State;

typedef struct
{
	SQ_ELEMENT_TYPE* SQ_array;
	SQ_INDEX_TYPE SQ_array_size;
	SQ_INDEX_TYPE SQ_head;
	SQ_INDEX_TYPE SQ_tail;
#ifdef USE_OPTIONAL_VARIABLE
	volatile SQ_INDEX_TYPE SQ_feed_buffer;
#endif //USE_OPTIONAL_VARIABLE
}SQ_t;

void				SQ(SQ_t* _sq, SQ_ELEMENT_TYPE* _sq_array, SQ_INDEX_TYPE _sq_array_size);
void				SQEnqueue(SQ_t* _sq, SQ_ELEMENT_TYPE _element_in);
SQ_Dequeue_State	SQDequeue(SQ_t* _sq, SQ_ELEMENT_TYPE* _element_out);
SQ_INDEX_TYPE 		SQAvailable(SQ_t* _sq);
#ifdef USE_OPTIONAL_FUNCTION
SQ_Peek_State		SQPeek(SQ_t* _sq, SQ_ELEMENT_TYPE* _element_out);
SQ_INDEX_TYPE		SQDequeueAll(SQ_t* _sq, SQ_ELEMENT_TYPE* _element_out, SQ_INDEX_TYPE max_dequeue);
#endif //USE_OPTIONAL_FUNCTION


#endif /* INC_SNAKE_QUEUE_H_ */
