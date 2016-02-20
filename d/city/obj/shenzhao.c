//Cracked by Roath
// Jay 2/5/97
#include "ansi.h"

inherit ITEM;
inherit F_UNIQUE;
int exercising(object me);
int halt_exercise(object me);

void setup()
{}

void init()
{
        add_action("do_dazuo", "lianneili");
}

void create()
{
        set_name(MAG "神照经" NOR, ({ "shenzhao jing", "jing", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "凭此秘籍的指导可以加快练内力(lianneili)的速度。\n");
                set("value", 5000);
                set("material", "paper");
		set("no_steal", 1);
        }
        ::create();
}

int do_dazuo(string arg)
{
        object me = this_player();
        int exercise_cost;
        object where;

        seteuid(getuid());
        where = environment(me);

        if (!present("shenzhao jing", me))
                return 0;

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

	if (where->query("no_fight"))
		return notify_fail("你不能屏除杂念，只感体内邪气乱窜，无法静心练功。\n");

        if (where->query("sleep_room"))
                return notify_fail("在睡房里不能打坐，这会影响他人。\n");

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

        write("你按着神照经上的气诀坐下来运气用功，一股内息开始在体内流动。\n");

        me->set_temp("pending/exercise", 1);
        me->set_temp("exercise_cost", exercise_cost);
        message_vision("$N盘膝坐下，开始修炼内力。\n", me);
        me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
        int exercise_cost = (int)me->query_temp("exercise_cost");
        int neili_gain = 2 + (int)me->query_skill("force") / 5;
        if (exercise_cost < 1)
                return 0;
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

