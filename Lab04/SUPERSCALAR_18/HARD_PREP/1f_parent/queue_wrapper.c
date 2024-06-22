#include "queue_wrapper.h"
// #include <stdlib.h>
#include "../lib/queue.h"
#include "../lib/q_mem_obj_def.h"


// Queue *qa_fn;
// Queue *qe;

void init_queues()
{
    // qa_fn = InitQueue("qa_fn", 'd');
    // qe = InitQueue("qe", 'd');
}

void close_queues()
{
    // CloseQueue(qa_fn);
    // CloseQueue(qe);
}

// int RECV1()
// {
//     return dequeueINT32(qa_fn);
// }

int RECV2()
{
    return dequeueINT32(qe);
}