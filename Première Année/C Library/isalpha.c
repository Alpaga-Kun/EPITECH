/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:50:24 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 18:51:35 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool iisalpha(char c)
{
    return (iislower(c) == true || iisupper(c) == true ? true : false);
}