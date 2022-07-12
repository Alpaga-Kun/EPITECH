/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** subscribe
*/

#include "server.h"

char *get_team_dir(char *s)
{
    DIR *d_storage = opendir("./storage");
    char *team_name = NULL;
    struct dirent *s_dir = {0};

    if (d_storage == NULL || s == NULL) {
        closedir(d_storage);
        return NULL;
    }
    while ((s_dir = readdir(d_storage)) != NULL) {
        if (strncmp(s, s_dir->d_name, strlen(s) - 1) == 0) {
            team_name = strdup(s_dir->d_name);
            break;
        }
    }
    closedir(d_storage);
    return (team_name);
}

char *create_path(char *team_dir)
{
    char start[] = "storage/";
    char end[] = "/sub_user.csv";
    char dest[70] = {0};

    strcat(dest, start);
    strcat(dest, team_dir);
    strcat(dest, end);
    return strdup(dest);
}

void sub_in(data_t *d, int fd_file, int fd)
{
    char uuid_str[37] = {0};

    uuid_unparse_upper(d->client_tab[fd].cli, uuid_str);
    dprintf(fd_file, ",");
    dprintf(fd_file, "%s", uuid_str);
}

void get_file_usr(char *filepath, data_t *d, int fd)
{
    int fd_file = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd_file < 0) {
        write(1, "Open Error.\n", 12);
        dprintf(fd, "UNKNOWN\r\n");
        return;
    }
    sub_in(d, fd_file, fd);
    close(fd_file);
}

void cmd_sub(int fd, char **command, data_t *d)
{
    char *team_dir = get_team_dir(command[1]);
    char *filepath = NULL;
    char uuid_str[37] = {0};

    if (team_dir == NULL) {
        dprintf(fd, "UNKNOWN\r\n");
        return;
    }
    filepath = create_path(team_dir);
    get_file_usr(filepath, d, fd);
    uuid_unparse_upper(d->client_tab[fd].cli, uuid_str);
    server_event_user_subscribed(command[1], uuid_str);
    dprintf(fd, "OK\r\n");
    free(team_dir);
    free(filepath);
}
