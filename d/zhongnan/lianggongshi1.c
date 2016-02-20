// By xuanyuan
// road: /zhongnan/lianggongshi1.c

inherit ROOM;
#include <ansi.h>
#include "/kungfu/skill/force_list.h"
int exercising(object me);
int halt_exercise(object me);
int respirating(object me);
int halt_respirate(object me);
int do_climb(object me);
int do_xia(object me);
int do_study(string);

void create()
{
        set("short","练功室");
        set("long",@LONG
    这石室形状甚是奇特，北窄南宽，成为梯形，东边半圆，西边却作  
三角形状,室顶石壁(shibi)上刻满了诸般花纹符号，均是以利器刻成，
或深或浅，殊无规则。石室中央放了一张白色石床(chuang)。
LONG);

        set("item_desc",(["chuang" : "
这石床是用来自极北苦寒之地的上古寒玉制成，是修习上乘内功的良
助。\n",
                        "shibi" : "
这石室原是一武林高人练武的地方。据孙婆婆说，当年这高人在此钻 
研武学，前窄练掌，後宽使拳，东圆研剑，西角发镖，而璧上所刻的尽是
这高人所悟的心得。
\n"]));

        set("exits",([ "north" : __DIR__"zoudao3",
                        "east" : __DIR__"lianggongshi2",
                       ]));
        set("cost",1);

        setup();
}

int valid_leave(object me, string dir)
{
	me=this_player();
//	if (dir == "north" && me->query_temp("hanyuchuang"))
	if (me->query_temp("hanyuchuang"))
	 return notify_fail("你还没下地(xiachuang)呢，就想乱跑。\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_dazuo", "dazuo");
	add_action("do_dazuo", "exercise");
	add_action("do_tuna", "tuna");
	add_action("do_tuna", "respirate");
	add_action("do_climb", "climb");
	add_action("do_climb", "sit");
	add_action("do_xia", "xiachuang");
	add_action("do_study", "study");
	add_action("do_study", "du");
	add_action("do_study", "lingwu");
}

int do_climb(object me)
{      
        me=this_player();
	if(!me->query_skill("yunu-xinjing", 1)||(int)me->query_skill("yunu-xinjing", 1) < 60)
	   {
		write("你的玉女心经修为不够，抵御不了奇寒！\n");                   
		message_vision("$N爬上了寒玉床，结果给冻得惨惨的，赶紧爬了下来。\n",me);
		return 1; 
 	  }	
	message_vision("$N爬上了寒玉床,现在打坐可以练功了。\n",me);
	me->set_temp("hanyuchuang",1);
	return 1;	
}

int do_xia(object me)
{
	me=this_player();
	if (!me->query_temp("hanyuchuang"))
	 return notify_fail("你又没爬上寒玉床，下到哪去呀？。\n");
	me->delete_temp("hanyuchuang");
	message_vision("$N练完功，精神焕发地跳下地来。\n",me);
	return 1;
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

		 if ( me->query_temp("hanyuchuang"))
		 {
		  write(HIW"你坐下来借助寒玉床的奇寒定神行功。\n"NOR);

		  me->set_temp("pending/exercise", 1);
		  me->set_temp("exercise_cost", exercise_cost);
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
					 if ((int)me->query("max_neili") > (int)me->query_skill("force") * 10) {
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


		 if ( me->query_temp("hanyuchuang"))
       {
		  write(HIW"你坐下来借助寒玉床的奇寒定神行功。\n"NOR);

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
                if ((int)me->query("max_jingli") > (int)me->query_skill("force") * 8
                 || (int)me->query("eff_jingli") > (int)me->query_skill("force") * 8) {
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


int do_study(string arg)
{
	object me;
        mapping fam;

	me = this_player();

	if ( !arg || arg != "shibi" )
		return notify_fail("什么？\n");

        if (!mapp(fam = me->query("family")) || (string)me->query("family/family_name") != "古墓派") 
		return notify_fail("你不是古墓派子弟，领悟不到石壁中所刻武功的奥妙。\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if ( (int)me->query_skill("yunu-jue", 1) < 50)
		return notify_fail("你的玉女二十四诀火候不够，无法静下心来学习石壁上的武功。\n");

	if (me->query("jing") < 60)
		return notify_fail("你的精力不够！\n");

	me->receive_damage("jing", random(60), "心力绞瘁死了");

	message_vision("$N正专心研读石壁上的武功心得。\n", me);

	switch( random(3) ) 
	{
	    case 0:
		if ( (int)me->query_skill("yunu-xinjing", 1) < 20)
		{
			me->improve_skill("yunu-xinjing", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对玉女心经有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("tianluo-diwang", 1) < 100)
		{
			me->improve_skill("tianluo-diwang", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对天罗地网势有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("strike", 1) < 100)
		{
			me->improve_skill("strike", me->query("int"));
			write("你对着石壁琢磨了一回儿，似乎对掌法有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 3:
		if ( (int)me->query_skill("cuff", 1) < 100)
		{
			me->improve_skill("cuff", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对拳法有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 4:
		if ( (int)me->query_skill("parry", 1) < 100)
		{
			me->improve_skill("parry", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对招架有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	}

	if ( !me->query_temp("shibi1_learned") )
	{
		write("你对着石壁琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}
