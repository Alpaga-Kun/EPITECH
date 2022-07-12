/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** messages
*/

#include "client.h"

static int lenghttab(char **tabs)
{
    int len = 0;
    for (; tabs[len] != NULL; len++);
    return (len);
}

static void write_into(char *hidden, size_t lenght)
{
    int fdfile = 0;

    fdfile = open(hidden, O_RDONLY | O_WRONLY | O_TRUNC, 0644);
    dprintf(fdfile, "%ld", lenght);
    close(fdfile);
}

static void see_msg(data_t *d, char *hidden, size_t lenght, char **content)
{

    if (d->new_msg == true && d->old == 0) {
        for (int i = d->old; content[i] != NULL; i += 2)
            client_event_private_message_received(content[i + 1],
                content[i]);
        d->old = lenght;
        d->new_msg = false;
        write_into(hidden, lenght);
        return;
    }
    if (d->new_msg == false && d->old < lenght) {
        for (int i = d->old; content[i] != NULL; i += 2)
            client_event_private_message_received(content[i + 1],
                content[i]);
        d->old = lenght;
        write_into(hidden, lenght);
    }
}

void update_message(data_t *d)
{
    size_t lenght = 0;
    char *buffer = NULL;
    char **content = NULL;
    char directory[PATH_MAX] = {0};
    char hidden[PATH_MAX] = {0};

    sprintf(hidden, "./storage/message/%s/.hidden.txt", d->user_uuid);
    sprintf(directory, "./storage/message/%s/user.csv", d->user_uuid);
    if ((buffer = read_file(directory)) == NULL) {
        d->new_msg = true;
        return;
    }
    d->old = atoi(read_file(hidden));
    content = strtab(buffer, ",\n");
    lenght = lenghttab(content);
    see_msg(d, hidden, lenght, content);
    if (buffer)
        free(buffer);
    freetab(content);
}

void list_message(char **command, data_t *d)
{
    char buff[1024] = {0};
    char **receive = NULL;

    if (command[1] == NULL)
        return;
    dprintf(d->socket_fd, "%s %s\r\n", command_toupper(command[0],
        strlen(command[0])), command[1]);
    read(d->socket_fd, buff, 1024);
    receive = strtab(buff, ",\n");
    for (int i = 0; i < lenghttab(receive); i++) {
        if (strcmp(d->user_uuid, receive[i]) == 0)
            client_private_message_print_messages(d->user_uuid, time(NULL),
                receive[i - 1]);
    }
    freetab(receive);
    return;
}
