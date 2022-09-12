/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreSystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:01:02 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/09/12 16:00:17 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void prompt(data_shell *infoShell)
{
    char newPath[PATH_MAX] = {0};
    fprintf(stdout, "🐾 \033[35m\033[1m%s 🐾 \033[37m\033[1m(\033[36m\033[1m%s\033[37m\033[1m) ~>\033[0m ", \
        infoShell->user, getcwd(newPath, sizeof(newPath)));
}

int coreSystem(data_shell *infoShell)
{
    size_t len = 0;
    char *line = NULL;
    char newPath[PATH_MAX] = {0};

    if (isatty(0))
        prompt(infoShell);
    while (getline(&line, &len, stdin) != EOF) {
        if (strlen(line) <= 1 || notOnlyDelimiter(line, " \t\n") == false && isatty(0)) {
            prompt(infoShell);
            continue;
        }
        if (strncmp(line, "exit", 4) == 0)
            break;
        infoShell->commands = wordsArray(line, " \t\n");
        (infoShell->commands != NULL ? searchSystem(infoShell) : 0);
        freeTabs(infoShell->commands);
        if (isatty(0))
            prompt(infoShell);
    }
    if (line)
        free(line);
    return (0);
}