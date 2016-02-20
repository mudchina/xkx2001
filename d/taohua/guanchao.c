//Cracked by Roath
//kane
//Modified by kane, 2/11/97
//Modified by ryu, 11/11/97

#include <ansi.h>
#include "localtime.h"
inherit ROOM;
#include "/kungfu/skill/force_list.h"
int exercising(object me);
int halt_exercise(object me);
int respirating(object me);
int halt_respirate(object me);
string long_desc();

string day_event(){ return NATURE_D->outdoor_room_event();}

void setup()
{}
void create()
{
	set("short", "观潮台");
      set("long", (: long_desc :));

	 set("exits", ([
                "southdown" : __DIR__"beach",
        ]));
	set("cost", 5);
	set("outdoors", "taohua");
	set("guanchao", 1);
	setup();
}
void init()
{
        add_action("do_dazuo", "dazuo");
	add_action("do_dazuo", "exercise");
	add_action("do_tuna", "tuna");
	add_action("do_tuna", "respirate");
}

string long_desc()
{
        string desc;

        desc  = "这是一座颇有点破旧的高台，前面是一望无际的大海。\n";

	if (day_event() == "event_dawn" || day_event() == "event_evening"){
               desc += HIG "远远望去大海浩淼，万里无波，海天一线处一道白线滚滚而来，渐近渐快，稍后\n" NOR;
               desc += HIG "洪涛汹涌，白浪连山，倾刻之间已至台下，惊涛骇浪狠狠打在台基上。你顿时感觉\n" NOR;
	       desc += HIG "立足不稳，摇摇欲坠，不禁脸上变色，为这天地之威所深深撼动。\n" NOR;

	     }
        
        else {
                desc += HIC "你登高远望，但见长天一碧，万里无波，当真是“海阔凭鱼跃，天高\n" NOR;
		    desc += HIC "任鸟飞”。当此景象，你深吸一口气，只觉胸腹之间清气充盈，轻飘\n" NOR;
                desc += HIC "飘的似乎就要乘风而去。\n" NOR;

	  }

        return desc;
}

int do_dazuo(string arg)
{
	int exercise_cost;
	object me = this_player();

	seteuid(getuid());
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");

	if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");

	if (day_event() == "event_dawn" || day_event() == "event_evening"
	|| day_event() == "event_midnight" ){
	write(HIG"你闭目行功，于惊涛骇浪声中吸纳怒潮那无穷无尽的气势\n"NOR);

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	me->set_temp("force_gain", exercise_cost/30);
	message_vision("$N盘膝坐下，开始修炼内力。\n", me);
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
	}
	else {return 0;}
}

int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 2 + (int)me->query_skill("force") / 10;
	int i, clan, extra;
	string force;

        if (exercise_cost < 1)
                return 0;
	force = (string)me->query_skill_mapped("force");

	for (i = 0; i < sizeof(force_list); i++)
		if (force == force_list[i]["force"])
			clan = i;	
	extra = 1;
	
	if (force_list[clan]["zheng_xie"] == 0) extra = extra * 2;
		else extra = extra * 1.5;

	neili_gain = neili_gain*extra;
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);

	//me->add("qi", -neili_gain);
	me->receive_damage("qi", neili_gain, "打坐走火入魔死了");

	if (exercise_cost > 0)
		return 1;

	me->set_temp("pending/exercise", 0);
	message_vision("$N运功完毕，深深吸了口气，站了起来。\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_skill("force") * me->query("con") * 2 / 3) {
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write("你的内力增加了！！\n");
			return 0;
		}
	}
}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}


int do_tuna(string arg)
{
	int respirate_cost;
	object where;
	object me = this_player();	

	seteuid(getuid());
	
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能吐纳，会走火入魔。\n");

	if (me->query_temp("cursed", 1))
                return notify_fail("什么？\n");

	if( me->query("rided"))
                return notify_fail("骑在马上吐纳，会走火入魔。\n");

	if( !arg || !sscanf(arg, "%d", respirate_cost))
		return notify_fail("你要花多少精修行？\n");
	if (respirate_cost < 10)
		return notify_fail("你的修为还没有达到那个境界！\n");

	if( (int)me->query("jing") < respirate_cost )
		return notify_fail("你现在精不足，无法修行精力！\n");

	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");

	if (day_event() == "event_dawn" || day_event() == "event_evening"){
	write(HIG"你闭目行功，于惊涛骇浪声中吸纳怒潮那无穷无尽的气势\n"NOR);

	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	message_vision("$N盘膝坐下，开始吐纳炼精。\n", me);
	me->start_busy((: respirating :), (:halt_respirate:));
	return 1;
	}
	else {return 0;}
}

int respirating(object me)
{
	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain = 1 + (int)me->query_skill("force",1) / 10;
	int i, clan, extra;
	string force;
	
	if (respirate_cost < 1)
		return 0;

        force = (string)me->query_skill_mapped("force");

        for (i = 0; i < sizeof(force_list); i++)
                if (force == force_list[i]["force"])
                        clan = i;
        extra = 1;

        if (force_list[clan]["zheng_xie"] == 0) extra = extra * 2;
                else extra = extra * 1.5;
        
	jingli_gain = jingli_gain*extra;
	me->add("jingli", jingli_gain);
	me->set_temp("respirate_cost", respirate_cost -= jingli_gain);

	//me->add("jing", -jingli_gain);
	me->receive_damage("jing", jingli_gain, "吐纳走火入魔死了");

	if (respirate_cost > 0)
		return 1;

	me->set_temp("pending/respirate", 0);
	message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
	if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
                if ((int)me->query("max_jingli") > (int)me->query_skill("force") * me->query("con") / 2
                || (int)me->query("eff_jingli") > (int)me->query_skill("force") * me->query("con") / 2) {
			write("你的精力修为似乎已经达到了瓶颈。\n");
			me->set("jingli", (int)me->query("max_jingli"));
                        return 0;
                }
                else {
                        me->add("eff_jingli", 1);
                        me->add("max_jingli", 1);
                        me->set("jingli", (int)me->query("max_jingli"));
                        write("你的精力增加了！！\n");
                        return 0;
                }
        }
}

int halt_respirate(object me)
{
        if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
                me->set("jingli", (int)me->query("max_jingli") * 2);
        me->set_temp("pending/respirate", 0);
        return 1;
}

