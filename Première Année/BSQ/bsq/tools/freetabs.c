/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetabs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:17:32 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/24 15:35:46 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

void ffreetabs(char **tabs)
{
    if (!tabs)
        return;
    for (int i = 0; tabs[i] != NULL; i++)
        free(tabs[i]);
    free(tabs);
}