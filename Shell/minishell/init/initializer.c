/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:54:24 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 22:29:17 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void setEnv(data_shell *infoShell)
{
    char *cwd = NULL;
    char pwd[PATH_MAX] = {0};
    sprintf(pwd, "%s=%s", "PWD=", getcwd(cwd, (size_t)0));
    infoShell->myenv = malloc(sizeof(char **) * 5);

    infoShell->myenv[0] = strdup("PATH=usr/bin:/usr/sbin");
    infoShell->myenv[1] = strdup(pwd);
    infoShell->myenv[2] = strdup("USER=user");
    infoShell->myenv[3] = strdup("HOME=/home/user");
    infoShell->myenv[4] = NULL;
}

static void saveEnv(char **env, data_shell *infoShell)
{
    int j = 0;
    infoShell->myenv = malloc(sizeof(char **) * (sizeTab(env) + 1));

    if (!infoShell->myenv)
        errorMessage("malloc()", 84);
    for (int i = 0; env[i] != NULL; i++, j++)
        infoShell->myenv[j] = strdup(env[i]);
    infoShell->myenv[j] = NULL;
}

void initializer(char **env, data_shell *infoShell)
{
    (env == NULL ? setEnv(infoShell) : saveEnv(env, infoShell));
}