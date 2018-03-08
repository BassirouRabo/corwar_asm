#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include "header.h"
# include "get_next_line/get_next_line.h"
# include "print.h"
# include "get.h"
# include "asm.h"
# include "utils.h"

int     return_error(header_t **header);
void    parse_file(const int fd, header_t **header, char *str);
int     main(int argc, char **argv);

#endif
