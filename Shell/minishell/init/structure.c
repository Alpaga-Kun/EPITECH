/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:54:41 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 20:37:44 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

data_shell *structure(char **env)
{
    data_shell *new = malloc(sizeof(data_shell));

    if (!new)
        errorMessage("malloc()", 84);
    new->exec = NULL;
    new->commands = NULL;
    initializer(env, new);
    return (new);
}

void freeStructure(data_shell *infoShell)
{
    freeTabs(infoShell->myenv);
    if (infoShell)
        free(infoShell);
}