//Cracked by Roath
// killer.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "西夏官府不再通缉你了！\n");
		return 0;
	}
	me->apply_condition("xakiller", duration - 1);
	return 1;
}
