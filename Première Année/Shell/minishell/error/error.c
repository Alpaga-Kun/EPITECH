/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:16:07 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/12 09:24:49 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void quitMessage(char const *msg, int exitStatus)
{
    perror(msg);
    exit(exitStatus);
}

int setquitMessage(char const *command, char const *msg, int returnStatus)
{
    fprintf(stderr, "%s: %s\n", command, msg);
    return (returnStatus);
}