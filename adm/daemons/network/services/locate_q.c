//Cracked by Kafei
//      /adm/daemons/network/dns_aux/locate_q.c
//      from the TMI-2 Mudlib
//      the locate_q for the UDP locate function
//      created by Descartes of Borg 931017
//	modified by Xuy@XKX 09/25/97

#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

object *find_users(string arg);
int maybe(object ob, string arg);

void send_locate_q(string who) {
    mapping info;
    string *muds;
    int i;

    i = sizeof(muds = keys(info=(mapping)DNS_MASTER->query_muds()));
    while(i--) {
        if(lower_case(muds[i]) == lower_case(Mud_name())) continue;
        DNS_MASTER->send_udp(info[muds[i]]["HOSTADDRESS"],
          info[muds[i]]["PORTUDP"], "@@@"+DNS_LOCATE_Q+
      "||NAME:"+Mud_name()+
      "||PORTUDP:"+ udp_port() +
      "||TARGET:"+lower_case(who)+
      "||ASKWIZ:"+(string)this_player()->query("id")+
        "@@@\n");
    }
    return;
}

void incoming_request(mapping info) {
    int i;
    string field, target="";
    object *targets;

    if(!info["NAME"] || !info["PORTUDP"]) return;
    if(!DNS_MASTER->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    if(!info["TARGET"]) field = "NO";
    else 
      field = (pointerp(targets=find_users(info["TARGET"])) && sizeof(targets)) ? "YES" : "NO";
    if( field == "YES" ) 
      for(i=0; i<sizeof(targets); i++) 
	if (target->query("env/invisibility")<10)
	 target += "\n"+targets[i]->short(1);
    DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
      "@@@"+DNS_LOCATE_A+"||NAME:"+Mud_name()+
      "||CNAME:"+Mud_cname()+
      "||PORTUDP:"+udp_port()+
      "||LOCATE:"+field+
      "||TARGET:"+target+
      "||ASKWIZ:"+info["ASKWIZ"]+"@@@\n");
}

object *find_users(string arg) {
    object target, *result;

    if( !arg || arg == "" ) return result;

    if( arg[0] < 128 ) {
	target = find_player(lower_case(arg));
	if(objectp(target) && target->query("env/invisibility")<10 ) result = ({target});
	return result;
    }

    result = users();
    if(pointerp(result)) result = filter_array(result, "maybe", this_object(), arg);
    return result;

}

private int maybe(object ob, string arg) {
    if(objectp(ob) && environment(ob) && ob->name(1) == arg 
       && ob->query("env/invisibility")<10 ) return 1;
    return 0;
}
