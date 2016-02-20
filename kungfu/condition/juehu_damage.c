//Cracked by Roath
// juehu_damage.c
// xQin 8/99

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) )
		message("vision", me->name() + "痛苦地呻吟了一声。\n", environment(me), me);
	else
	{
		if( duration > 400 )
		{
			tell_object(me, HIR "你只觉得下体疼痛难忍。\n" NOR );
			message("vision", CYN + me->name() + "双手捂住小腹蹲下。\n"NOR,
				environment(me), me);
		}
		else if( duration > 200 )
		{
			tell_object(me, HIR "你只觉得下体疼痛感阵阵传来。\n" NOR );
			message("vision", CYN + me->name() + "低哼了一声，似乎受到了什麽痛楚。\n"NOR,
				environment(me), me);
		}
		else
		{
			tell_object(me, HIR "你只觉得下体疼痛仍然隐隐传来。\n" NOR );
			message("vision", CYN + me->name() + "眉头微微一皱，似乎感觉到什麽。\n"NOR,
				environment(me), me);
		}

	}


	if( !me->query_temp("wudang/juehu_damage") )
	{
		me->add_temp("apply/attack", -duration);
		me->add_temp("apply/defense", -duration);
		me->set_temp("wudang/juehu_damage", 1);
	}

	me->apply_condition("juehu_damage", duration - 1);
	me->add_temp("apply/attack", 1);
	me->add_temp("apply/defense", 1);

	if( duration < 1 )
	{
		tell_object(me, "你觉得下体的痛楚似乎减轻了。\n");
                me->delete_temp("wudang/juehu_damage");
		if( me->query("ori_gender") == "男性" )
		{
			me->delete("ori_gender");
			me->set("gender", "男性");
			tell_object(me, HIY "你重新恢复了男人的自信！\n" NOR );
		}
		return 0;
	}

	return CND_CONTINUE;
}