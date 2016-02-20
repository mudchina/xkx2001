//Cracked by Kafei
/*
 * File    : rwho_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to send a reply to a remote who request.
 */
// Modified by xuy@XKX 

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

// They have answered our remote who question.

void incoming_request(mapping info)
{
	int uptime, usernum;
	object ob;

	if( !ACCESS_CHECK(previous_object())) return;

	if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"])) {
		if (info["NAME"] == Mud_name())	return ;
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
		if (stringp(info["ASKWIZ"]) && info["ASKWIZ"] == DNS_RWHO_A) {
			if( sscanf(info["RWHO"], "%d/%d", usernum, uptime) == 2) {
				this_object()->set(info["NAME"]+"/USERNUM", usernum);
				this_object()->set(info["NAME"]+"/UPTIME", uptime);
			}
			return;
		}
			
		if (!(ob = find_player(lower_case(info["ASKWIZ"])))) return ;
		tell_object(ob, info["RWHO"]);
	}
}

void create()
{
	seteuid(ROOT_UID);
	call_out("refresh_cache", 60);
}

void refresh_cache()
{
	int i;
	mapping mud_list;
	string *muds;

	while(find_call_out("refresh_cache") != -1) {}

	call_out("refresh_cache", 60);
	
	mud_list = (mapping)DNS_MASTER->query_muds();

	if(!mud_list) return;
	
	muds = keys(mud_list);
	i = sizeof(muds);
	while (i--) {
		if(lower_case(muds[i]) == lower_case(Mud_name())) continue;
		this_object()->set(mud_list[muds[i]]["NAME"]+"/UPTIME", -1);
		(AUX_PATH + DNS_RWHO_Q)->send_rwho_q(muds[i], this_object(), "");
	}
		
}
