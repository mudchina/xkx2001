//Cracked by Roath
#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#ifndef SVC_TCP
#include <net/services.h>
#endif

/* These are the primary and secondry hosts to use as boot servers
 * for the DNS.  It is better to set to the primary to be a mud on
 * the same continent.
 */
// Elon (07-01-95) updated LISTNODES to current
// The TMI-2
#define MUDLIST_DNS  ({ "207.206.185.91", 5559 })
#define MUDLIST_BAK  ({ "202.103.44.195", 8008 })
#define MUDLIST_BAK  ({ "202.98.15.17", 5559 })
#define MUDLIST_BAK  ({ "202.96.236.99", 5559 })
#define MUDLIST_BAK  ({ "142.132.12.118", 5559 })
#define MUDLIST_BAK  ({ "202.102.197.65", 5559 })
#define MUDLIST_BAK  ({ "210.77.38.100", 5559 })
#define MUDLIST_BAK  ({ "202.97.230.92", 5559 })
#define MUDLIST_BAK  ({ "202.101.248.39", 5559 })
#define MUDLIST_BAK  ({ "202.102.190.40", 5559 })
#define MUDLIST_BAK  ({ "202.130.25.8", 5559 })
// The Eastern Stories
#define MUDLIST_BAK  ({ "140.113.204.42", 8008 })
#define MUDLIST_BAK ({"193.10.174.41", 5563})
#define MUDLIST_BAK ({"209.191.135.218",5559})
#define MUDLIST_BAK ({"209.191.135.218",2229})

#define LISTNODES ([ \
	"US"		:	"207.206.185.91 5559",\
	"DV"		:	"206.245.158.138 5559",\
	"CD"		:	"61.139.77.84 5559",\
	"JL"		:	"202.98.15.17 5559" ,\
	"SH"		:	"202.101.42.229 8892" ,\
	"ET"		:	"202.101.42.229 5559",\
	"DV"		:	"142.132.12.118 5559",\
	"AH"		:	"202.102.197.65 5559",\
	"BJ"		:	"210.77.38.100 5559", \
	"HB"		:	"202.103.44.195 5559", \
	"HL"		:	"210.76.60.137 5559", \
	"JX"		:	"202.101.233.79 5559", \
	"SD"		:	"61.156.28.11 5559", \
	"SY"		:	"202.130.25.8 5559", \
	"XF"		:	"202.103.44.253 5559", \
	"WD"		:	"202.103.44.197 5559", \
	"SC"		:	"61.139.77.84 8892", \
	"LN"		:	"202.96.80.2 5559", \
	"JS"		:	"202.102.3.15 5559", \
	"SZ"		:	"61.132.119.19 5559", \
	"NJ"		:	"202.102.2.68 5559", \
	"XA"		:	"202.100.30.11 5559", \
	"HN"		:	"202.102.245.17 5559", \
	"WX"		:	"210.28.144.204 5559", \
	"DN"		:	"202.119.144.5 5559", \
	"QD"		:	"203.93.95.159 5559", \
	"CG"		:	"202.106.182.102 5559", \
	"FX"		:	"202.96.91.9 5559", \
])

/* This is the default packet size of outgoing mail messages.  The ideal
 * number is 512, maximum would be about 900, since 1024 is the maximum
 * udp packet size.  Probably best kept at 512
 */
#define MAIL_PACKET_SIZE        512

/* These macros are for the name service.  They determine how often the
 * database is refreshed, how often other muds are checked, how often
 * the sequence list is checked for timed out services, and how long a
 * service is allowed to time out.
 */
#define REFRESH_INTERVAL     5*60
#define PING_INTERVAL       30*60
#define SEQ_CLEAN_INTERVAL  60*60
#define SERVICE_TIMEOUT        30

/* The number of muds that we initialy allocate space for.  This speeds
 * up name lookup.
 */
#define MUDS_ALLOC 60

/* This macro controls the level of tcp support used by the mud for
 * services such as finger, tell and mail. Valid values are:
 *  TCP_ALL   - all services available
 *  TCP_ONLY  - only tcp services available
 *  TCP_SOME  - some tcp services are available
 *  TCP_NONE  - no tcp services available
 */
#define TCP_SERVICE_LEVEL TCP_ALL

/* These are the prefered protocols used for certain services which can
 * be done either way.  Mail should be left tcp, the others are up to
 * the individual admin.  If the one you choose is not supported the
 * other type _may_ be used depending on the service.
 */

#define PREF_MAIL         SVC_TCP
#define PREF_FINGER       SVC_TCP
#define PREF_TELL         SVC_UDP

/* These macros are used by the name server to keep a list of muds which
 * do not support the DNS.
 */
#define MUD_ADDRESSES   "/adm/etc/mud_addresses"
#define MUD_SERVICES    "/adm/etc/mud_services"

#endif //__NET__CONFIG_H
