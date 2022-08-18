/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtowordarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:57:08 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 18:39:39 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static bool detect(char const c, char const *delim)
{
    for (int i = 0; delim[i] != '\0'; i++)
        if (c == delim[i])
            return (true);
    return (false);
}

static size_t wordsize(char const *s, char const *delim, int i)
{
    int lenght = 0;

    for (; detect(s[i], delim) == false && s[i] != '\0'; i++, lenght++);
    return (lenght);
}

static size_t countword(char const *s, char const *delim)
{
    int words = 0;

    for (int i = 0; s[i] != '\0'; i++)
        if (detect(s[i], delim) == true && detect(s[i + 1], delim) == false)
            words++;
    return (words + 1);
}

char **sstrtowordarray(char const *s, char const *delim)
{
    int x = 0;
    int y = 0;
    char **tabs = NULL;

    if (!s || !(tabs = malloc(sizeof(char *) * (countword(s, delim) + 1))))
        return (NULL);
    for (int i = 0; s[i] != '\0';) {
        y = 0;
        for (; detect(s[i], delim) == true && s[i] != '\0'; i++);
        tabs[x] = malloc(sizeof(char) * (wordsize(s, delim, i) + 1));
        for (; detect(s[i], delim) == false && s[i] != '\0'; i++, y++)
            tabs[x][y] = s[i];
        tabs[x][y] = '\0';
        x++;
        for (; detect(s[i], delim) == true && s[i] != '\0'; i++);
    }
    tabs[x] = NULL;
    return (tabs);
}