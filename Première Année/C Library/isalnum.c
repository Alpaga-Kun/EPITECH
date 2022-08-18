/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:47:42 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 18:49:31 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool iisalnum(char c)
{
    return (iisalpha(c) == true || iisdigit(c) == true ? true : false);
}