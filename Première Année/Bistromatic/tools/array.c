/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:05:38 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/16 17:09:44 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void freeTabs(char **tabs)
{
    if (tabs != NULL) {
        for (int i = 0; tabs[i] != NULL; i++)
            free(tabs[i]);
        free(tabs);
    }
}

void displayTabs(char **tabs)
{
    if (tabs != NULL) {
        for (int i = 0; tabs[i] != NULL; i++)
            fprintf(stdout, "%s\n", (tabs[i] != NULL ? tabs[i] : "NULL"));
    }
}

char **wordsArray(char *line, char const *delim)
{
    char *ptr = NULL;
    char **tabs = NULL;
    size_t i = 0;

    ptr = strtok(line, delim);

    while (ptr != NULL) {
        tabs = realloc(tabs, ((i + 1) * sizeof(char *)));
        tabs[i] = strdup(ptr);
        ptr = strtok(NULL, delim);
        i = i + 1;
    }
    tabs = realloc(tabs, ((i + 1) * sizeof(char *)));
    tabs[i] = NULL;
    return (tabs);
}
