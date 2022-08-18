/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:36:16 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:38:02 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char *sstrcpy(char *dest, char const *src)
{
    int j = 0;

    for (int i = 0; src[i] != '\0'; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}