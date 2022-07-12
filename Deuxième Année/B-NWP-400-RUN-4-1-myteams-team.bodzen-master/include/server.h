/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** server
*/

#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <uuid/uuid.h>
#include "../libs/myteams/logging_server.h"

#define _BSD_SOURCE

typedef enum status_e {
    DISCONNECTED,
    CONNECTED
} status_e;

typedef enum use_e {
    UNDEFINE,
    TEAM,
    CHANNEL,
    THREAD
} use_e;

typedef struct client_s {
    int fd;
    status_e status;
    use_e use_cont;
    uuid_t team;
    uuid_t channel;
    uuid_t thread;
    uuid_t cli;
    char name[32];
} cli_t;

typedef struct data_s {
    int socket_fd;
    unsigned int sock_len;
    char uuid_user[37];
    char *directory;
    fd_set readfds;
    fd_set readfds_cpy;
    fd_set writefds;
    fd_set writefds_cpy;
    cli_t client_tab[FD_SETSIZE];
    struct sockaddr_in sockaddr;
    struct sockaddr_in cliaddr;
    struct timeval tv;
} data_t;

typedef struct server_opt_s {
    char const *option;
    void (*ptr)(int, char **, data_t *);
} ptr_server;

char **strtab(char *line, char *delim);
void freetab(char **tabs);
char *read_file(char const *path);

void cmd_creating(int fd, char **command, data_t *d);
void cmd_help(int fd, char **command, data_t *d);
void cmd_info(int fd, char **command, data_t *d);
void cmd_listing(int fd, char **command, data_t *d);
void cmd_login(int fd, char **command, data_t *d);
void cmd_disc(int fd, char **command, data_t *d);
void cmd_list_message(int fd, char **command, data_t *d);
void cmd_send_message(int fd, char **command, data_t *d);
void cmd_sub(int fd, char **command, data_t *d);
void cmd_list_sub(int fd, char **command, data_t *d);
void cmd_unsub(int fd, char **command, data_t *d);
void cmd_using(int fd, char **command, data_t *d);
void cmd_info_usr(int fd, char **command, data_t *d);
void cmd_list_usr(int fd, char **command, data_t *d);

int get_con(char *str, data_t *d);
int get_name_len(char *name);
int get_commands(int fd, data_t *d);
int run_server(data_t *d);
int create_socket(data_t *d, char *port);
int is_storage_exist(void);
char *rm_end(char *cmd);
char *get_team_dir(char *s);
char *create_path(char *team_dir);
void subscribe_cmd(int fd, char *s, data_t *d);
void unsubscribe_cmd(int fd, char *s, data_t *d);
char *get_team_id(char *team_name);
char *create_pathname(char *team_name);
void subscribed_cmd(int fd, char *s, data_t *d);
char *create_pathname(char *team_name);
char *get_team_id(char *team_name);
char *get_username(char *user);
