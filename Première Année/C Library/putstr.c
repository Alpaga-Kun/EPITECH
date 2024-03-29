/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:25:31 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:03:22 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void pputstr(char const *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        pputchar(s[i]);
}
