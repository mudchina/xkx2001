//Cracked by Roath
// sserver.c

inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
	int sz, i;
	object *enemy, target;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) {
	    for (i=0; i<4; i++) {
		target = enemy[random(sz)];
		if (environment(target) == environment(me))
		    return target;
	    }
  	} 
	return 0;
}
