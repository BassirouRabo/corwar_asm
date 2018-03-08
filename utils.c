#include "utils.h"

int    return_error(header_t **header)
{
    print_error();
    ft_memdel((void **)header);
    return (MINUS);
}

char	*ft_concat(char *dest, char *str, int len)
{
    char	*out;

    len = len ? len : ft_strlen(str);
    if (!(out = ft_memalloc((len + (dest ? ft_strlen(dest) : 0) + 1))))
        exit(ZERO);
    out = ft_strcat(out, dest);
    out = ft_strncat(out, str, len);
    free(dest);
    return (out);
}

int     has_label(char *str)
{
    int i;

    i = 0;
    while (str && *str && ++i)
    {
        while (str && *str && *str == ' ')
            str++;
        if (str && *str && *str == LABEL_CHAR)
            return (--i);
        if (!ft_strchr((const char *)LABEL_CHARS, *str++))
            return (ZERO);
    }
    return (ZERO);
}
