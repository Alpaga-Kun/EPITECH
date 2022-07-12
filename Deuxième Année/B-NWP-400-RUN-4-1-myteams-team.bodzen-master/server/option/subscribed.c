/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** subscribed
*/

#include "server.h"

void verify_subs(char *filepath, char *team_name, int fd, data_t *d)
{
    uuid_t usr_uuid;
    char **subs = NULL;
    char *content = NULL;
    char desc[PATH_MAX] = {0};
    char *buffer = read_file(filepath);

    if (buffer == NULL)
        return;
    subs = strtab(strdup(buffer), ",\n");
    for (int i = 0; subs[i] != NULL; i++) {
        uuid_parse(subs[i], usr_uuid);
        if (uuid_compare(usr_uuid, d->client_tab[fd].cli) == 0) {
            sprintf(desc, "./storage/%s/team_desc.csv", team_name);
            content = read_file(desc);
            dprintf(fd, "%s\n%s\n%s\n", strtok(team_name, "_"),
                strtok(team_name + 37, "_"), content);
            (content != NULL ? free(content) : 0);
        }
    }
    free(buffer);
    freetab(subs);
}

void search_teams(int fd, data_t *d)
{
    DIR *d_storage = opendir("./storage");
    struct dirent *dir = {0};
    char filepath[PATH_MAX] = {0};

    if (d_storage == NULL) {
        closedir(d_storage);
        return;
    }
    while ((dir = readdir(d_storage)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0 &&
            strcmp(dir->d_name, "user") != 0 &&
            strcmp(dir->d_name, "message") != 0) {
            sprintf(filepath, "./storage/%s/sub_user.csv", dir->d_name);
            verify_subs(filepath, dir->d_name, fd, d);
        }
    }
    closedir(d_storage);
}

void print_one_team(int fd, data_t *d, char **command)
{
    char *subs = NULL;
    char **content = NULL;
    char filepath[PATH_MAX] = {0};

    sprintf(filepath, "./storage/%s/sub_user.csv",
        get_team_dir(command[1]));
    subs = read_file(filepath);
    if (subs == NULL) {
        dprintf(fd, "UNKNOWN\r\n");
        return;
    }
    dprintf(fd, "OK\r\n");
    content = strtab(strdup(subs), ",\n");
    for (int i = 0; content[i] != NULL; i++) {
        dprintf(fd, "%s\n%s\n%d\n", content[i], get_username(content[i]),
            get_con(content[i], d));
    }
    free(subs);
    freetab(content);
}

void cmd_list_sub(int fd, char **command, data_t *d)
{
    if (strcmp(command[1], "NULL") == 0) {
        search_teams(fd, d);
        dprintf(fd, "\r\n");
    } else {
        print_one_team(fd, d, command);
        dprintf(fd, "\r\n");
    }
}
