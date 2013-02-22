/* $OpenBSD: misc.h,v 1.37 2007/12/27 14:22:08 dtucker Exp $ */

/*
 * Author: Tatu Ylonen <ylo@cs.hut.fi>
 * Copyright (c) 1995 Tatu Ylonen <ylo@cs.hut.fi>, Espoo, Finland
 *                    All rights reserved
 *
 * As far as I am concerned, the code I have written for this software
 * can be used freely for any purpose.  Any derived versions of this
 * software must be clearly marked as such, and if the derived work is
 * incompatible with the protocol description in the RFC file, it must be
 * called by a name other than "ssh" or "Secure Shell".
 */

#ifndef _MISC_H
#define _MISC_H

/* misc.c */

char	*pamsshagentauth_chop(char *);
char	*pamsshagentauth_strdelim(char **);
int	 pamsshagentauth_set_nonblock(int);
int	 pamsshagentauth_unset_nonblock(int);
void	 pamsshagentauth_set_nodelay(int);
int	 pamsshagentauth_a2port(const char *);
int	 pamsshagentauth_a2tun(const char *, int *);
char	*pamsshagentauth_put_host_port(const char *, u_short);
char	*pamsshagentauth_hpdelim(char **);
char	*pamsshagentauth_cleanhostname(char *);
char	*pamsshagentauth_colon(char *);
long	 pamsshagentauth_convtime(const char *);
char	*pamsshagentauth_tilde_expand_filename(const char *, uid_t);
char	*pamsshagentauth_percent_expand(const char *, ...) __attribute__((__sentinel__));
char	*pamsshagentauth_tohex(const void *, size_t);
void	 pamsshagentauth_sanitise_stdfd(void);

struct passwd *pamsshagentauth_pwcopy(struct passwd *);
const char *ssh_gai_strerror(int);

typedef struct arglist arglist;
struct arglist {
	char    **list;
	u_int   num;
	u_int   nalloc;
};
void	 pamsshagentauth_addargs(arglist *, char *, ...)
	     __attribute__((format(printf, 2, 3)));
void	 pamsshagentauth_replacearg(arglist *, u_int, char *, ...)
	     __attribute__((format(printf, 3, 4)));
void	 pamsshagentauth_freeargs(arglist *);

int	 pamsshagentauth_tun_open(int, int);

/* Common definitions for ssh tunnel device forwarding */
#define SSH_TUNMODE_NO		0x00
#define SSH_TUNMODE_POINTOPOINT	0x01
#define SSH_TUNMODE_ETHERNET	0x02
#define SSH_TUNMODE_DEFAULT	SSH_TUNMODE_POINTOPOINT
#define SSH_TUNMODE_YES		(SSH_TUNMODE_POINTOPOINT|SSH_TUNMODE_ETHERNET)

#define SSH_TUNID_ANY		0x7fffffff
#define SSH_TUNID_ERR		(SSH_TUNID_ANY - 1)
#define SSH_TUNID_MAX		(SSH_TUNID_ANY - 2)

/* Functions to extract or store big-endian words of various sizes */
u_int64_t	pamsshagentauth_get_u64(const void *)
    __attribute__((__bounded__( __minbytes__, 1, 8)));
u_int32_t	pamsshagentauth_get_u32(const void *)
    __attribute__((__bounded__( __minbytes__, 1, 4)));
u_int16_t	pamsshagentauth_get_u16(const void *)
    __attribute__((__bounded__( __minbytes__, 1, 2)));
void		pamsshagentauth_put_u64(void *, u_int64_t)
    __attribute__((__bounded__( __minbytes__, 1, 8)));
void		pamsshagentauth_put_u32(void *, u_int32_t)
    __attribute__((__bounded__( __minbytes__, 1, 4)));
void		pamsshagentauth_put_u16(void *, u_int16_t)
    __attribute__((__bounded__( __minbytes__, 1, 2)));


/* readpass.c */

#define RP_ECHO			0x0001
#define RP_ALLOW_STDIN		0x0002
#define RP_ALLOW_EOF		0x0004
#define RP_USE_ASKPASS		0x0008

char	*read_passphrase(const char *, int);
int	 ask_permission(const char *, ...) __attribute__((format(printf, 1, 2)));
int	 read_keyfile_line(FILE *, const char *, char *, size_t, u_long *);

#endif /* _MISC_H */
