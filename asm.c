#include "asm.h"

void        assemble(t_queue *head, header_t **header)
{
    while (head)
    {
        printf("%s\t%d\t[%s]\t[%s]\t[%s]\n", head->label, head->ins->op, head->ins->arg1,  head->ins->arg2,  head->ins->arg3);
        head = head->next;
    }
}
