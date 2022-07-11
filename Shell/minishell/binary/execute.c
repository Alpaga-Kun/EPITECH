/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:18 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 22:42:07 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int getStatus(pid_t pid)
{
    int status = 0;

    waitpid(pid, &status, 0);
    switch (status) {
        case 139: fprintf(stderr, "Segmentation fault (core dumped)\n");
        break;
        case 136: fprintf(stderr, "Floating point exception (core dumped)\n");
        break;
        case 11: fprintf(stderr, "Segmentation fault\n");
        break;
        case 8: fprintf(stderr, "Floating point exception\n");
        break;
        default: break;
    }
    return (0);
}

int execBinary(data_shell *infoShell)
{
    pid_t pid = 0;
    struct stat stats = {0};

    stat(infoShell->exec, &stats);
    if (S_ISDIR(stats.st_mode))
        return (setErrorMessage(infoShell->commands[0], "Permission denied.", false));
    pid = fork();
    (pid == 0 ? execve(infoShell->exec, infoShell->commands, infoShell->myenv) : getStatus(pid));
    if (infoShell->exec)
        free(infoShell->exec);
    return (0);
}