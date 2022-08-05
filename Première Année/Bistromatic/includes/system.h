/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:15:11 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/04 20:46:17 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
/* ░░░░░░░░░░░░░░░░░ OPERAND ░░░░░░░░░░░░░░░░░░░░░░░░ */
char *infinyAdd(char *number1, char *number2);
char *infinySub(char *number1, char *number2);
char *infinyDiv(char *number1, char *number2);
char *infinyMul(char *number1, char *number2);
