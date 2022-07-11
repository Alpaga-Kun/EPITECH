/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:46:48 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 19:45:43 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct data_shell_s
{
    char **myenv;
} data_shell;

/* ░░░░░░░░░░░░░░░░░ ERROR ░░░░░░░░░░░░░░░░░ */
void errorMessage(char const *msg, int exitStatus);
/* ░░░░░░░░░░░░░░░░░ TOOLS ░░░░░░░░░░░░░░░░░ */
size_t sizeTab(char **tabs);
/* ░░░░░░░░░░░░░░░░░ INITIALISATION ░░░░░░░░░░░░░░░░░ */
void initializer(char **env, data_shell *infoShell);
data_shell *structure(char **env);
void freeStructure(data_shell *infoShell);
