/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:37:42 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/05 17:47:07 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

char *infinyAdd(char *number1, char *number2)
{
    char result[4080] = {0};
    fprintf(stdout, "Number 01: %s - Number 02: %s\n", number1, number2);
    sprintf(result, "%d", atoi(number1) + atoi(number2));
    return (strdup(result));
}