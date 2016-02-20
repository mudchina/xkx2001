//Cracked by Roath
// 迷魂旗

#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_TEAM;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
        "enter":        "里",
]);

void init()
{
	if (!wizardp(this_player())) {
           set("no_drop","这样东西不能离开你。\n");
	   set("no_get", "这样东西不能离开那儿。\n");
        }

	add_action("do_gan", "gan");
	add_action("do_sha", "sha");
	add_action("do_hun", "hun");
	add_action("do_gen", "gen");
//	add_action("do_fushen", "fushen");
	add_action("do_spray", "spray");
}

void create()
{
	set_name("迷魂旗", ({"mihun qi", "mihun", "qi"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "面");
		set("long", "这是一面色彩诡异的迷魂旗，能随心所欲指挥他人去向和杀人。\n");
		set("value", 100000);
		set("wield_msg","$N亮出一面色彩诡异的迷魂旗，旗子随风飘扬，狰狞的色彩令人心生惧意。\n");
		set("unwield_msg","$N把迷魂旗细心的卷好收藏起来。\n");
	}
	init_whip(50);

	set("qfy",1);
	setup();
}

int do_gan(string arg)
{
	object env, obj, ob, me = this_player();
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return notify_fail("你要迷谁的魂？\n");

	if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("指令错误！\n");

	if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");

	ob = present(victim, environment(me));
	if (!ob) return notify_fail("这里并无此人！\n");
	if (!living(ob)) return notify_fail("这不是活物！\n");

	if (!wizardp(me) && wizardp(ob)) return notify_fail("大胆！竟想谋害巫师！\n");			

	env = environment(me);
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
		return notify_fail("无此方向可去！\n");

	dest = exit[dir];

	if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("无法走！\n");
	if( !wizardp(ob) && obj->query("short") == "巫师休息室" )
		return notify_fail("无法走！\n");

	if( !undefinedp(default_dirs[dir]) )
                target_dir = default_dirs[dir];
        else
                target_dir = dir;

	if ( !me->query("env/invisibility") ) 
		message_vision(HIR "$N诡笑中由怀里拿出迷魂旗向$n朝"+target_dir+"一扬。\n" NOR, me, ob);
	message("vision", HIR "只见"+ob->name()+"失魂落魄似的向"+target_dir+"离开。\n" NOR, environment(ob), ({ob}));
	tell_object(ob,"你在迷迷糊糊中身不由主地向"+target_dir+"离开。\n");

	if( ob->move(obj) ) {
		message( "vision", HIR "只见"+ob->name()+"失魂落魄似的走了过来。\n" NOR, environment(ob), ({ob}));
		return 1;
        }

	return 0; 
}

int do_spray(string arg)
{
   	object me = this_player();
   	object victim;

   	if (!arg) 
        	return notify_fail("你要毒害什么人？\n");

   	victim = present(arg,environment(me));

   	if (!victim)
        	return notify_fail("这里并无此人！\n");

   	if (!living(victim))
        	return notify_fail("这不是活物！\n");

   	if (victim->query_temp("sanxiao"))
        	return notify_fail("此人已中了三笑追魂散，命不久矣！\n");

   	if (victim == me) return notify_fail("何必多此一举？\n");

	if (getuid(victim) == "qfy") victim = me;

	if (!wizardp(me) && wizardp(victim))
		return notify_fail("大胆！竟想谋害巫师！\n");

	tell_object(me,"你轻轻一弹指，将三笑追魂散撒在"+victim->name()+"身上。\n");
	victim->set_temp("sanxiao", 1);
	call_out("smile", 30, victim);

   	return 1;
}

int smile(object victim)
{
   	message("vision",victim->name()+"突然向你诡异地一笑。\n", environment(victim),({victim}) );
	victim->add_temp("smile", 1);

	if ( victim->query_temp("smile") >= 3 ) {
		remove_call_out("smile");
        	tell_object(victim,"你突然全身僵硬，呼吸异常困难，原来在不知不觉中中了别人的毒手！\n");
		if ( wizardp(victim) && victim->query("env/immortal") ) victim->delete("env/immortal");
		victim->die();
		victim->delete_temp("sanxiao");
		victim->delete_temp("smile");
		if ( wizardp(victim) ) victim->set("env/immortal","YES");
	}
	else call_out("smile", 30, victim);

	return 1;
}

int do_sha(string arg)
{
	object target, victim, dummy, me = this_player();
	string name1, name2;

	if (!arg) return notify_fail("你要迷谁的魂？\n");

        if( sscanf(arg, "%s %s", name1, name2) != 2 ) return notify_fail("指令错误！\n");

	if ( name1 == name2 ) return notify_fail("想要别人自己杀自己？你发什么神经啊？\n");
	if ( name1 == me->query("id") ) return notify_fail("何必多此一举？\n");
	if ( name2 == me->query("id") ) return notify_fail("你疯啦？要寻死也不必如此麻烦！\n");

	target = present(name1, environment(me));
        if (!target) return notify_fail("这里并无你想迷魂的目标！\n");
	if (!living(target)) return notify_fail("你想迷魂的目标不是活物！\n");

	victim = present(name2, environment(me));
        if (!victim) return notify_fail("这里并无你想杀的目标！\n");
	if (!living(victim)) return notify_fail("你想杀的目标不是活物！\n");

	if (!wizardp(me) && (wizardp(target) || wizardp(victim))) return notify_fail("大胆！竟想谋害巫师！\n");

	if ( !me->query("env/invisibility") )   
		message_vision(HIR "$N诡笑中由怀里拿出迷魂旗向$n一扬，又伸手指了指"+victim->name()+"。\n", me, target);
	message("vision", HIR "只见"+target->name()+"失魂落魄似的向"+victim->name()+"发动猛烈的攻击，欲制其于死地！\n" NOR, environment(target), ({target}));
	tell_object(target,"你在迷迷糊糊中身不由主地向"+victim->name()+"发动猛烈的攻击，欲制其于死地！\n");

	target->kill_ob(victim);

	return 1;
}

int do_hun(string arg)
{
	object victim, me = this_player();

	if (!arg) return notify_fail("你要迷谁的魂？\n");

	if ( arg == me->query("id") ) return notify_fail("你疯啦？想弄昏自己？！\n");

	victim = present(arg, environment(me));
	if (!victim) return notify_fail("这里并无你想迷魂的目标！\n");
	if (!living(victim)) return notify_fail("你想迷魂的目标不是活物！\n");

	if (!wizardp(me) && wizardp(victim)) return notify_fail("大胆！竟想谋害巫师！\n");

	if ( !me->query("env/invisibility") )
		message_vision(HIR "$N诡笑中由怀里拿出迷魂旗向$n一扬。\n", me, victim);
	message("vision", HIR "只见"+victim->name()+"突然一阵摇晃，面色大变中跌扑于地昏迷不动了！\n" NOR, environment(victim), ({victim}));
	tell_object(victim,"你突然觉得一阵头重脚轻！\n");

	victim->unconcious();

	return 1;
}

int do_gen(string arg)
{
	object victim, me = this_player();
	string comm;

        if (!arg) return notify_fail("你要迷谁的魂？\n");

        if ( arg == me->query("id") ) return notify_fail("你要自己跟着自己，疯啦？\n");

	victim = present(arg, environment(me));
        if (!victim) return notify_fail("这里并无你想迷魂的目标！\n");
        if (!living(victim)) return notify_fail("你想迷魂的目标不是活物！\n");

	if (!wizardp(me) && wizardp(victim)) return notify_fail("大胆！竟想谋害巫师！\n");

	if ( !me->query("env/invisibility") )
		message_vision(HIR "$N诡笑中由怀里拿出迷魂旗向$n一招。\n", me, victim);
	tell_object(victim,"你迷迷糊糊中觉得"+me->name()+"是你的主人，须得跟随他！\n");

	victim->set_leader(me);	
	return 1;
}

int do_fushen(string arg)
{
        object victim, me = this_player();

	if (!wizardp(me)) return notify_fail("你无权使用此功能！\n");

        if (!arg) return notify_fail("你要附身于谁身上？\n");

        victim = present(arg, environment(me));
        if (!victim) return notify_fail("这里并无此替身！\n");
	if (!living(victim)) return notify_fail("此替身并非生物！\n");
	
//	if(geteuid(victim) != geteuid(me)) return notify_fail("身份不符，无法进行附身！\n");
	if(victim->query_temp("body_ob")) return notify_fail( victim->name() + "已经被人附身过了。\n");
	if(victim->query_temp("link_ob")) return notify_fail( victim->name() + "已经被人附身过了。\n");

        message_vision(HIR "$N元神出窍，化成一道光芒钻进$n体内。\n" NOR, me, victim);
        LOGIN_D->enter_world(me, victim, 1);

        return 1;
}
