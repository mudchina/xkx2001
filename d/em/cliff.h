//Cracked by Roath
// /d/emei/down_pool.h
// xbc 1997/02/05

#include <ansi.h>

int to_cliff(object me)
{
        tell_room(environment(me),"\n崖下传来一声大叫：『啊¨¨¨』\n", me);
        tell_object(me,RED"\n下面什么都没有，啊¨¨¨，你吓得昏了过去。\n\n"NOR);
        me->move(__DIR__"cliff");
	me->receive_wound("qi", me->query("max_qi")+100, "掉到舍身崖摔得粉身碎骨了");
	call_out("destroy_corpse", 1);
        return 1;
}

int to_branch1(object me)
{
        tell_object(me,RED"\n下面什么都没有，啊¨¨¨，你吓得昏了过去。\n\n"NOR);
        me->move(__DIR__"clifftree1");
        tell_room(environment(me),(string)me->query("name")+"从悬崖上摔了下来。\n", me);
	me->add("quest_exp", 2+random(1));
        me->unconcious();
	call_out("wakeup", random(3), me);
        return 1;
}

int to_branch2(object me)
{
        tell_object(me,RED"\n下面什么都没有，啊¨¨¨，你吓得昏了过去。\n\n"NOR);
        me->move(__DIR__"clifftree2");
        tell_room(environment(me),"$N从悬崖上摔了下来。\n", me);
	me->add("quest_exp", 5+random(5));	
        me->unconcious();
	call_out("wakeup", 2+random(3), me);
        return 1;
}

int to_pool(object me)
{
        tell_object(me,RED"\n啊¨¨¨，你吓得昏了过去。\n\n"NOR);
        me->move(__DIR__"cliffpool");
        tell_room(environment(me),(string)me->query("name")+"从悬崖上摔了下来，掉到水潭里。\n", me);
	me->add("quest_exp", 2);
        me->unconcious();
	call_out("wakeup", 2+random(2), me);
        return 1;
}

int wakeup(object me)
{
	me->revive();
	return 1;
}
