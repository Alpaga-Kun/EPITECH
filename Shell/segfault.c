/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segfault.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:36:58 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/07/11 22:39:47 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
    *(int*)0 = 0;
}