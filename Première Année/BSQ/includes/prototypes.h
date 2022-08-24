/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:28:14 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/24 17:05:58 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct bsq_s
{
    int size;
    int width;
    int height;
} sbsq;

/* ░░░░░░░░░░░░░░░░░ ALGORITHM ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */
void algorithm(char **tabs);
/* ░░░░░░░░░░░░░░░░░ TOOLS ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */
int getWidth(char **tabs);
int getHeight(char **tabs);
void ffreetabs(char **tabs);
void pprinttabs(char **tabs);
void exitErrorMsg(char const *msg, int status);
char *rread(char const *file);
char **sstrtowordarray(char const *s, char const *delim);