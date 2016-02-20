//Cracked by Roath
// killer.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "大理官府不再通缉你了！\n");
		return 0;
	}
	me->apply_condition("dlkiller", duration - 1);
	return 1;
}
