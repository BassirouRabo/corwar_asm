#ifndef INS_H
# define INS_H

# include "header.h"
# include "ins.h"

typedef struct      s_ins
{
    int             op;
    char            *arg1;
    char            *arg2;
    char            *arg3;
    char			*acb;
}                   t_ins;

t_ins   *new_ins(int op, char *arg1, char *arg2, char *arg3);
void    ins_free(t_ins *ins);

#endif
