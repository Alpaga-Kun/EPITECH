/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:54:41 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/09/14 14:26:40 by Alpaga-Kun       ###   ########.fr       */
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
    new->piped = false;
    new->redirect = false;
    new->pointvir = false;
    new->exec = NULL;
    new->commands = NULL;
    new->commandsPipe = NULL;
    new->oldPath = strdup(newPath);
    initializer(env, new);
    new->home = findInEnv(env == NULL ? new->myenv : env, "HOME=");
    new->user = findInEnv(env == NULL ? new->myenv : env, "USER=");
    new->user[0] = toupper(new->user[0]);
    return (new);
}

void freeStructure(data_shell *infoShell)
{
    freeTabs(infoShell->myenv);
    free(infoShell->oldPath);
    free(infoShell->home);
    free(infoShell->user);
    free(infoShell);
}