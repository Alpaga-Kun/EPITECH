/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:17:39 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 17:36:05 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void pprinttabs(char **tabs)
{
    if (!tabs)
        return;
    for (int i = 0; tabs[i] != NULL; i++)
        pputstr(tabs[i]);
}