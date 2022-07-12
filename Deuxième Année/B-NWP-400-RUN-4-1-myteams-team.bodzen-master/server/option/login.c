/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** login
*/

#include "server.h"

int check_user(char *str, int fd, data_t *d, char *name)
{
    int fd2 = open(str, O_RDONLY);
    struct stat st = {0};
    char *content = 0;

    if (fd2 == -1 || stat(str, &st))
        return (1);
    if ((content = malloc(sizeof(char) * st.st_size)) == 0)
        return 1;
    if (read(fd2, content, st.st_size) < 1)
        return (1);
    if ((str = strstr(content, name))) {
        server_event_user_logged_in(strtok(str - 37, ","));
        strcpy(d->uuid_user, strtok(str - 37, ","));
        dprintf(fd, "%.36s\r\n", str - 37);
        uuid_parse(str - 37, d->client_tab[fd].cli);
        close(fd2);
        free(content);
        return (0);
    }
    free(content);
    return (1);
}

int is_new_user(char *s1, int fd, data_t *d)
{
    DIR *dirp = opendir("storage/user");
    struct dirent *e = 0;
    char *p = "storage/user/users.csv";

    if (dirp == NULL) {
        closedir(dirp);
        return (0);
    }
    while ((e = readdir(dirp))) {
        if (strcmp(e->d_name, "users.csv") == 0 && !check_user(p, fd, d, s1)) {
            d->client_tab[fd].status = CONNECTED;
            snprintf(d->client_tab[fd].name, strlen(s1), "%s", s1);
            closedir(dirp);
            d->client_tab[fd].fd = fd;
            return 1;
        }
    }
    closedir(dirp);
    return (0);
}

int write_user_to_file(char *uuid, char *name)
{
    int fd = 0;

    mkdir("storage/user", 0700);
    fd = open("./storage/user/users.csv", O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd < 0)
        return -1;
    dprintf(fd, "%s,%s\n", uuid, name);
    close(fd);
    return (0);
}

void cmd_login(int fd, char **command, data_t *d)
{
    uuid_t uuid;
    char uuid_str[37] = {0};

    if (is_new_user(command[1], fd, d) == 0) {
        uuid_generate_random(uuid);
        uuid_unparse_upper(uuid, uuid_str);
        write_user_to_file(uuid_str, command[1]);
        d->client_tab[fd].status = CONNECTED;
        d->client_tab[fd].fd = fd;
        uuid_copy(d->client_tab[fd].cli, uuid);
        snprintf(d->client_tab[fd].name, strlen(command[1]), "%s", command[1]);
        server_event_user_created(uuid_str, command[1]);
        server_event_user_logged_in(uuid_str);
        strcpy(d->uuid_user, uuid_str);
        dprintf(fd, "%s\r\n", uuid_str);
    }
}
