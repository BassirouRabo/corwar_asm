#ifndef QUEUE_H
# define QUEUE_H

# include "header.h"

typedef struct              s_has_l_a
{
    t_bool                  l;  // Label
    t_bool                  a;  // abc
}                           t_has_l_a;

typedef struct		        s_queue
{
    struct s_has_l_a        has_l_a;
    int                     size;
	char			        *acb;
    char                    *ins;
	struct s_queue	*next;
}					        t_queue;

t_queue			    *queue_new(t_has_l_a has_l_a, int size, char *acb, char *ins);
t_queue				*queue_enqueue(t_queue *head, t_queue *node);
t_queue				*queue_dequeue(t_queue *head);
int					queue_len(t_queue *head);
int					queue_find(t_queue *head, char *data);

#endif
