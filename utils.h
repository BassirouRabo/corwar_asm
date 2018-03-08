#ifndef UTILS_H
# define UTILS_H

# include "header.h"
# include "print.h"
# include "op.h"

int     return_error(header_t **header);
char    *ft_concat(char *dest, char *str, int len);
int     has_label(char *str);

#endif
