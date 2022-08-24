/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:31:45 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/24 16:32:59 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int getWidth(char **tabs)
{
    return (strlen(tabs[0]));
}

int getHeight(char **tabs)
{
    int height = 0;

    for (int i = 1; tabs[i] != NULL; i++, height++);
    return (height);
}