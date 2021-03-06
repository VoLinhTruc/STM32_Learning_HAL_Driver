/*
 * Snake_Queue.c
 *
 *  Created on: May 10, 2020
 *      Author: Bico
 */

#include "Snake_Queue.h"

void SQ(SQ_t* _sq, SQ_ELEMENT_TYPE* _sq_array, SQ_INDEX_TYPE _sq_array_size)
{
	_sq->SQ_array = _sq_array;
	_sq->SQ_array_size = _sq_array_size;
	_sq->SQ_head = 0;
	_sq->SQ_tail = 0;
#ifdef USE_OPTIONAL_VARIABLE
	_sq->SQ_feed_buffer = 0;
#endif
}

void SQEnqueue(SQ_t* _sq, SQ_ELEMENT_TYPE _element_in)
{
	_sq->SQ_array[_sq->SQ_head] = _element_in;

	_sq->SQ_head = (_sq->SQ_head + 1) % _sq->SQ_array_size;
	if(_sq->SQ_head == _sq->SQ_tail)
	{
		_sq->SQ_tail = (_sq->SQ_tail + 1) % _sq->SQ_array_size;
	}
}

SQ_Dequeue_State SQDequeue(SQ_t* _sq, SQ_ELEMENT_TYPE* _element_out)
{
	if(_sq->SQ_tail != _sq->SQ_head)
	{
		if(_element_out != 0)
		{
			*_element_out = _sq->SQ_array[_sq->SQ_tail];
		}
		_sq->SQ_tail = (_sq->SQ_tail + 1) % _sq->SQ_array_size;

		return SQ_DEQUEUE_SUCCESS;
	}
	else
	{
		return SQ_NOT_AVAILABLE_TO_DEQUEUE;
	}
}

SQ_INDEX_TYPE SQAvailable(SQ_t* _sq)
{
	if(_sq->SQ_head >= _sq->SQ_tail)
	{
		return _sq->SQ_head - _sq->SQ_tail;
	}
	else
	{
		return (_sq->SQ_array_size - (_sq->SQ_tail - _sq->SQ_head));
	}
}

SQ_Peek_State SQPeek(SQ_t* _sq, SQ_ELEMENT_TYPE* _element_out)
{
	if(_sq->SQ_tail != _sq->SQ_head)
	{
		if(_element_out != 0)
		{
			*_element_out = _sq->SQ_array[_sq->SQ_tail];
		}

		return SQ_DEQUEUE_SUCCESS;
	}
	else
	{
		return SQ_NOT_AVAILABLE_TO_DEQUEUE;
	}
}

SQ_INDEX_TYPE SQDequeueAll(SQ_t* _sq, SQ_ELEMENT_TYPE* _element_out, SQ_INDEX_TYPE max_dequeue)
{
	SQ_INDEX_TYPE num_of_dequeue = 0;

	while (SQAvailable(_sq) > 0)
	{
		SQDequeue(_sq, _element_out++);

		num_of_dequeue++;
		if (num_of_dequeue == max_dequeue)
			break;
	}

	return num_of_dequeue;
}
