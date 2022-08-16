/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:29:14 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/16 17:14:19 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

char *strrev(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
        return (str);
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return (str);
}

char * removeSpacesFromStr(char *string)
{
    int non_space_count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') {
            string[non_space_count] = string[i];
            non_space_count++;
        }
    }
    string[non_space_count] = '\0';
    return (string);
}
