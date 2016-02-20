//Cracked by Roath
// remove.c
// xQin 2/00

#include <ansi.h>

int exert(object me)
{
	mapping lj_exert = me->query_temp("lj_exert");

	switch( lj_exert["name"] )
	{
		case "tiandi" :
			if( lj_exert["eff_jing"] ) me->add("eff_jing", -lj_exert["eff_jing"]);
			if( lj_exert["eff_qi"] ) me->add("eff_qi", -lj_exert["eff_qi"]);
			tell_object(me, HIG"你将所聚天地之精气散回天地之间。\n"NOR);
			break;
		case "longhe" :
			if( lj_exert["jing2jingli"] )
			{
				me->receive_curing("jing", lj_exert["jing2jingli"]);
				me->add("jingli", -lj_exert["jing2jingli"]);
			}
			if( lj_exert["neili2jingli"] )
			{
				me->add("neili", lj_exert["neili2jingli"]);
				me->add("jingli", -lj_exert["neili2jingli"]);
			}
			if( lj_exert["qi2jingli"] )
			{
				me->receive_curing("qi", lj_exert["qi2jingli"]);
				me->add("jingli", -lj_exert["qi2jingli"]);
			}
			if( lj_exert["jing2neili"] )
			{
				me->receive_curing("jing", lj_exert["jing2neili"]);
				me->add("neili", -lj_exert["jing2neili"]);
			}
			if( lj_exert["jingli2neili"] )
			{
				me->add("jingli", lj_exert["neili2jingli"]);
				me->add("neili", -lj_exert["neili2jingli"]);
			}
			if( lj_exert["qi2neili"] )
			{
				me->receive_curing("qi", lj_exert["qi2neili"]);
				me->add("neili", -lj_exert["qi2neili"]);
			}
			tell_object(me, HIG"你行龙鹤二庄已久，又恢复了原有精气。\n"NOR);
			break;
	}
	me->delete_temp("lj_exert");

	return 1;
}