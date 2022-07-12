/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:31:36 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/12 10:02:17 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int unsetenvSystem(data_shell *infoShell)
{
    int j = 0;
    char **tabs = NULL;

    if (!infoShell->commands[1])
        return (-1);
    if (!(tabs = malloc(sizeof(char **) * (sizeTab(infoShell->myenv)))))
        quitMessage("malloc()", 84);
     for (int i = 0; infoShell->myenv[i] != NULL; i++) {
        if (strncmp(infoShell->myenv[i], infoShell->commands[1], strlen(infoShell->commands[1])) == 0)
            continue;
        else {
            tabs[j] = strdup(infoShell->myenv[i]);
            j++;
        }
    }
    tabs[j] = NULL;
    freeTabs(infoShell->myenv);
    infoShell->myenv = tabs;
    return (0);
}