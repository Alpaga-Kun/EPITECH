/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:03:07 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/09/14 15:10:11 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int pidZero(char ***contains, int pipefds[2], int *d)
{
    close(pipefds[0]);
    if (contains[*d + 1] != NULL)
        dup2(pipefds[1], 1);
    if (execve(contains[*d][0], contains[*d], NULL) == -1)
        close(pipefds[0]);
    return (0);
}

int pipeExecution(char ***contains, int *d)
{
    pid_t pid = 0;
    int status = 0;
    int pipefds[2] = {0};

    if (!contains[*d])
        return (0);
    pipe(pipefds);
    pid = fork();
    if (pid == 0)
        pidZero(contains, pipefds, d);
    else {
        close(pipefds[1]);
        (*d)++;
        dup2(pipefds[0], 0);
        pipeExecution(contains, d);
        waitpid(pid, &status, 0);
        close(pipefds[1]);
    }
    return (0);
}

int thePipe(data_shell *infoShell)
{
    int j = 0;
    int d = 0;
    char ***contains = malloc(sizeof(char **) * (sizeTab(infoShell->commands) + 1));

    for (; infoShell->commands[j] != NULL; j++) {
        infoShell->commandsPipe = wordsArray(infoShell->commands[j], " \t\n");
        infoShell->commandsPipe[0] = findPath(infoShell, false);
        contains[j] = infoShell->commandsPipe;
    }
    contains[j] = NULL;
    pipeExecution(contains, &d);
    for (int i = 0; contains[i] != NULL; i++)
        freeTabs(contains[i]);
    free(contains);
}