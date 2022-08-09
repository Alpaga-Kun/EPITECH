/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:06:58 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/09 19:14:44 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void doOperand(char **tabs, char *listOperand)
{
    int pos = 0;
    char tmp[4080] = {0};
    char *result = NULL;

    ptrOperand op[] = {
        {'+', &infinyAdd},
        {'-', &infinySub},
        {'*', &infinyMul},
        {'/', &infinyDiv},
    };

    for (size_t i = 0; i < strlen(listOperand); i++) {
        for (int j = 0; j != 4; j++) {
            if (op[i].operand == listOperand[i]) {
                if (result) {
                    sprintf(tmp, "%s", result);
                    free(result);
                }
                result = (op[i].ptr((result == NULL ? tabs[pos] : tmp), (pos < 2 ? tabs[pos + 1] : tabs[pos])));
                fprintf(stdout, "Resultat: %s\n", result);
                (pos < 2 ? pos += 2 : pos++);
                break;
            }
        }
    }
    freeTabs(tabs);
    free(listOperand);
    free(result);
}

void coreSystem(void)
{
    size_t len = 0;
    char **tabs = NULL;
    char *listOperand = NULL;
    char *buffer = NULL;

    while (getline(&buffer, &len, stdin) != EOF) {
        fprintf(stdout, "Your operation: %s\n", buffer);
        listOperand = findOperand(buffer, "+-*/");
        fprintf(stdout, "Your operand: %s\n", listOperand);
        tabs = wordsArray(buffer, " \n+-*/");
        doOperand(tabs, listOperand);
    }
    if (buffer)
        free(buffer);
}

int main(void)
{
    coreSystem();
    return (0);
}