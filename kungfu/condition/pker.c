//Cracked by Roath
// pker.c

int update_condition(object me, int duration)
{
	if (duration < 1) {
		return 0;
	}
	me->apply_condition("pker", duration - 1);
	return 1;
}
