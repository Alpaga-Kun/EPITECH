/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:16:07 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 20:42:32 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void errorMessage(char const *msg, int exitStatus)
{
    perror(msg);
    exit(exitStatus);
}

int unknowCommands(char const *command)
{
    fprintf(stderr, "%s: Command not found.\n", command);
    return (1);
}