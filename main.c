#include "main.h"

void    parse_file(const int fd, header_t **header, char *str)
{
    t_queue   *queue;

    queue = NULL;
    while (get_next_line(fd, &str) > ZERO)
    {
        while (str && *str && *str == ' ')
            str++;
        if (str && *str &&
                (!ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
                 || !ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))))
        {
            if (!get_header(*header, str) && return_error(header))
                return ;
            continue ;
        }
        if (str && *str && *str == COMMENT_CHAR)
            continue ;
        if (str && *str && (queue = get_instrucions(&queue, str)) && return_error(header))
                return ;
    }
    asm_file(fd, queue);
}

int     main(int argc, char **argv)
{
    int         fd;
    int         i;
    header_t    *header;
    char        *str;

    i = 0;
    str = NULL;
    argc--;
    argv++;
    while (argc--)
    {
        if (!(header = ft_memalloc(sizeof(header_t *)))
            && return_error(&header))
            exit(MINUS);
        if ((fd = open(argv[i++], O_RDONLY)) == MINUS && return_error(&header))
            continue ;
        parse_file((const int)fd, &header, str);
    }
    return (ZERO);
}
