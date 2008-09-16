/*
 * (C) 2005 by Pablo Neira Ayuso <pablo@eurodev.net>
 *
 * This software may be used and distributed according to the terms
 * of the GNU General Public License, incorporated herein by reference.
 */

#ifndef _LIBNETFILTER_CONNTRACK_UDP_H_
#define _LIBNETFILTER_CONNTRACK_UDP_H_

enum udp_flags {
	UDP_ORIG_SPORT_BIT = 0,
	UDP_ORIG_SPORT = (1 << UDP_ORIG_SPORT_BIT),

	UDP_ORIG_DPORT_BIT = 1,
	UDP_ORIG_DPORT = (1 << UDP_ORIG_DPORT_BIT),

	UDP_REPL_SPORT_BIT = 2,
	UDP_REPL_SPORT = (1 << UDP_REPL_SPORT_BIT),

	UDP_REPL_DPORT_BIT = 3,
	UDP_REPL_DPORT = (1 << UDP_REPL_DPORT_BIT),

	UDP_MASK_SPORT_BIT = 4,
	UDP_MASK_SPORT = (1 << UDP_MASK_SPORT_BIT),

	UDP_MASK_DPORT_BIT = 5,
	UDP_MASK_DPORT = (1 << UDP_MASK_DPORT_BIT),

	UDP_STATE_BIT = 6,
	UDP_STATE = (1 << UDP_STATE_BIT)
};

#endif
