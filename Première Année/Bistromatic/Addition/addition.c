/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:37:42 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/16 17:12:39 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int deduction = 0;

char *cleanOff(char *result)
{
    result = removeSpacesFromStr(result);
    if (result[0] == '0')
        result[0] = ' ';
    result = removeSpacesFromStr(result);
    return (result);
}

static char setByOrEqualNine(int number1, int number2)
{
    int result = 0;

    result = number1 + number2 + deduction;
    deduction = result / 10;
    result %= 10;
    return (result < 0 || result > 9 ? ' ' : result + '0');
}

static char *addtion(char *number1, char *number2)
{
    char ch = 0;
    char *result = malloc(sizeof(char) * (getBiggerStr(number1, number2) + 1));

    memset(result, '\0', getBiggerStr(number1, number2));
    for (int i = 0; number1[i] != '\0'; i++) {
        ch = setByOrEqualNine((number1[i] - '0'), (number2[i] - '0'));
        strncat(result, &ch, 1);
    }
    result = cleanOff(strrev(result));
    return (result);
}

char *infinyAdd(char *number1, char *number2)
{
    char num01[4080] = {0};// For better precision, malloc must be use here
    char num02[4080] = {0};// For better precision, malloc must be use here

    switch (sizeStr(number1, number2)) {
        case LONG:
            sprintf(num01, "%s%s", memset(num01, '0', strlen(number1)),
                number2), sprintf(num02, "0%s", number1);
            break;
        case SHORT:
            sprintf(num01, "%s%s", memset(num01, '0', strlen(number2)),
                number1), sprintf(num02, "0%s", number2);
            break;
        case EQUAL:
            sprintf(num01, "0%s", number1), sprintf(num02, "0%s", number2);
            break;
        default: fprintf(stderr, "[-] Error: String Invalid\n"); break;
    }
    sprintf(num01, "%s", strrev(num01));
    sprintf(num02, "%s", strrev(num02));
    return (addtion(num01, num02));
}
