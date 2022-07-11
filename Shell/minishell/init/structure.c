/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:54:41 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 21:48:21 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

data_shell *structure(char **env)
{
    char newPath[PATH_MAX] = {0};
    data_shell *new = malloc(sizeof(data_shell));

    if (!new)
        errorMessage("malloc()", 84);
    if (getcwd(newPath, sizeof(newPath)) == NULL)
        errorMessage("getcwd()", 84);
    memcpy(new->oldPath, newPath, PATH_MAX);
    memcpy(new->currentPath, newPath, PATH_MAX);
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