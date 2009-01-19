/*
 *  Copyright (C) 2002, 2003 Tomasz Kojm <tkojm@clamav.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301, USA.
 */

#ifndef __SERVER_H
#define __SERVER_H

#include <time.h>
#include <pthread.h>

#include "libclamav/clamav.h"
#include "shared/optparser.h"

struct thrarg {
    int sid;
    int options;
    const struct optstruct *opts;
    const struct cl_engine *engine;
    const struct cl_limits *limits;
};

/* thread watcher arguments */
struct thrwarg {
    int socketd;
    struct cl_engine **engine;
    const struct optstruct *opts;
    const struct cl_limits *limits;
    unsigned int options;
};

typedef struct client_conn_tag {
    char *cmd;
    size_t cmdlen;
    int sd;
    struct fd_data *fds;
    unsigned int options;
    const struct optstruct *opts;
    struct cl_engine *engine;
    time_t engine_timestamp;
    char term;
} client_conn_t;

int acceptloop_th(int *socketds, unsigned nsockets, struct cl_engine *engine, unsigned int dboptions, const struct optstruct *opts);
void sighandler(int sig);
void sighandler_th(int sig);
void sigsegv(int sig);

#endif
