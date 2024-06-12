#include "queue_wrapper.h"
#include "queue.h"
//#include <stdio.h>
//#include <stdlib.h>

#include "q_mem_obj_def.h"

int RECV1()
{

    return dequeueINT32(q6);
}

int RECV2()
{

    return dequeueINT32(q1e);
}
