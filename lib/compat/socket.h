/*
 * Copyright (c) 2002-2013 BalaBit IT Ltd, Budapest, Hungary
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */
#ifndef COMPAT_SOCKET_H_INCLUDED
#define COMPAT_SOCKET_H_INCLUDED 1

#include "compat/compat.h"

#ifndef _WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#else
#include <winsock2.h>
#include <ws2tcpip.h>
#endif

#ifndef SHUT_RDWR
#define SHUT_RDWR SD_BOTH
#endif

#ifdef _WIN32

#define ESTALE WSAESTALE
#define ECONNRESET WSAECONNRESET
#define EWOULDBLOCK  WSAEWOULDBLOCK
#define ECONNABORTED WSAECONNABORTED
#define EINPROGRESS WSAEINPROGRESS

#endif

#ifndef HAVE_INET_NTOP
const char *inet_ntop(int af, const void *src, char *dst, socklen_t cnt);
#endif

#ifndef HAVE_INET_PTON
int inet_pton(int af, const char *src, void *dst);
#endif

#ifndef HAVE_STRUCT_SOCKADDR_STORAGE
struct sockaddr_storage 
{
  union
  {
    sa_family_t ss_family;
    struct sockaddr __sa;
    struct sockaddr_un __sun;
    struct sockaddr_in __sin;
#if ENABLE_IPV6
    struct sockaddr_in6 __sin6;
#endif
  };
};
#endif

#ifndef HAVE_INET_ATON
int inet_aton(const char *cp, struct in_addr *dst);
#endif

#endif