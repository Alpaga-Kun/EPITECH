/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:31:08 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:34:22 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char *sstrncat(char const *dest, char const *src, size_t n)
{
    int k = 0;
    char *new = NULL;

    if (!dest || !src)
        return (NULL);
    if (!(new = malloc(sizeof(char) * (sstrlen(dest) + n + 1))))
        return (NULL);
    for (int i = 0; dest[i] != '\0'; i++, k++)
        new[k] = dest[i];
    for (int j = 0; j != n; j++, k++)
        new[k] = src[j];
    new[k] = '\0';
    return (new);
}