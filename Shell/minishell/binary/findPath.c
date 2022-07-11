/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:48:21 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 22:28:57 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static char *catchPath(char **newPath, char const *command)
{
    char exec[PATH_MAX] = {0};

    for (int i = 0; newPath[i] != NULL; i++) {
        sprintf(exec, "%s/%s", newPath[i], command);
        if (access(exec, X_OK) == 0) {
            freeTabs(newPath);
            return (strdup(exec));
        }
    }
    freeTabs(newPath);
    return (NULL);
}

static char **infoPath(char **myenv)
{
    char **temp = NULL;
    char lineCpy[PATH_MAX] = {0};

    for (int i = 0; myenv[i] != NULL; i++) {
        if (strncmp("PATH=", myenv[i], 5) == 0 && strlen(myenv[i]) > 7) {
            sprintf(lineCpy, "%s", myenv[i]);
            return (wordsArray(lineCpy, ":"));
        }
    }
    return (NULL);
}

char *findPath(data_shell *infoShell)
{
    char *exec = NULL;
    char **newPath = NULL;

    if (access(infoShell->commands[0], X_OK) == 0)
        return (infoShell->commands[0]);
    if ((newPath = infoPath(infoShell->myenv)) == NULL)
        return (NULL);
    if ((exec = catchPath(newPath, infoShell->commands[0])) != NULL)
        return (exec);
    return (NULL);
}