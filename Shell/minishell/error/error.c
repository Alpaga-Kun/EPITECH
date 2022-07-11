/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:16:07 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 22:19:28 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void errorMessage(char const *msg, int exitStatus)
{
    perror(msg);
    exit(exitStatus);
}

int setErrorMessage(char const *command, char const *msg, bool status)
{
    fprintf(stderr, "%s: %s\n", command, msg);
    return (status == true ? 1 : 0);
}