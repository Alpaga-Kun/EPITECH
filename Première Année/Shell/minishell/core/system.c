/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:17:20 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/09/14 14:31:15 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int searchSystem(data_shell *infoShell)
{
    ptrBuiltin buitlin[] = {
        {"cd", &cdSystem},
        {"env", &envSystem},
        {"setenv", &setenvSystem},
        {"unsetenv", &unsetenvSystem},
    };
    for (int i = 0; i != 4; i++)
        if (strcmp(infoShell->commands[0], buitlin[i].builtin) == 0)
            return (buitlin[i].ptr(infoShell));
    return ((infoShell->exec = findPath(infoShell, true)) != NULL ? \
        execBinary(infoShell) :
        setquitMessage(infoShell->commands[0], "Command not found.", 1));
    return (0);
}