#include "ins.h"

t_ins   *new_ins(int op, char *arg1, char *arg2, char *arg3)
{
    t_ins   *node;
    node = NULL;
    if (!op)
        return (NULL);
    if (!(node = (t_ins *)ft_memalloc(sizeof(t_ins))))
        return (NULL);
    if (!(node->arg1 = ft_memalloc(ft_strlen(arg1) + 1))
        || !(node->arg2 = ft_memalloc(ft_strlen(arg2) + 1))
        || !(node->arg3 = ft_memalloc(ft_strlen(arg3) + 1)))
		return (NULL);
    node->op = op;
    if (arg1)
        ft_strcpy(node->arg1, (const char*)arg1);
    if (arg2)
        ft_strcpy(node->arg2, (const char*)arg2);
    if (arg3)
        ft_strcpy(node->arg3, (const char*)arg3);
    node->acb = NULL;
    return (node);
}

void    ins_free(t_ins *ins)
{
    if (!ins)
        return ;
    ft_strdel(&ins->arg1);
    ft_strdel(&ins->arg2);
    ft_strdel(&ins->arg3);
    ft_strdel(&ins->acb);
    ft_memdel((void **)&ins);
}