/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:28:11 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:12:36 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

size_t sstrlen(char const *s)
{
    size_t lenght = 0;

    if (!s)
        return (0);
    for (; s[lenght] != '\0'; lenght++);
    return (lenght);
}
