/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:46:48 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 20:12:08 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct data_shell_s
{
    char **myenv;
    char **commands;
} data_shell;

/* ░░░░░░░░░░░░░░░░░ ERROR ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
void errorMessage(char const *msg, int exitStatus);
/* ░░░░░░░░░░░░░░░░░ TOOLS ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
char **wordsArray(char *line, char const *delim);
void freeTabs(char **tabs);
void displayTabs(char **tabs);
size_t sizeTab(char **tabs);
/* ░░░░░░░░░░░░░░░░░ INITIALISATION ░░░░░░░░░░░░░░░░░ */
void initializer(char **env, data_shell *infoShell);
data_shell *structure(char **env);
void freeStructure(data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░ CORE SYSTEM ░░░░░░░░░░░░░░░░░░░░░ */
int coreSystem(data_shell *infoShell);

