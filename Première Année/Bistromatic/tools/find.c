/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:36:01 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/16 17:13:03 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

char *findOperand(char const *buffer, char const *operand)
{
    char list[4080] = {0};

    for (size_t i = 0; i < strlen(buffer); i++)
        (buffer[i] == '*' || buffer[i] == '/' || \
            buffer[i] == '+' || buffer[i] == '-' ) ?
            strncat(list, &buffer[i], 1) : 0;
    return (strdup(list));
}
