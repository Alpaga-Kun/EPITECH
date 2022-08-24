/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:29:47 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/24 17:17:53 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

static int setFirstLine(char **tabs)
{
    int i = 0;

    for (int x = 0; tabs[i][x] != '\0'; x++)
        tabs[i][x] = (tabs[i][x] == 'o' ? 1 : 2);
    for (int y = 0; tabs[y] != NULL; y++)
        tabs[y][i] = (tabs[y][i] == 'o' || tabs[y][i] == 1 ? 1 : 2);
    return (0);
}

static int scanMap(char **tabs, int x, int y)
{
    int n = tabs[y - 1][x];
    int o = tabs[y][x - 1];
    int no = tabs[y - 1][x - 1];

    if (n <= no && n <= o)
        tabs[y][x] = n + 1;
    if (no <= n && no <= o)
        tabs[y][x] = no + 1;
    if (o <= no && o <= n)
        tabs[y][x] = o + 1;
    return (0);
}

static void biggestSquare(sbsq ptr, char **tabs)
{
    int big = 0;
    int bigX = 0;
    int bigY = 0;

    for (int y = 0; tabs[y] != NULL; y++) {
        for (int x = 0; tabs[y][x] != '\0'; x++) {
            if (ptr.size < tabs[y][x]) {
                ptr.size = tabs[y][x];
                ptr.width = x;
                ptr.height = y;
            }
        }
    }
    big = ptr.size - 2;
    bigX = ptr.width;
    bigY = ptr.height;
    for (int i = bigY - big; i <= bigY; i++)
        for (int j = bigX - big; j <= bigX; j++)
            tabs[i][j] = 'x';
}

void algorithm(char **tabs)
{
    sbsq ptr = {1, 0, 0};
    setFirstLine(tabs);
    for (int y = 1; tabs[y] != NULL; y++) {
        for (int x = 1; tabs[y][x] != '\0'; x++) {
            (tabs[y][x] == 'o' ? tabs[y][x] = 1 : scanMap(tabs, x, y));
        }
    }
    biggestSquare(ptr, tabs);
    for (int y = 0; tabs[y] != NULL; y++) {
        for (int x = 0; tabs[y][x] != '\0'; x++) {
            if (tabs[y][x] == 1)
                tabs[y][x] = 'o';
            else if (tabs[y][x] != 'x')
                tabs[y][x] = '.';
        }
    }
    pprinttabs(tabs);
}