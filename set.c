#include "set.h"

char    *set_header(header_t *header, char *str, char *value, int len)
{
    char *dest;

    dest = NULL;
    while (*value == *str++)
        value++;
    if (*value)
        return (NULL);
    while (str && *str && *str == ' ')
        str++;
    if (!str || !*str || *str++ != '"')
        return (NULL);
    while (str && *str && *str != '"')
        dest = ft_concat(dest, str++, 1);
    if (!str || !*str || *str++ != '"')
        return (NULL);
    while (str && *str)
        if (*str++ != ' ')
            return (NULL);
    if (ft_strlen(dest) > len)
        return (NULL);
    return (dest);
}
