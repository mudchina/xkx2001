//Cracked by Roath
// jitan.c 法坛
// Ryu

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"法坛"NOR, ({ "fa tan", "altar", "tan" }) );
	set_weight(300000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "这是一个极其庞大的铜制祭坛，高约三丈，方圆约有五丈，乃是当年吐番国王亲\n"
			    "自指挥铸造的，耗倾国之力，十年方成。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
	add_action("do_light", "light");
	add_action("do_spray", "peng");
	add_action("do_dazuo", "dazuo");
	add_action("do_wave", "wave");
	add_action("do_spray", "spray");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("你要将什么东西放进哪里？\n");
                
        if( item == "all" ) {
		write("还是一样一样来吧。\n");
		return 1;
	}
                                                                
	sscanf(item, "%d %s", amount, item);
	
	if( !objectp(obj = present(item, me)) )
		return notify_fail("你要给谁什么东西？\n");

	if( obj->query("id") != "corpse"){
		write("你不往祭坛里放这样东西。\n");
		return 1;
	}
}
int do_light(string arg)
{
	object  me = this_player();

	if (!present("fire", me))
		return notify_fail("你要用什么点火？\n");
	if (!query("in_use"))
		return notify_fail("你要点燃什么？\n");
        if (!id(arg))
                return notify_fail("你要点燃什么？\n");
	message_vision(HIR"$N点燃了祭坛中的木柴与酥油，熊熊烈火冲天而起。\n"NOR, me);
	set("burning", 1);
	set("pending", me->query("name"));
	set("long", query("long") + HIR"里面燃着熊熊的火焰。\n"NOR);
	set("in_use", 0);
	remove_call_out("burning");
        call_out("burning",20+random(20), me);
	return 1;
}
void burning(object me)
{
	int point;
	point = me->query_temp("award_pending")*10/me->query("combat_exp");
	point = point * me->query_skill("lamaism")/12;
	if (me->query("combat_exp") < 150000) point = point/2;
	message_vision(BLU"一丝魂魄升出祭坛，冉冉而起。魂魄受$N佛法感召，徘徊不去。\n"NOR, me);
	if (me->query_temp("award_pending"))
	me->add("potential", point + random(point/2));
	if (me->query_temp("award_doubling"))
	me->set("potential", me->query("max_potential"));
	if (me->query("potential") > me->query("max_potential"))
	me->set("potential", me->query("max_potential"));
	set("wait_for_spray", 1);
}
int do_spray(string arg)
{
	object  ob, me = this_player();
	ob = (present("lubo", me));
	
	if (!present("lubo", me))
		return 0;
	if (me->query("name") != query("pending"))
		return notify_fail("你跟这儿凑什么热闹？\n");
	if (!query("wait_for_spray"))
		return notify_fail("时辰未到！\n");
	if (!id(arg))
                return notify_fail("你想往哪儿喷？\n");
	if (ob->query("liquid/remaining") < 1)
		return notify_fail("颅钵里面的水已经所剩无几了。\n");

	message_vision(HIW"$N端起颅钵吸进一口水，「噗」的一声猛地朝那熊熊火焰喷将过去。\n"NOR, me);
	ob->add("liquid/remaining", -1);
	set("wait_for_spray", 0);
	set("time_to_dazuo", 1);
	return 1;
}
int do_dazuo()      
{
	object me = this_player();
	
	if (me->query("name") != query("pending"))
                return notify_fail("你凑什么热闹？\n");
	if (me->query("neili") < 600)
		return notify_fail("你内力不够！\n");
	if (!query("time_to_dazuo"))
                return notify_fail("这不是你打坐的时候。\n");

	message_vision(HIY"$N盘腿打坐，神光内蕴，口中念念有辞，渐渐有一丝魂魄在$N面前凝聚成形。\n"NOR, me);
	me->start_busy(20);
	remove_call_out("rise");
        call_out("rise",20+random(20), me);
	return 1;
}
void rise(object me)
{
       message_vision(BLU"魂魄越聚越多，竟然呈出人形！ $N手指人形，口念真言，指引往生之路。\n"NOR, me);
	me->add("neili", -600);
	if (me->query_temp("award_pending")*10/me->query("combat_exp") >= 16)
        me->add("max_neili", me->query_skill("lamaism", 1)/60);
        if (me->query_temp("award_doubling"))
        me->add("max_neili", me->query_skill("lamaism", 1)/10);
        set("time_to_dazuo", 0);
	set("time_to_wave", 1);
}
int do_wave(string arg)
{
	object weapon, me = this_player();

	if (!arg && arg != "ling" && arg != "fa ling")
		return notify_fail("你要摇什么？\n");
		
	if (!present("fa ling", me))
		return notify_fail("你要摇什么？\n");

	if (me->query("name") != query("pending"))
                return notify_fail("你跟这儿凑什么热闹？\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| (me->query_temp("weapon"))->query("name") != "法铃")
		return notify_fail("你手中没有这样东西。\n");
	
	if (!query("time_to_wave"))
		return notify_fail("时辰未到！\n");

	message_vision(CYN"$N手持法铃，边走边摇，高声诵读密传经咒。突然大喝一声。声似雷霆。\n"NOR, me);
	set("time_to_wave", 0);
	remove_call_out("close_up");
        call_out("close_up",20+random(20), me);
	me->start_busy(20);
	return 1;
}
void close_up(object me)
{
	object ob = this_object();
	int gaining;
	gaining = me->query_temp("award_pending")*10/me->query("combat_exp");
	gaining = 14 * gaining;
	if (gaining > 300) gaining = 300;	
	if (me->query("combat_exp") < 80000)
	gaining = gaining/3;
	if (me->query("combat_exp") > 80000 && me->query("combat_exp") < 100000)
	gaining = gaining/2;

	message_vision(HIW"大院里光茫四起，一声巨响过后，又恢复了平静。超度完毕。\n"NOR, me);
	set("long", "这是一个极其庞大的铜制祭坛，高约三丈，方圆约有五丈，乃是当年吐番国王亲\n"
    		    "自指挥铸造的，耗倾国之力，十年方成。\n");
	set("long", query("long") + RED"里面燃着的火焰快熄灭了。\n"NOR);
	me->improve_skill("lamaism", me->query("int"));
	me->add("jingli", -300, "把自己超度了");
	set("burning", 0);
	if (me->query_temp("award_pending"))
        me->add("combat_exp", gaining + random(gaining/2));
       // if (me->query_temp("award_doubling"))
        //me->add("combat_exp", (int)me->query_temp("award_pending")/50);	
	me->delete_temp("award_pending");
	me->delete_temp("award_doubling");
	me->delete_temp("marks/葛");
	if (random(me->query("potential")) > me->query_con()*3)
	me->unconcious();
	remove_call_out("renewing");
        call_out("renewing", 50 + random(100), ob);
}
void renewing(object ob)
{
	ob->set("last_burner", ob->query("pending"));
	ob->set("pending", 0);
	ob->set("long", "这是一个极其庞大的铜制祭坛，高约三丈，方圆约有五丈，乃是当年吐番国王亲\n"
    			"自指挥铸造的，耗倾国之力，十年方成。\n");
}				 
