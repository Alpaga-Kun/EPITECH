/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** client
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include "../libs/myteams/logging_client.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

#define HELP "/help : show help\n/login [“user_name”] : set the user_name \
 used by client\n/logout : disconnect the client from the server\n/users : get\
 the list of all users that exist on the domain\n/user [“user_uuid”] : get\
 information about a user\n/send [“user_uuid”] [“message_body”] : send a\
 message to a user\n/messages [“user_uuid”] : list all messages exchange\
 with an user\n/subscribe [“team_uuid”] : subscribe to the event of a team\
 and its sub directories (enable reception of all events from a team)\n\
/subscribed ?[“team_uuid”] : list all subscribed teams or list all users\
 subscribed to a team\n/unsubscribe [“team_uuid”] : unsubscribe from a team\
 /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] :\
 use specify a context team/channel/thread\n/create : based on what is\
 being used create the sub resource (see below)\n/list : based on what is\
 being used list all the sub resources (see below)\n/info : based on what\
 is being used list the current (see below)\n"

typedef struct data_s {
    size_t old;
    bool new_msg;
    int socket_fd;
    char *directory;
    fd_set readfds;
    fd_set readfds_cpy;
    fd_set writefds;
    fd_set writefds_cpy;
    uuid_t uuid;
    char user_uuid[37];
    char name[32];
    unsigned int sock_len;
    bool is_con;
    struct sockaddr_in sockaddr;
    struct timeval tv;
} data_t;

typedef struct option_s {
    char const *option;
    void (*ptr)(char **, data_t *);
} ptr_option;

typedef void (*ptr_create)(char *);

void update_message(data_t *d);

char *command_toupper(char *line, size_t lenght);
char **strtab(char *line, char const *delim);
void freetab(char **tabs);
char *read_file(char const *path);

void user_info(char *str, data_t *d);
void users_list(data_t *d);

bool is_logged(data_t *d);
int get_login(char **command, data_t *d);
int logout(data_t *d);

int check_command(char *str, data_t *d);
int run_client(data_t *d);
int connect_server(data_t *d, char **av);
void subscribe(data_t *d, char *s);
char *rm_end(char *cmd);
void print_list(data_t *d, char *buff);
void subscribed(data_t *d, char *team_uuid);
void unsubscribe(data_t *d, char *team_uuid);

void show_help(char **, data_t *);
void set_log(char **, data_t *);
void get_disconnect(char **, data_t *);
void get_list_usr(char **, data_t *);
void get_info_usr(char **, data_t *);
void send_message(char **, data_t *);
void list_message(char **, data_t *);
void get_sub(char **, data_t *);
void list_sub(char **, data_t *);
void get_unsub(char **, data_t *);
void use_fnc(char **, data_t *);
void creating(char **, data_t *);
void listing(char **, data_t *);
void get_info(char **, data_t *);
