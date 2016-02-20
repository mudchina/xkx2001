//Cracked by Roath
// jinshe_book1.c 假金蛇秘笈

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("金蛇秘笈", ({ "jinshe miji", "miji", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", 
		"这是金蛇郎君遗下的《金蛇秘籍》。载有武功绝学，地图，\n"
		"兵刃和机关图样。\n");
		set("value", 10000000);
		set("material", "paper");
		set("no_drop","这样东西不能离开你。\n");
	}
}

void init()
{
	add_action("do_read", "study");
	add_action("do_read", "du");
}

int do_read(string arg)
{
	object me = this_player();

	if (!arg || arg=="") 
                return notify_fail("你想读那项武功？剑法(jianfa)，锥法(zhuifa)，还是掌法(zhangfa)？\n");

	if ( arg == "zhangfa" || arg == "jianfa" || arg == "zhuifa" ) {
		message_vision("$N伸食指在口中一舔，蘸了些唾液翻阅起书来。\n", me);

		if ( !me->query_temp("poison") ) {
			me->set_temp("poison", 1);
			call_out("poison", 20, me);
		}
		
		return 1;
	}

	write("你想读那项武功？剑法(jianfa)，锥法(zhuifa)，还是掌法(zhangfa)？\n");

        return 1;
}

int poison(object me)
{
	me->delete_temp("poison");
	tell_object(me, HIR"你突然感到一阵晕旋，原来是书上剧毒发作了！\n"NOR);
	message("vision", me->name()+"脚下几个踉跄，双脚一蹬便不动了，眼、耳、鼻、口中都流出黑血来！\n", environment(me), ({me}) );
	me->receive_wound("qi", me->query("max_qi")+100, "剧毒发作死了");

	return 1;
}
