/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:46:53 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 18:47:03 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool iislower(char c)
{
    return ((c >= 'a' && c <= 'z') ? true : false);
}