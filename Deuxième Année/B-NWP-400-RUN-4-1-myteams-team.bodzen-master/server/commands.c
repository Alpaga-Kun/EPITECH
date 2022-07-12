/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** commands
*/

#include "server.h"

void execute(int fd, char **instruct, data_t *d)
{
    ptr_server option[] = {
        {"HELP", &cmd_help}, {"LOGIN", &cmd_login},
        {"LOGOUT", &cmd_disc}, {"USERS", &cmd_list_usr},
        {"USER", &cmd_info_usr}, {"SEND", &cmd_send_message},
        {"MESSAGES", &cmd_list_message}, {"SUB", &cmd_sub},
        {"SUBD", &cmd_list_sub}, {"UNSUB", &cmd_unsub},
        {"USE", &cmd_using}, {"CREATE", &cmd_creating},
        {"LIST", &cmd_listing}, {"INFO", &cmd_info}
    };

    for (int i = 0; i != 14; i++) {
        if (strcmp(instruct[0], option[i].option) == 0)
            option[i].ptr(fd, instruct, d);
    }
}

int get_commands(int fd, data_t *d)
{
    char buff[1024] = {0};
    char **instruct = NULL;

    if (read(fd, buff, 1024) < 1) {
        FD_CLR(fd, &d->readfds);
        d->client_tab[fd].status = DISCONNECTED;
        close(fd);
        return -1;
    }
    instruct = strtab(buff, " \"\r\n");
    if (instruct != NULL) {
        execute(fd, instruct, d);
        freetab(instruct);
    }
    return (0);
}
