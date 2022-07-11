/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:07:17 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 21:26:48 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool notOnlyDelimiter(char const *line, char const *delim)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (isprint(line[i]) && isalnum(line[i]))
            return (true);
    return (false);
}