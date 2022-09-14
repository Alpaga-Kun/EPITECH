/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:46:48 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/09/14 14:30:09 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PATH_MAX 4096

typedef struct data_shell_s
{
    char *exec;
    char *home;
    char *user;
    char *oldPath;
    char **myenv;
    char **commands;
    char **commandsPipe;
    bool pathDir;
    bool redirect;
    bool pointvir;
    bool piped;
} data_shell;

typedef struct ptr_builtin_s
{
    char const *builtin;
    int (*ptr)(data_shell *);
} ptrBuiltin;

/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ERROR ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
void quitMessage(char const *msg, int exitStatus);
int setquitMessage(char const *command, char const *msg, int returnStatus);
/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ TOOLS ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
void freeTabs(char **tabs);
size_t sizeTab(char **tabs);
void displayTabs(char **tabs);
char *findInEnv(char **myenv, char const *word);
char **wordsArray(char *line, char const *delim);
bool notOnlyDelimiter(char const *line, char const *delim);
/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ INITIALISATION ░░░░░░░░░░░░░░░░░ */
data_shell *structure(char **env);
void freeStructure(data_shell *infoShell);
void initializer(char **env, data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ CORE SYSTEM ░░░░░░░░░░░░░░░░░░░░░ */
int coreSystem(data_shell *infoShell);
int searchSystem(data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ BUILTIN ░░░░░░░░░░░░░░░░░░░░░░░░░ */
int cdSystem(data_shell *infoShell);
int envSystem(data_shell *infoShell);
int setenvSystem(data_shell *infoShell);
int unsetenvSystem(data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ PATH ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */
char *findPath(data_shell *infoShell, bool state);
int execBinary(data_shell *infoShell);
/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ PIPE ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */
int thePipe(data_shell *infoShell);