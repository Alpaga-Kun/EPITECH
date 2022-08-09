/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:15:11 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/09 21:29:33 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum SIZESTR {
    LONG,
    SHORT,
    EQUAL
};

typedef struct ptr_operand_s
{
    char operand;
    char *(*ptr)(char *, char *);
} ptrOperand;

/* ░░░░░░░░░░░░░░░░░ ERROR ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
void errorQuit(char const *msg);
/* ░░░░░░░░░░░░░░░░░ TOOLS ░░░░░░░░░░░░░░░░░░░░░░░░░░ */
char *findOperand(char const *buffer, char const *operand);
void freeTabs(char **tabs);
void displayTabs(char **tabs);
char **wordsArray(char *line, char const *delim);
int sizeStr(char *s1, char *s2);
char *strrev(char *str);
/* ░░░░░░░░░░░░░░░░░ OPERAND ░░░░░░░░░░░░░░░░░░░░░░░░ */
char *infinyAdd(char *number1, char *number2);
char *infinySub(char *number1, char *number2);
char *infinyDiv(char *number1, char *number2);
char *infinyMul(char *number1, char *number2);
/* ░░░░░░░░░░░░░░░░░ ADDITION ░░░░░░░░░░░░░░░░░░░░░░░ */
void findSizeStr(char **number01, char **number02);
