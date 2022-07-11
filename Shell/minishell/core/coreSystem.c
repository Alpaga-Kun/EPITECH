/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreSystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:01:02 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 21:00:24 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int coreSystem(data_shell *infoShell)
{
    size_t len = 0;
    char *line = NULL;

    if (isatty(0))
        fprintf(stdout, "$> ");
    while (getline(&line, &len, stdin) != EOF) {
        if (isatty(0))
            fprintf(stdout, "$> ");
        if (strlen(line) <= 1)
            continue;
        infoShell->commands = wordsArray(line, " \t\n");
        (infoShell->commands != NULL ? searchSystem(infoShell) : 0);
        freeTabs(infoShell->commands);
    }
    if (line)
        free(line);
    return (0);
}