/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:30:54 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/16 17:13:19 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

size_t getBiggerStr(char *s1, char *s2)
{
    return (strlen(s1) > strlen(s2) ? strlen(s1) : strlen(s2));
}

int sizeStr(char *s1, char *s2)
{
    return (strlen(s1) > strlen(s2) ? LONG : \
        strlen(s1) < strlen(s2) ? SHORT : EQUAL);
}

size_t sizeTab(char **tabs)
{
    size_t lenght = 0;

    for (; tabs[lenght] != NULL; lenght++);
    return (lenght);
}
