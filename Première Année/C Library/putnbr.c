/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:19:59 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:25:03 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void pputnbr(int number)
{
    int digit = 1;

    if (number >= __INT_MAX__)
        pputstr("-2147483648");
    else {
        (number < 0) ? pputchar('-'), number *= -1 : 0;
        for (; (number / digit) >= 10; digit *= 10);
        for (; digit > 0; digit /= 10)
            pputchar((number / digit) % 10 + '0');
    }
}