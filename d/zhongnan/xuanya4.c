//Cracked by Kafei
// road: /zhongnan/xuanya4.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
#include "localtime.h"
#include "/kungfu/skill/force_list.h"
int exercising(object me);
int halt_exercise(object me);
int respirating(object me);
int halt_respirate(object me);

int do_climb(string arg);

void create()
{
		  set("short",HIW"崖顶"NOR);

		  set("long",@LONG
崖顶是个巨大的平台，积满了皑皑白雪。正中立着一块石碑，上面似乎刻着一首
词(ci)。站在崖顶往四周望去，但见平烟茫茫，一望无尽的沙漠消失在天边，说不尽
的潇潇之意，几只巨大的黑雕在空中来回盘旋。
LONG);

		  set("item_desc",(["ci" : "


		沁园春。侠客行

			 清枫

	侠客终身，荒废光阴，但求安心。
        望古墓内外，美女稀少；星宿上下，男人寥寥。
        白驼怪蛇，牛鼻老道，欲与贼秃试比高。
        遁大理，看峨嵋九爪，华山剑豪。

        经验如此难找，
        引无数PK竞拔刀。
        惜东邪西毒，萧筝缠绕；南帝北丐，不减风骚。
        一代天骄，重阳真人，不识儿女之情调。
        轩辕云，涉天上人间，任我逍遥。


\n",]));

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_dazuo", "dazuo");
	add_action("do_dazuo", "exercise");
	add_action("do_tuna", "tuna");
	add_action("do_tuna", "respirate");
}


int do_climb(string arg)
{
	object me = this_player();
	int gain,cost;

	if(me->is_busy())
		return notify_fail("你还在忙着呢。\n");

	if(arg != "down" )
		return notify_fail("那个方向没法爬。\n");

	cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
	if ( cost<10 )cost = 10;
	cost *= 2;

	if( me->query("jingli") < 30)
		return notify_fail("你累的实在爬不动了。\n");

	me->add("jingli",-cost);
	gain = me->query("con",1)*2;
	gain *= 2;

	if ( me->query_skill("dodge") > 300 ) gain /= 2;

	me->improve_skill( "dodge",random( gain ) );
	if( me->query_skill( "jinyangong",1) > 0 )
		me->improve_skill( "jinyangong",random( gain ) );


	message_vision( HIY"\n$N在悬崖上攀藤附葛，小心谨慎的爬下去。\n"NOR, me);
	me->move("/d/zhongnan/xuanya3");
	message_vision( HIY"\n$N爬了下来。\n"NOR, me);
	return 1;
}

string day_event(){ return NATURE_D->outdoor_room_event();}

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

		 if (day_event() == "event_night" || day_event() == "event_midnight")
		 {
		  write(HIG"在万籁俱静之中，你坐下来定神行功。\n"NOR);

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


		 if (day_event() == "event_night" || day_event() == "event_midnight")
       {
		  write(HIG"在万籁俱静之中，你坐下来定神行功。\n"NOR);

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


