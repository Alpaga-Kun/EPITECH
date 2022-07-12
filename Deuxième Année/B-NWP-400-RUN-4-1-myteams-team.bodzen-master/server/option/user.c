/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** user
*/

#include "server.h"

void cmd_info_usr(int fd, char **command, data_t *d)
{
    int fd2 = open("storage/user/users.csv", O_RDONLY);
    char *s1 = 0;
    struct stat st = {0};

    if (fd2 == -1)
        return;
    stat("storage/user/users.csv", &st);
    if ((s1 = malloc(sizeof(char) * st.st_size)) == 0)
        return;
    if (read(fd2, s1, st.st_size) == 0)
        return;
    for (int i = 0; s1[i]; i++) {
        if (strncmp(s1 + i, command[1], 36) == 0) {
            dprintf(fd, "%s %d\r\n", strtok(s1 + i, "\n"), get_con(s1 + i, d));
            free(s1);
            return;
        }
    }
    dprintf(fd, "UNKNOW\r\n");
}
