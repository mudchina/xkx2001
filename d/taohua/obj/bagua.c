//Cracked by Roath
// /d/taohua/obj/bagua.c
// by kane 7 / 97
// by kane 10/98
// by kane 2/2, special thanks for chu's compass
// by maco 9/29/99 add taohu,convert
// mantian 5/11/2001 add can't zhanbu taohua job npc

#include <ansi.h>
inherit ITEM;

#include "/d/REGIONS.h";

#define ROUTER "/clone/obj/traverser"

static object route_finder;
static object target_room;
// 0: idle, 1: searching
static int status;

int do_route(string, object);
int do_printroute(object);
void init();

void create()
{
	set_name("铁八卦", ({ "tie bagua", "bagua" }) );
	set_weight(10000);
	set_color(GRN);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "铁八卦是纯铁所铸，分量极重，上有八卦图案。\n"
			"出阵指令：chuzhen <方向>\n");
		set("unit", "枚");
		set("wield_msg", GRN "$N由口袋里拿出$n。\n" NOR );
		set("unwield_msg", GRN "$N将$n放回口袋中。\n" NOR );
		set("value", 1600);
		set("tanzhi",200);
	}
	setup();
}

void init()
{
	add_action("do_divine", "divine");
	add_action("do_divine", "zhanbu");
	add_action("do_chuzhen", "chuzhen");
	add_action("do_printroute", "printroute");
	add_action("do_taohua", "taohua");
	add_action("do_convert", "convert");
	add_action("do_convert", "huan");
}

int do_divine(string arg)
{
	object ob, where, env, me = this_player();
	mapping myfam;
	string region;
	int i, lvl, diff, busy_time;

	if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked")) return notify_fail("你现在正忙着呢。\n");
	myfam = (mapping)me->query("family");	
	if( !myfam || myfam["family_name"] != "桃花岛" ) return notify_fail("你非桃花弟子，不能将奇门遁甲用于占卜。\n");
	if( (lvl = (int)me->query_skill("qimen-dunjia", 1)) < 60 ) return notify_fail("你奇门遁甲等级不够。\n");
	if( me->query("jingli") < 100 ) return notify_fail("你的精力不够，不足以占卜！\n");
	if( me->query("jing") < 100 ) return notify_fail("你的精不够，不足以占卜！\n");
	if (!arg) return notify_fail("你要占卜谁的位置？\n");
	if( !(ob = find_player(arg)) ) if( !(ob = find_living(arg)) ) return notify_fail("现在没这个人.\n");
	message_vision(CYN"$N拿起一只铁八卦屏心凝气，拇指依次掐向铁八卦上子、丑、寅、卯、辰、巳、午、未、申、酉、戌、亥\n各个方位，细心推算起来……\n\n\n"NOR, me);
	busy_time = 25 - lvl/10;
	if(busy_time < 1) busy_time = 1;
	me->start_busy(busy_time);
	me->add("jing", -50);
	me->add("jingli", -50);
	if( arg == me->query("zangbu_yapu")) return notify_fail("这个人不知道在那里耶...\n");
	if( !(where = environment(ob))) return notify_fail("这个人不知道在那里耶...\n");
	if( !wizardp(me) && wizardp(ob) ) return notify_fail("大胆！竟想谋害巫师！\n");
	if( strsrch(file_name(where), "/d/") != 0 ||  undefinedp(region = region_names[explode(file_name(where), "/")[1]]) ) return notify_fail("这个人不知道在那里耶...\n");
	env = environment(me);
	diff = (int)(me->query("combat_exp")/ob->query("combat_exp"));
	if( lvl > 120 && !ob->query_temp("apply/name") && random(lvl / 10 + me->query_int() + diff) > ob->query_kar()/2 )
	{ 
		me->add("jing", -random(200-lvl));
		printf("%s(%s)现在在%s%s。\n", (string)ob->name(), (string)ob->query("id"), region, (string)where->query("short"));
		if( me->query("combat_exp") < me->query("int") * 5000 )
		{
			me->add("combat_exp", busy_time/2+1);
			if (me->query("potential")<me->query("max_potential")) me->add("potential",busy_time/3+1);
		}
		me->add_temp("apply/karma",random(3));
		if( lvl > 140 && !ob->query("yapu_target") )
		{
			do_route(file_name(where), me);
		}
		if( (random(lvl/2)+diff) < ob->query("kar") ) tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......\n"NOR);
	}
	else if( me->query_int() > random(ob->query_kar()) )
	{
		me->add("jing", -random(200-lvl));
		printf("%s(%s)现在在%s一带。\n", (string)ob->name(), (string)ob->query("id"), region);
		if( me->query("combat_exp") < me->query("int") * 5000 )
		{
			me->add("combat_exp", busy_time/3+2);
			if (me->query("potential")<me->query("max_potential")) me->add("potential",busy_time/4+1);
		}
		me->add_temp("apply/karma",random(2));
	 	if( (random(lvl/2)+diff) < ob->query("kar")/2 ) tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......\n"NOR);
	}
	else
	{
		write("你殚精竭虑推算了半晌，却发现一无所得…… \n");
		me->set("jing", 1);
		me->improve_skill("qimen-dunjia",random((int)me->query_int()));
	}
	me->improve_skill("qimen-dunjia", 2+random(3));
	return 1;
}

int do_chuzhen(string arg)
{
	object obj, env, me;
	string dest;
	mapping exit;

	if(!arg) return notify_fail("你要从哪个方向出阵？\n");
	me = this_player();
	if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked")) return notify_fail("你现在正忙着呢。\n");
	env = environment(me);	
	if( !env->query("th_buzhen") ) return notify_fail("这里并无布有奇门阵法。\n");
	if( me->query_skill("qimen-dunjia", 1) < 60 ) return notify_fail("你的奇门遁甲修为不够，无法看出阵法秘奥。\n");	
	if( me->query_skill("qimen-dunjia",1) < env->query("th_pozhen")/3)
	{
		message_vision(CYN"$N坐在地上冥思苦想，突然脸色大变，口吐鲜血！\n"NOR,me);
		me->unconcious();
		return notify_fail("");
	}
	exit = env->query("org_exits");
	dest = exit[arg];
	if(undefinedp(exit[arg])) return notify_fail("这个方向没有出路。\n");
	if( !(obj = find_object(dest)) ) call_other(dest, "???");
	if( !(obj = find_object(dest)) ) return notify_fail("这个方向没有出路。\n");
	message_vision(CYN"$N凝思片刻，身形左一转，右一旋，忽然消失得无影无踪。\n"NOR,me);	
	if( me->move(obj) )
	{
		message( "vision", me->name()+"快步走了过来。\n"NOR, 
		environment(me), ({me}) );
		return 1;
	}
	return 0;
}

int visit_room(string room_path, mapping traverse_info, mapping room_info, string target)
{
	string room_short, tmp;

	if (! room_info) return 0;
	// taking care of the colors in names
	room_short=explode(room_info["short"], ESC)[0];
	if (sscanf(room_short, "[%*dm%s", tmp) == 2) room_short = tmp;
	if (sscanf(room_short, "[%*d;%*dm%s", tmp) == 3) room_short = tmp;
	if (room_short == target)
	{
		target_room = find_object(room_path);
		if (! target_room)  target_room = load_object(room_path);
		// something wrong with the room, return 1 to prune the search branch
		if (! target_room)
		return 1;
		return -1;   // found room, done
	}
	return 0;      // otherwise, keep going
}

int do_route(string arg, object me)
{
	int ready;

	if (status == 1) return notify_fail("正在搜索路途. 用 printroute 来显示结果。\n");
	if (objectp(route_finder)) destruct(route_finder);
	route_finder = new (ROUTER);
	if (! objectp(route_finder))
	{
		target_room = 0;
		return notify_fail("奇怪,不能造出 "+ROUTER+"?\n");
	}
	status = 1;
	target_room = find_object(arg);
	if (! target_room)  target_room = load_object(arg);
	if (! objectp(target_room))
	{
	    // return notify_fail("目标房间 "+arg+" 不存在.\n");
	    // assume arg is a short name, not file path
	    ready = route_finder->traverse(base_name(environment(me)), (: visit_room :), arg);
	}
	else
	{
		ready = route_finder->find_route(base_name(environment(me)), base_name(target_room));
	}
	if (ready)  return do_printroute(me);
	return notify_fail("已经开始搜索路途，用 printroute 来显示结果.\n");
}

int do_printroute(object me)
{
	mapping info;
	mixed   route;
	int     i, n, wizp, lvl;
	object  room;
	string  room_file, room_short;

	lvl = me->query_skill("qimen-dunjia",1);
	if (status == 0) return notify_fail("请先用 route 来查路途.\n");
	if (! objectp(route_finder))
	{
		status = 0;
		target_room = 0;
		route_finder = 0;
		return notify_fail("奇怪，object maproute 不见了.\n");
	}
	if (! route_finder->traverse_finish())
	{
		return notify_fail("还没找到，请等等再来查.\n");
	}
	status = 0;
	if (target_room)
	{
		route = route_finder->thread_route(base_name(target_room));
	}
	else
	{
		status = 2;
	}
	target_room = 0;
	destruct(route_finder);
	route_finder = 0;

	if (status == 2)
	{
		return notify_fail("没有这个房间.\n");
		status = 0;
	}
	if ((int)route == 1)
	{
		return notify_fail("没有去此房间的道路.\n");
	}
	if (sizeof(route) <= 1)
	{
		return notify_fail("你不就在这儿吗？\n");
	}
	printf("找到了道路，从这里开始：\n");
	n = sizeof(route);
	if(n > lvl/20) n = lvl/20;
	wizp = wizardp(me);
	for (i=1; i<n; i++)
	{
		room_file = keys(route[i])[0];
		room = find_object(room_file);
		if (! objectp(room) ) room = load_object(room_file);
		if (objectp(room))
		{
			room_short=room->query("short");
		}
		else
		{
			room_short="不知道哪儿";
	    }
	    info = route[i][room_file];
	    if (info["dir"] == "cross_river")
		{
			printf("摆渡过"+room->query("name"));
		}
		else if (strsrch(info["dir"], "out_sea")==0)
		{
			printf("坐船渡海");
		}
		else
		{
			printf("往 %s ", info["dir"]);
		}
		printf("到 %s %s, 距离 %s步\n", room_short, wizp?"("+room_file+")":"", chinese_number(info["dist"]));
	}
	if(n < sizeof(route)) printf("......不知道哪儿.\n");
	return 1;
}

int do_taohua(string arg)
{
	object me, obj;
	me = this_player();
	if (me->query("family/family_name") != "桃花岛") return 0;

	if(arg) return 0;
	write("你目前有桃花经验"+me->query("th_exp")+"点，桃花潜能"+me->query("th_pot")+"点。\n");
	return 1;
}

int do_convert(string arg)
{
	object me, obj;
	int th_exp, th_pot, exp, pot, max_pot, use_pot;
	
	me = this_player();
	exp = me->query("combat_exp");
	pot = me->query("potential");
	max_pot = me->query("max_potential");
	th_exp = me->query("th_exp");
	th_pot = me->query("th_pot");
	use_pot = max_pot-pot;
	if(use_pot > th_pot) use_pot = th_pot;
	if (me->query("family/family_name") != "桃花岛") return 0;
	if(!arg) return notify_fail("指令格式：convert || huan [ exp || pot ] \n");
	if(arg == "exp")
	{
		if(th_exp == 0)
		return notify_fail("你现在没有桃花经验。\n");
		write("你将"+th_exp+"点桃花经验全部转换为实际经验。\n");
		me->add("combat_exp",th_exp);
		me->delete("th_exp");
	}
	else if(arg == "pot")
	{
		if(th_pot == 0)
		return notify_fail("你现在没有桃花潜能。\n");
		if(pot >= max_pot)
		return notify_fail("你的潜能已经满了，无法转换桃花潜能。\n");
		write("你将"+use_pot+"点桃花潜能转换为实际潜能，还剩下"+(th_pot-use_pot)+"点。\n");
		me->add("potential",use_pot);
		me->add("th_pot", -use_pot);
	}
	else return notify_fail("指令格式：convert || huan [ exp || pot ] \n");
	return 1;
}
