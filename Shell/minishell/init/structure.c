/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:54:41 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/12 09:24:49 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

data_shell *structure(char **env)
{
    char newPath[PATH_MAX] = {0};
    data_shell *new = malloc(sizeof(data_shell));

    if (!new)
        quitMessage("malloc()", 84);
    if (getcwd(newPath, sizeof(newPath)) == NULL)
        quitMessage("getcwd()", 84);
    new->pathDir = false;
    new->exec = NULL;
    new->commands = NULL;
    new->oldPath = strdup(newPath);
    initializer(env, new);
    new->home = findInEnv(env, "HOME=");
    return (new);
}

void freeStructure(data_shell *infoShell)
{
    freeTabs(infoShell->myenv);
    free(infoShell->oldPath);
    free(infoShell->home);
    free(infoShell);
}