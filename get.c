#include "get.h"

int     get_header(header_t *header, char *str)
{
    // TODO free res
    char *res;

    if (!ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
    {
        if (ft_strlen(header->prog_name) || !(res = set_header(header, str, NAME_CMD_STRING, PROG_NAME_LENGTH)))
            return (ZERO);
        ft_strcpy(header->prog_name, res);
    }
    else if (!ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
    {
        if (ft_strlen(header->comment) || !(res = set_header(header, str, COMMENT_CMD_STRING, COMMENT_LENGTH)))
            return (ZERO);
        ft_strcpy(header->comment, res);
    }
    return (ONE);
}

t_queue *get_instrucions(t_queue **labels, char *str)
{
    t_queue *node;
    int     res;

    res = 0;
    if ((res = has_label(str)))
        printf("{%d}\t%s\n", res, str);


    //printf("%s\n", str);
  //  node = queue_new(NULL, NULL,)
   // printf("%d\n", queue_len(*labels));
    return (NULL);
}
