/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:37:42 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/09 21:34:32 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static char *addtion(char *number1, char *number2)
{
    char ch = 0;
    char result[4080] = {0};

    for (int i = 0; number1[i] != '\0'; i++) {
        printf("%c - %c\n", number1[i], number2[i]);
        if (number1[i] == '9' || number2[i] == '9') {
            fprintf(stdout, "Found!");
        } else {
            ch = (number1[i] - '0') + (number2[i] - '0') + '0';
            printf("Char: %c\n", ch);
            strncat(result, &ch, 1);
        }
    }
    fprintf(stdout, "Fin: [%s]\n", result);
    sprintf(result, "%s", strrev(result));
    return (strdup(result));
}

char *infinyAdd(char *number1, char *number2)
{
    char num01[4080] = {0};
    char num02[4080] = {0};

    switch (sizeStr(number1, number2)) {
        case LONG: sprintf(num01, "%s%s", memset(num01, '0', strlen(number1)), number2), sprintf(num02, "0%s", number1);
        break;
        case SHORT: sprintf(num01, "%s%s", memset(num01, '0', strlen(number2)), number1), sprintf(num02, "0%s", number2);
        break;
        case EQUAL: sprintf(num01, "0%s", number1), sprintf(num02, "0%s", number2);
        break;
        default: fprintf(stderr, "[-] Error: String Invalid\n"); break;
    }
    fprintf(stdout, "NUM01 - NUM02: %s - %s\n", num01, num02);
    sprintf(num01, "%s", strrev(num01));
    sprintf(num02, "%s", strrev(num02));

    return (addtion(num01, num02));
}