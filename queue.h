#ifndef QUEUE_H
# define QUEUE_H

# include "header.h"
# include "ins.h"

typedef struct              s_has_l_a
{
    t_bool                  has_label;
    t_bool                  has_abc;
}                           t_has_l_a;

typedef struct		        s_queue
{
    struct s_has_l_a        *has_l_a;
    char                    *label;
    int                     size;
    struct s_ins            *ins;
	struct s_queue	        *next;
}					        t_queue;

t_queue			    *queue_new(t_has_l_a *has_l_a, char *label, int size, t_ins *ins);
t_queue				*queue_enqueue(t_queue *head, t_queue *node);
t_queue				*queue_dequeue(t_queue *head);
int					queue_len(t_queue *head);
int					queue_find(t_queue *head, char *data);

#endif
