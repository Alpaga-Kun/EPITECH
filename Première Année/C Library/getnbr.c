/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:40:34 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:56:10 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"
#include <stdio.h>

int ggetnbr(char const *s)
{
    int sign = 1;
    int result = 0;

    for (; *s == '-' || *s == '+'; s++)
        (*s == '-') ? sign = -sign : 0;
    for (; *s != '\0' && (*s >= '0' && *s <= '9'); s++) {
        if (result > __INT_MAX__ || result == __INT_MAX__ && (*s > 7 && sign == 1 || *s > 8 && sign == -1))
            return (0);
        result = result * 10 + *s - '0';
    }
    if (sign == -1)
        result = -result;
    return (result);
}