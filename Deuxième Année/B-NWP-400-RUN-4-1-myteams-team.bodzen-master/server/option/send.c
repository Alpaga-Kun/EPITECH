/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** send
*/

#include "server.h"

void write_message(char *directory, char const *msg, char const *sender)
{
    int fdfile = 0;

    strcat(directory, "user.csv");
    fdfile = open(directory, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fdfile < 0)
        return;
    dprintf(fdfile, "%s,%s\n", msg, sender);
    close(fdfile);
}

bool check_users(char **command, data_t *d)
{
    DIR *dp = NULL;
    int fdfile = 0;
    char directory[PATH_MAX] = {0};
    char hidden[PATH_MAX] = {0};
    char *username = read_file("storage/user/users.csv");

    if (strstr(username, command[1]) != NULL) {
        sprintf(directory, "storage/message/%s/", command[1]);
        if ((dp = opendir(directory)) == NULL) {
            mkdir(directory, 0700);
            sprintf(hidden, "storage/message/%s/", command[1]);
            strcat(hidden, ".hidden.txt");
            fdfile = open(hidden, O_WRONLY | O_CREAT, 0644);
            dprintf(fdfile, "0");
            close(fdfile);
        }
        write_message(directory, command[2], d->uuid_user);
        free(username);
        return (true);
    }
    free(username);
    closedir(dp);
    return (false);
}


void cmd_send_message(int fd, char **command, data_t *d)
{
    (void)fd;
    DIR *dp = NULL;

    if ((dp = opendir("storage/message/")) == NULL) {
        mkdir("storage/message/", 0700);
        if (check_users(command, d) == true)
            server_event_private_message_sended(d->uuid_user,
                command[1], command[2]);
    } else
        if (check_users(command, d) == true)
            server_event_private_message_sended(d->uuid_user,
                command[1], command[2]);
    closedir(dp);
}
