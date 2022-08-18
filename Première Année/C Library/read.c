/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:32:35 by Alpaga-Kun        #+#    #+#             */
/*   Updated: 2022/08/18 16:16:35 by Alpaga-Kun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char *rread(char const *file)
{
    ssize_t size = 0;
    char *buffer = NULL;
    struct stat st = {0};
    int fd = open(file, O_RDONLY);

    if (fd == -1 || stat(file, &st) == -1)
        pputerror("Failed to open or stat failed.\n");
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    if (buffer == NULL)
        pputerror("Failed to allocate memory.\n");
    while ((size = read(fd, buffer, st.st_size)) > 0);
    if (size == -1)
        pputerror("Read failed.\n");
    buffer[st.st_size] = '\0';
    close(fd);
    return (buffer);
}