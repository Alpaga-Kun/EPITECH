/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:30:54 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/06 08:50:00 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int sizeStr(char *s1, char *s2)
{
    return (strlen(s1) > strlen(s2) ? LONG : strlen(s1) < strlen(s2) ? SHORT : EQUAL);
}

size_t sizeTab(char **tabs)
{
    size_t lenght = 0;

    for (; tabs[lenght] != NULL; lenght++);
    return (lenght);
}