/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreSystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:01:02 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/09/14 14:23:27 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void prompt(data_shell *infoShell)
{
    char newPath[PATH_MAX] = {0};
    fprintf(stdout, "🐾 \033[35m\033[1m%s 🐾 \033[37m\033[1m(\
\033[36m\033[1m%s\033[37m\033[1m) ~>\033[0m ", \
        infoShell->user, getcwd(newPath, sizeof(newPath)));
}

static void scanner(char *line, data_shell *infoShell)
{
    for (int i = 0; line[i] != '\0'; i++)
        (line[i] == '|' ? infoShell->piped = true : \
        line[i] == '>' ? infoShell->redirect = true : \
        line[i] == ';' ? infoShell->pointvir = true : 0);
}

static int attritubeProcess(char *line, data_shell *infoShell)
{
    scanner(line, infoShell);
    if (infoShell->piped == true) {
        infoShell->commands = wordsArray(line, "|");
        return (thePipe(infoShell));
    }
    if (infoShell->pointvir == true) {
        infoShell->commands = wordsArray(line, ";");
        return (fprintf(stdout, "PointVir Function.\n"));
    }
    if (infoShell->redirect == true) {
        infoShell->commands = wordsArray(line, ">");
        return (fprintf(stdout, "Redirect Function.\n"));
    }
    infoShell->piped = false;
    infoShell->redirect = false;
    infoShell->pointvir = false;
    infoShell->commands = wordsArray(line, " \t\n");
    return (infoShell->commands != NULL ? searchSystem(infoShell) : 0);
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
        attritubeProcess(line, infoShell);
        freeTabs(infoShell->commands);
        if (isatty(0))
            prompt(infoShell);
    }
    if (line)
        free(line);
    return (0);
}