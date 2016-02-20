//Cracked by Kafei
//      /adm/daemons/network/services/remote_q.c
//	create by Xuy@XKX 9/22/97

#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void send_remote_q(string mudname, string myinfo, string channel, string emote, string target) {
    mapping info;
    mapping mud;
    int i;

    if(lower_case(mudname) == lower_case(Mud_name())) return;
    mud=(mapping)DNS_MASTER->query_mud_info(mudname);
    if(!mapp(mud)) return;
    DNS_MASTER->send_udp(mud["HOSTADDRESS"],
          mud["PORTUDP"], "@@@"+DNS_REMOTE_Q+
      "||NAME:"+Mud_name()+
      "||PORTUDP:"+ udp_port() +
      "||TARGET:"+lower_case(target)+
      "||ASKWIZ:"+myinfo+
      "||CHANNEL:"+channel+
      "||EMOTE:"+emote+
        "@@@\n");
    return;
}

void incoming_request(mapping info) {
    string target;
    string msg;

    if(!info["NAME"] || !info["PORTUDP"] ) return;
    if(!DNS_MASTER->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

    msg = EMOTE_D->do_intermud_emote(info["ASKWIZ"], info["EMOTE"], info["TARGET"]);
    if( !stringp(msg) ) return;

    if(!stringp(info["CHANNEL"])) return;
    
    CHANNEL_D->do_channel(this_object(), info["CHANNEL"], msg, 1);

    GCHANNEL->send_msg(info["CHANNEL"], "gchannel", "gchannel", msg, 1, 1);
}

void create()
{
    seteuid(ROOT_UID);
    set("channel_id", "");
}
