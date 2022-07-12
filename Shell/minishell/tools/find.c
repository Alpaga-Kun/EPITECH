/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:50:40 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/12 08:11:06 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

char *findInEnv(char **myenv, char const *word)
{
    int j = strlen(word);

    for (int i = 0; myenv[i] != NULL; i++)
        if (strncmp(myenv[i], word, strlen(word)) == 0)
            return (strdup(&myenv[i][j]));
    return (NULL);
}