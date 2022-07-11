/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:46:48 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 22:19:28 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PATH_MAX 4096

typedef struct data_shell_s
{
    char *exec;
    char **myenv;
    char **commands;
    char *oldPath[PATH_MAX];
    char *currentPath[PATH_MAX];
} data_shell;

typedef struct ptr_builtin_s
{
    char const *builtin;
    int (*ptr)(data_shell *);
} ptrBuiltin;

/* ░░░░░░░░░░░░░░░░░ ERROR ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
int setErrorMessage(char const *command, char const *msg, bool status);
void errorMessage(char const *msg, int exitStatus);
/* ░░░░░░░░░░░░░░░░░ TOOLS ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
char **wordsArray(char *line, char const *delim);
void freeTabs(char **tabs);
void displayTabs(char **tabs);
size_t sizeTab(char **tabs);
bool notOnlyDelimiter(char const *line, char const *delim);
/* ░░░░░░░░░░░░░░░░░ INITIALISATION ░░░░░░░░░░░░░░░░░ */
void initializer(char **env, data_shell *infoShell);
data_shell *structure(char **env);
void freeStructure(data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░ CORE SYSTEM ░░░░░░░░░░░░░░░░░░░░░ */
int coreSystem(data_shell *infoShell);
int searchSystem(data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░ BUILTIN ░░░░░░░░░░░░░░░░░░░░░░░░░ */
int cdSystem(data_shell *infoShell);
int envSystem(data_shell *infoShell);
int setenvSystem(data_shell *infoShell);
int unsetenvSystem(data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░ PATH ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */
char *findPath(data_shell *infoShell);
int execBinary(data_shell *infoShell);
