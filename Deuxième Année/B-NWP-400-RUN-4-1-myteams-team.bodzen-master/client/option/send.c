/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** send
*/

#include "client.h"

void send_message(char **command, data_t *d)
{
    if (command[1] != NULL && command[2] != NULL) {
        if (strlen(command[2]) > MAX_DESCRIPTION_LENGTH) {
            return;
        }
        dprintf(d->socket_fd, "%s %s %s\r\n",
            command_toupper(command[0], strlen(command[0])),
            command[1], command[2]);
    }
    return;
}
