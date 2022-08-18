/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:39:59 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 15:43:35 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static void err(char c)
{
    write(2, &c, 1);
}

void pputerror(char const *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        err(s[i]);
    exit(84);
}