/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:31:19 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/12 09:38:26 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static bool errorSetenv(data_shell *infoShell)
{
    for (int i = 0; infoShell->commands[1][i] != '\0'; i++)
        if (isalpha(infoShell->commands[1][i]))
            return (true);
    return (false);
}

int setenvSystem(data_shell *infoShell)
{
    int j = 0;
    char **tabs = NULL;
    char variable[PATH_MAX] = {0};

    if (!infoShell->commands[1])
        return (-1);
    if (errorSetenv(infoShell) == false)
        return (setquitMessage(infoShell->commands[0], "Variable name must begin with a letter.", 1));
    if (!(tabs = malloc(sizeof(char **) * (sizeTab(infoShell->myenv) + 2))))
        quitMessage("malloc()", 84);
    (!infoShell->commands[2]) ? sprintf(variable, "%s=", infoShell->commands[1]) :
    sprintf(variable, "%s=%s", infoShell->commands[1], infoShell->commands[2]);
    for (int i = 0; infoShell->myenv[i] != NULL; i++, j++)
        tabs[j] = strdup(infoShell->myenv[i]);
    tabs[j] = strdup(variable);
    tabs[j + 1] = NULL;
    freeTabs(infoShell->myenv);
    infoShell->myenv = tabs;
    return (0);
}