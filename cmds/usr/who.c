//Change by Server
// who.c
// modified by xuy 07/29/97

#include <net/daemons.h>
#include <net/dns.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

#define O_SHAOLIN	0x1;
#define O_WUDANG	0x2;
#define O_GAIBANG	0x4;
#define O_EMEI		0x8;
#define O_HUASHAN	0x10;
#define O_DALI		0x20;
#define O_TAOHUA	0x40;
#define O_XINGXIU	0x80;
#define O_SHENLONG	0x100;
#define O_XUESHAN	0x200;
#define O_XUEDAO	0x200;
#define O_BAITUO	0x400;
#define O_QUANZHEN	0x800;
#define O_GUMU	0x1000;
#define O_LINGJIU  0x2000;
#define O_OTHER     0x4000;

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	 string str, *option, *sites;
    object *list;
    int i, j, ppl_cnt, total;
    int opt_long, opt_id, opt_wiz, family=0;

    if( arg ) {
        option = explode(arg, " ");
    	i = sizeof(option);
    	while( i-- )
				switch(option[i]) {
		case "-l": 	opt_long = 1;	break;
		case "-i": 	opt_id = 1;	break;
		case "-w": 	opt_wiz = 1;	break;
		case "-quanzhen":family |= O_QUANZHEN;	break;
		case "-gumu":family |= O_GUMU;	break;
		case "-shaolin":family |= O_SHAOLIN;	break;
		case "-wudang": family |= O_WUDANG;	break;
		case "-gaibang":family |= O_GAIBANG;	break;
		case "-emei":   family |= O_EMEI;  break;
		case "-huashan":family |= O_HUASHAN; break;
		case "-dali":   family |= O_DALI; break;
		case "-taohua": family |= O_TAOHUA; break;
		case "-xingxiu":family |= O_XINGXIU; break;
		case "-lingjiu": family |= O_LINGJIU; break;
		case "-shenlong":family|= O_SHENLONG; break;
		case "-xueshan":family |= O_XUESHAN; break;
		case "-xuedao": family |= O_XUEDAO; break;
		case "-baituo": family |= O_BAITUO; break;
		case "-other" : family |= O_OTHER; break;
		default:
			 if( remote ) break;
		    if( option[i][0]=='@' ) {
			RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
						me, arg);
			write("网路讯息已送出，请稍候。\n");
			return 1;
		    }
		    return notify_fail("指令格式：who [-l|-i|-w|-shaolin|-wudang|...] [@site]\n");
	    }
    }

    if( !remote && opt_long && wizardp(me)) {
	if( (int)me->query("jing") < 30 )
	    return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
	me->receive_damage("jing", 30);
	 }

	 if (opt_wiz && me ) {
	sites = keys(DNS_MASTER->query_svc());
	j = sizeof(sites);
		  for(i=0; i<j; i++)
		 RWHO_Q->send_rwho_q(sites[i], me, arg);
	 }

	 str = "◎ " + INTERMUD_MUD_CNAME + "\n";
	 str += "─────────────────────────────────────\n";
	 list = users();
	 total = sizeof(list);
	 if (family) list = filter_array(list, "filter_user", this_object(), family);
	 list = sort_array(list, "sort_user", this_object());
	 if( opt_long || opt_wiz ) {
	ppl_cnt = 0;
		j = sizeof(list);
		while( j-- ) {
				// Skip those users in login limbo.
		 if( !environment(list[j]) ) continue;
		 if( me && !me->visible(list[j]) ) continue;
		 if( opt_wiz && !wizardp(list[j]) ) continue;
		 str = sprintf("%s%12s %s\n", str, RANK_D->query_rank(list[j]),
			  list[j]->short(1) );
		 ppl_cnt++;
	}
	 } else {
	ppl_cnt = 0;
	j = sizeof(list);
	while( j-- ) {
	// Skip those users in login limbo.
		 if( !environment(list[j]) ) continue;
		 if( me && !me->visible(list[j]) ) continue;
		 str = sprintf("%s%-15s%s", str,
				opt_id ? capitalize(list[j]->query("id")): list[j]->name(1),
				(ppl_cnt%5==4? "\n": "")
			);
		 ppl_cnt++;
		  }
	if( ppl_cnt%5 ) str += "\n";
	 }

	 str += "─────────────────────────────────────\n";
	 str = sprintf("%s共有%s位使用者连线中，系统负担：%s\n", str, chinese_number(total),
		query_load_average() + "\n");

	 if( remote ) return (ppl_cnt ? str : 0);

	 me->start_more(str);
	 return 1;
}

string do_who(string arg)
{
	 string str, *option, *sites;
    object *list;
    int i, j, ppl_cnt, total;
    int opt_long, opt_id, opt_wiz, family=0;

    if( arg ) {
        option = explode(arg, " ");
    	i = sizeof(option);
    	while( i-- )
				switch(option[i]) {
		case "-l": 	opt_long = 1;	break;
		case "-i": 	opt_id = 1;	break;
		case "-w": 	opt_wiz = 1;	break;
		case "-quanzhen":family |= O_QUANZHEN;	break;
		case "-gumu":family |= O_GUMU;	break;
		case "-shaolin":family |= O_SHAOLIN;	break;
		case "-wudang": family |= O_WUDANG;	break;
		case "-gaibang":family |= O_GAIBANG;	break;
		case "-emei":   family |= O_EMEI;  break;
		case "-huashan":family |= O_HUASHAN; break;
		case "-dali":   family |= O_DALI; break;
		case "-taohua": family |= O_TAOHUA; break;
		case "-xingxiu":family |= O_XINGXIU; break;
		case "-lingjiu": family |= O_LINGJIU; break;
		case "-shenlong":family|= O_SHENLONG; break;
		case "-xueshan":family |= O_XUESHAN; break;
		case "-xuedao": family |= O_XUEDAO; break;
		case "-baituo": family |= O_BAITUO; break;
		case "-other" : family |= O_OTHER; break;
		default:
	    }
    }


	 str = "◎ " + INTERMUD_MUD_CNAME + "\n";
	 str += "─────────────────────────────────────\n";
	 list = users();
	 total = sizeof(list);
	 if (family) list = filter_array(list, "filter_user", this_object(), family);
	 list = sort_array(list, "sort_user", this_object());
	 if( opt_long || opt_wiz ) {
	ppl_cnt = 0;
		j = sizeof(list);
		while( j-- ) {
				// Skip those users in login limbo.
		 if( !environment(list[j]) ) continue;
		 if( opt_wiz && !wizardp(list[j]) ) continue;
		 str = sprintf("%s%12s %s\n", str, RANK_D->query_rank(list[j]),
			  list[j]->short(1) );
		 ppl_cnt++;
	}
	 } else {
	ppl_cnt = 0;
	j = sizeof(list);
	while( j-- ) {
	// Skip those users in login limbo.
		 if( !environment(list[j]) ) continue;
		 str = sprintf("%s%-15s%s", str,
				opt_id ? capitalize(list[j]->query("id")): list[j]->name(1),
				(ppl_cnt%5==4? "\n": "")
			);
		 ppl_cnt++;
		  }
	if( ppl_cnt%5 ) str += "\n";
	 }

	 str += "─────────────────────────────────────\n";
	 str = sprintf("%s共有%s位使用者连线中，系统负担：%s\n", str, chinese_number(total),
		query_load_average() + "\n");


	 return str;
}

int filter_user(object user, int family)
{
	string fam = user->query("family/family_name");
        switch (fam) {
	    case "少林派": return family & O_SHAOLIN; break;
		 case "武当派": return family & O_WUDANG; break;
		 case "丐帮"  : return family & O_GAIBANG; break;
		 case "峨嵋派": return family & O_EMEI; break;
		 case "华山派": return family & O_HUASHAN; break;
		 case "大理段家": return family & O_DALI; break;
		 case "桃花岛": return family & O_TAOHUA; break;
         case "星宿派": return family & O_XINGXIU; break;
         case "灵鹫宫": return family & O_LINGJIU; break;
		 case "神龙教": return family & O_SHENLONG; break;
		 case "雪山派":
		 case "血刀门": return family & O_XUESHAN; break;
		 case "白驼山": return family & O_BAITUO; break;
		 case "全真教": return family & O_QUANZHEN; break;
		 case "古墓派": return family & O_GUMU; break;
		 default:	   return family & O_OTHER; break;
	}

	return 0;
}

int sort_user(object ob1, object ob2)
{
	string *family;
	int rank1,rank2, i;
	string family1, family2;

	if( wiz_level(ob1) || wiz_level(ob2) )
		return wiz_level(ob2) - wiz_level(ob1);

	family =
	({
		"全真教",
		"古墓派",
		"少林派",
		"武当派",
		"丐帮",
		"峨嵋派",
		"华山派",
		"大理段家",
		"桃花岛",
		"星宿派",
        "灵鹫宫",
		"神龙教",
		"雪山派",
		"血刀门",
		"白驼山"
	});

	family1 = ob1->query("family/family_name");
	family2 = ob2->query("family/family_name");
	rank1 = member_array(family1, family);
	rank2 = member_array(family2, family);

	if( rank1 > rank2 ) return -1;
	if( rank2 > rank1 ) return 1;

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-i|-w|-shaolin|-wudang|...] [@site]

这个指令可以列出所有在线上的玩家及其等级。

-l 选项列出较长的讯息。
-i 只列出玩家的英文代号。
-w 只列出线上所有的巫师。
-menpai 只列出此门派的玩家。menpai 可以是以下任意一个：
  shaolin, wudang, gaibang, emei, huashan, dali, taohua,
  shenlong, xingxiu, xueshan, xuedao, baituo, other.
@site 显示其他「侠客行」站点的信息。

范例：who, who -w, who -i -wudang -emei, who -l -shaolin @sh
相关指令： finger, locate, mudlist
HELP
	 );
	 return 1;
}
