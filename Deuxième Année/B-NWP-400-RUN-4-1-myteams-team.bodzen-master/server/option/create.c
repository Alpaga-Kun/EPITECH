/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** create
*/

#include "server.h"

bool is_dir_exists(const char *path)
{
    struct stat stats = {0};
    stat(path, &stats);

    if (S_ISDIR(stats.st_mode))
        return true;
    return false;
}

static void create_folder(char *dirs, char *descrp, char *name, char *format)
{
    int fdfile = 0;
    int fdfile2 = 0;
    char directory[PATH_MAX] = {0};
    char sub[PATH_MAX] = {0};
    mkdir(dirs, 0700);

    if (strncmp(format, "team", 4) == 0) {
        sprintf(sub, "%s/%s", dirs, "sub_user.csv");
        fdfile2 = open(sub, O_WRONLY | O_CREAT, 0644);
        close(fdfile2);
    }
    sprintf(directory, "%s/%s", dirs, format);
    fdfile = open(directory, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fdfile < 0)
        return;
    dprintf(fdfile, "%s, %s\n", name, descrp);
    close(fdfile);
}

void check_format(data_t *d, char *uuid_tmp, char **format,
                    char **command)
{
    if (strcmp(format[0], "team") == 0)
        server_event_team_created(uuid_tmp, format[1], d->uuid_user);
    if (strcmp(format[0], "channel") == 0)
        server_event_channel_created("uuid_team", uuid_tmp, format[1]);
    if (strcmp(format[0], "thread") == 0)
        server_event_thread_created("channel_uuid", uuid_tmp,
            d->uuid_user, format[1], command[2]);
}

void cmd_creating(int fd, char **command, data_t *d)
{
    uuid_t binuuid;
    char uuid[37] = {0};
    char path[PATH_MAX] = {0};
    char *uuid_tmp = NULL;
    char **format = strtab(command[1], "_");

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    uuid_tmp = strdup(uuid);
    if (strcmp(format[0], "team") == 0)
        sprintf(path, "./storage/%s_%s", uuid, format[1]);
    else
        sprintf(path, "%s%s_%s", d->directory, uuid, format[1]);
    create_folder(path, command[2], format[1],
        (strcmp(format[0], "team") == 0 ? "team_desc.csv" :
        strcmp(format[0], "channel") == 0 ? "channel_desc.csv" :
        strcmp(format[0], "thread") == 0 ? "thread_desc.csv" :
        "unknow.csv"));
    check_format(d, uuid_tmp, format, command);
    dprintf(fd, "%s %s %s\n", format[0], format[1], uuid_tmp);
    freetab(format);
}
