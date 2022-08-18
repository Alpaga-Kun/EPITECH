/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:27:22 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 17:36:10 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

void pputchar(char);
void pputnbr(int);
void pputstr(char const *);
void ffreetabs(char **);
void pputerror(char const *);
void pprinttabs(char **);

size_t sstrlen(char const *);
size_t ttablen(char const **);

int ggetnbr(char const *);
int sstrcmp(char const *, char const *);
int sstrncmp(char const *, char const *, size_t);

char *rread(char const *);
char *sstrdup(char const *);
char *sstrcpy(char *, char const *);
char *sstrcat(char const *, char const *);
char *sstrncat(char const *, char const *, size_t);
