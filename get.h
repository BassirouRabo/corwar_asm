#ifndef GET_H
# define GET_H

# include "header.h"
# include "queue.h"
# include "utils.h"
# include "set.h"
# include "op.h"

int         get_header(header_t *header, char *str);
t_queue     *get_instruction(char *str);

#endif
