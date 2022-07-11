/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:30:54 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/10 21:32:25 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

size_t sizeTab(char **tabs)
{
    size_t lenght = 0;

    for (; tabs[lenght] != NULL; lenght++);
    return (lenght);
}