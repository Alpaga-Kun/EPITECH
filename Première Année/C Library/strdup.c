/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:04:57 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:52:58 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char *sstrdup(char const *todup)
{
    int i = 0;
    char *s = NULL;

    if (!(s = malloc(sizeof(char) * (sstrlen(todup) + 1))))
        return (NULL);
    for (; todup[i] != '\0'; i++)
        s[i] = todup[i];
    s[i] = '\0';
    return (s);
}