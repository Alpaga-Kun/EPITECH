/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:50:35 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 21:48:05 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int main(int ac, char **av, char **env)
{
    data_shell *infoShell = NULL;

    if (ac == 1) {
        infoShell = structure(env);
        coreSystem(infoShell);
        freeStructure(infoShell);
    }
    return (0);
}