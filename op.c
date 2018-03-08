/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:44:35 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op    op_tab[NBR_OP + 1] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
            "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
            "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
            "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
            "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
            "store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
            "long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

t_ins   *get_ins(char *str, t_has_l_a *has_l_a)
{
    int op;
    int nbr_params;
    int len;
    char *op_str;

    if (!(op_str = get_op_str(str)) || !(op = get_op(op_str)))
        return (NULL);
    ft_strdel(&op_str);
    len = ft_strlen((const char *)op_tab[op - 1].op_name);
    has_l_a->has_abc = op_tab[op - 1].has_abc;
    while (len--)
        str++;
    while (str && *str && *str != ' ' && *str != '\t')
        str++;
    while (str && *str && (*str == ' ' || *str == '\t'))
        str++;
    nbr_params = op_tab[op - 1].nbr_params;
    if (nbr_params && !str)
        return (NULL);
    return (get_params(str, nbr_params, op));
}


char    *get_op_str(char *str)
{
    int     i;
    t_ins   *ins;
    char    *dest;

    i = 0;
    while (str && str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    if (!(dest = ft_memalloc(i + 1)) || !(dest = ft_strncpy(dest, str, i)))
        return (NULL);
    dest[i] = '\0';
    return (dest);
}

t_ins   *get_params(char *str, int nbr_params, int op)
{
    char *arg1;
    char *arg2;
    char *arg3;

    arg1 = NULL;
    arg2 = NULL;
    arg3 = NULL;
    if (nbr_params >= 1)
    {
        arg1 = get_arg(str);
        str = str + ft_strlen(arg1) + 1;
    }
    if (nbr_params >= 2)
    {
        arg2 = get_arg(str);
        str = str + ft_strlen(arg2) + 1;
    }
    if (nbr_params == 3)
    {
        arg3 = get_arg(str);
        str = str + ft_strlen(arg3) + 1;
    }
    return (new_ins(op, arg1, arg2, arg3));
}

char    *get_arg(char *str)
{
    int     i;
    char    *arg;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i] && str[i] != SEPARATOR_CHAR && str[i] != ' ' && str[i] != '\t')
        i++;
    if (!(arg = ft_memalloc(i + 1)) || !(arg = ft_strncpy(arg, str, i)))
        return (NULL);
    arg[i] = '\0';
    return (arg);
}

int     get_op(char *str)
{
    int i;

    i = 0;
    while(i < NBR_OP)
    {
        if (!ft_strcmp(str, op_tab[i].op_name))
        {
            return (op_tab[i].opcode);
        }
        i++;
    }
    return (ZERO);
}