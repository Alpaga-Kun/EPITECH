/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:50:35 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 19:47:08 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int main(int ac, char **av, char **env)
{
    data_shell *infoShell = NULL;
    infoShell = structure(env);

    for (int i = 0; infoShell->myenv[i] != NULL; i++) {
        printf("[%d]: [%s]\n", i, (infoShell->myenv[i] == NULL ? "NULL" : infoShell->myenv[i]));
    }
    freeStructure(infoShell);
    if (infoShell)
        free(infoShell);
    return (0);
}