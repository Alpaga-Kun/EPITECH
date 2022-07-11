/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreSystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:01:02 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 20:15:07 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int coreSystem(data_shell *infoShell)
{
    size_t len = 0;
    char *line = NULL;

    fprintf(stdout, "$> ");
    while (getline(&line, &len, stdin) != EOF) {
        fprintf(stdout, "%s\n", line);
        infoShell->commands = wordsArray(line, " \t\n");
        freeTabs(infoShell->commands);
        fprintf(stdout, "$> ");
    }
    if (line)
        free(line);
}