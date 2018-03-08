#include "queue.h"

t_queue			*queue_new(t_has_l_a *has_l_a, char *label, int size, t_ins *ins)
{
	t_queue	*node;

	if (!(node = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
    if (!(node->label = ft_memalloc(ft_strlen(label) + 1)))
        return (NULL);
    if (!(node->has_l_a = (t_has_l_a *)ft_memalloc(sizeof(t_has_l_a))))
        return (NULL);
    node->has_l_a->has_label = has_l_a->has_label;
    node->has_l_a->has_abc = has_l_a->has_abc;
    ft_strncpy(node->label, (const char*)label, ft_strlen(label));
    node->ins = ins;
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
        ins_free(head->ins);
		ft_memdel((void **)&head);
		return (NULL);
	}
	cpy = head;
	while (head->next->next)
		head = head->next;
    ins_free(head->ins);
	ft_memdel((void **)head->next);
	return (cpy);
}

int				queue_len(t_queue *head)
{
	int i;

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
	/*while (head)
	{
		if (!ft_strcmp(head->acb, acb))
			return (1);
		head = head->next;
	}*/
	return (0);
}
