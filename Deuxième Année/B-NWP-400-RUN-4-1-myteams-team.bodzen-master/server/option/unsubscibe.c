/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** unsubscibe
*/

#include "server.h"

char *get_team_folder(char *s)
{
    DIR *d_storage = opendir("storage");
    struct dirent *s_dir = {0};
    char *new = NULL;

    if (d_storage == NULL) {
        closedir(d_storage);
        return NULL;
    }
    while ((s_dir = readdir(d_storage)) != NULL) {
        if (strncmp(s, s_dir->d_name, strlen(s) - 1) == 0) {
            new = strdup(s_dir->d_name);
            break;
        }
    }
    closedir(d_storage);
    return new;
}

void replace_file(char *filepath, char *new, int fd)
{
    int fd_file = 0;

    remove(filepath);
    fd_file = open(filepath, O_RDWR | O_CREAT, 0644);
    if (fd_file < 0) {
        dprintf(fd, "UNKNOWN\r\n");
        return;
    }
    if (new[strlen(new) - 1] == ',')
        new[strlen(new) - 1] = '\0';
    dprintf(fd_file, "%s\n", new);
    close(fd_file);
}

void rm_subs(int fd, char *filepath, data_t *d)
{
    int fd_file = open(filepath, O_RDWR, 0644);
    char *buffer = "";
    char new[1024] = {0};
    struct stat stats = {0};
    uuid_t usr_uuid;

    if (fd_file < 0) {
        dprintf(fd, "UNKNOWN\r\n");
        return;
    }
    stat(filepath, &stats);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    read(fd_file, buffer, stats.st_size);
    for (char *t = strtok(buffer, ","); t != NULL; t = strtok(NULL, ",")) {
        uuid_parse(t, usr_uuid);
        (uuid_compare(usr_uuid, d->client_tab[fd].cli) != 0) ?
        strcat(new, t), strcat(new, strdup(",")) : 0;
    }
    close(fd_file);
    replace_file(filepath, new, fd);
    free(buffer);
}

void cmd_unsub(int fd, char **command, data_t *d)
{
    char *team_dir = get_team_folder(command[1]);
    char *filepath = NULL;
    char uuid_str[37] = {0};

    if (team_dir == NULL) {
        dprintf(fd, "UNKNOWN\r\n");
        return;
    }
    filepath = create_path(team_dir);
    rm_subs(fd, filepath, d);
    uuid_unparse_upper(d->client_tab[fd].cli, uuid_str);
    server_event_user_unsubscribed(command[1], uuid_str);
    dprintf(fd, "OK\r\n");
    free(team_dir);
    free(filepath);
}
