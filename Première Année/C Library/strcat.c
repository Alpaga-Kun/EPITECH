/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:25:58 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 18:40:52 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "library.h"

char *sstrcat(char const *dest, char const *src)
{
    int k = 0;
    char *new = NULL;

    if (!dest || !src)
        return (NULL);
    if (!(new = malloc(sizeof(char) * (sstrlen(dest) + sstrlen(src) + 1))))
        return (NULL);
    for (int i = 0; dest[i] != '\0'; i++, k++)
        new[k] = dest[i];
    for (int j = 0; src[j] != '\0'; j++, k++)
        new[k] = src[j];
    new[k] = '\0';
    return (new);
}