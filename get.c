#include "get.h"

int         get_header(header_t *header, char *str)
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

t_queue     *get_instruction(char *str)
{
    t_queue     *node;
    int         res;
    char        *label;
    t_has_l_a   *has_l_a;
    t_ins       *ins;

    res = 0;
    label = NULL;
    if (!(has_l_a = (t_has_l_a *)ft_memalloc(sizeof(t_has_l_a))))
        return (NULL);
    has_l_a->has_label = FALSE;
    while (str && *str && (*str == '\t' || *str == ' '))
        str++;
    if ((res = has_label(str)))
    {
        if (!(label = ft_memalloc(res + 1)) || !(label = ft_strncpy(label, str, res)))
            return (NULL);
        str = str + res + 1;
        while (str && *str && (*str == '\t' || *str == ' '))
            str++;
        has_l_a->has_label = TRUE;
    }
    if (str && *str && !(ins = get_ins(str, has_l_a)))
        return (NULL);
    return (queue_new(has_l_a, label, 0, ins));
}
