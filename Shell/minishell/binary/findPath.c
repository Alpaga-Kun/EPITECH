/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:48:21 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 20:58:43 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

char *findPath(data_shell *infoShell)
{
    char *binary = NULL;
    char *newPath = NULL;

    if (access(infoShell->commands[0], X_OK) == 0)
        return (infoShell->commands[0]);

    return (NULL);
}