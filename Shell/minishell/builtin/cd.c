/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:30:16 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/12 09:01:55 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int setPath(data_shell *infoShell, char const *path)
{
    char newPath[PATH_MAX] = {0};

    chdir(path);
    free(infoShell->oldPath);
    infoShell->oldPath = strdup(getcwd(newPath, sizeof(newPath)));
    fprintf(stdout, "[%s]\n", infoShell->oldPath);
    return (0);
}

int cdSystem(data_shell *infoShell)
{
    struct stat stats = {0};
    stat(infoShell->commands[1], &stats);

    if (strcmp(infoShell->commands[1], "-") == 0)
        return (chdir(infoShell->oldPath));
    if (strcmp(infoShell->commands[1], "~") == 0)
        return (chdir(infoShell->home));
    if (infoShell->commands[1] != NULL && access(infoShell->commands[1], R_OK) == 0 && S_ISDIR(stats.st_mode))
        return (setPath(infoShell, infoShell->commands[1]));
    return (setErrorMessage(infoShell->commands[0], ": Not a directory.", 1));
}