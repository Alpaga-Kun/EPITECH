/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:28:46 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/24 20:03:13 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int main(int ac, char **av)
{
    if (ac != 2)
        exitErrorMsg("Error: One argument is expected.", 84);
    char *content = rread(av[1]);
    char **tabs = sstrtowordarray(content, "0123456789\n");
    algorithm(tabs);
    ffreetabs(tabs);
    free(content);
}