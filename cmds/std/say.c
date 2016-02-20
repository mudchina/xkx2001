//Cracked by Roath
// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

string* words = ({
	"万年不老",
	"仙福永享",
	"寿与天齐",
	"神通广大",
	"战无不胜",
	"功无不克",
	"无坚不摧",
	"无敌不破",
	"教主宝训，时刻在心",
	"神目如电，烛照四方",
});

int main(object me, string arg)
{
	int i;
	int point, count;
	object *inv;	

	if (!arg) {
		write("你自言自语不知道在说些什么。\n");
		message("sound", me->name() + "自言自语不知道在说些什么。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	if( me->query("family/family_name") == "神龙教" 
	&&  me->query("jing") >= 30
	&&  me->query("jingli") >= 30 ) {

		inv = all_inventory(environment(me));
		if( !sizeof(inv) ) count = 0;
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			if( userp(inv[i]) && inv[i] != me ) count++;
		}

		point = me->query_skill("dulong-dafa", 1);
		for(i=0; i<sizeof(words); i++) {
			if( (strsrch(arg, "洪教主") >= 0 || strsrch(arg, "洪夫人") >= 0) 
			&& strsrch(arg, words[i]) >= 0 
			&& point <= 100 && point >= 30 
			&& count > 0 ) {
				me->improve_skill("dulong-dafa", random(point*2 + count*10));
				me->receive_damage("jing", random(point*2), "大声呐喊，精神衰竭而死");
				me->receive_damage("jingli", random(point*2), "大声呐喊，精力衰竭而死");
				break;
			}
		}
	}

	write( CYN "你说道：" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "说道：" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
