/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:29:40 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 15:31:49 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

size_t ttablen(char const **tabs)
{
    size_t lenght = 0;

    if (!tabs)
        return (0);
    for (; tabs[lenght] != NULL; lenght++);
    return (lenght);
}
