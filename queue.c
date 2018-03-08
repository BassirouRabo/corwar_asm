#include "queue.h"

t_queue			*queue_new(t_has_l_a has_l_a, int size, char *acb, char *ins)
{
	t_queue	*node;

	if (!acb)
		return (NULL);
	if (!(node = ft_memalloc(sizeof(t_queue))))
		return (NULL);
	if (!(node->ins = ft_memalloc(ft_strlen(ins) + 1)))
		return (NULL);
    if (!(node->acb = ft_memalloc(ft_strlen(acb) + 1)))
        return (NULL);
	ft_strcpy(node->ins, (const char*)ins);
    ft_strcpy(node->acb, (const char*)acb);
    node->has_l_a.l = has_l_a.l ? has_l_a.l : FALSE;
    node->has_l_a.a = has_l_a.a ? has_l_a.a : FALSE;
	node->size = size;
	node->next = NULL;
	return (node);
}

t_queue			*queue_enqueue(t_queue *head, t_queue *node)
{
	t_queue *cursor;

	if (!node)
		return (head);
	if (!head)
		return (node);
	cursor = head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	return (head);
}

t_queue			*queue_dequeue(t_queue *head)
{
	t_queue	*cpy;

	if (!head)
		return (NULL);
	if (!head->next)
	{
		ft_strdel(&head->ins);
		ft_strdel(&head->acb);
		ft_memdel((void **)&head);
		return (NULL);
	}
	cpy = head;
	while (head->next->next)
		head = head->next;
    ft_strdel(&head->next->ins);
	ft_strdel(&head->next->acb);
	ft_memdel((void **)head->next);
	return (cpy);
}

int				queue_len(t_queue *head)
{
	int		i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int				queue_find(t_queue *head, char *acb)
{
	while (head)
	{
		if (!ft_strcmp(head->acb, acb))
			return (1);
		head = head->next;
	}
	return (0);
}
