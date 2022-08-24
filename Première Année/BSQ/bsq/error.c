/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:29:32 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/24 15:30:57 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

void exitErrorMsg(char const *msg, int status)
{
    fprintf(stderr, "%s\n", msg);
    exit(status);
}