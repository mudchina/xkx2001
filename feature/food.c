//Cracked by Roath
// food.c

#include <dbase.h>
#include <name.h>

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

int feed_ob(object me)
{
	string str;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !living(me) ) return 0;

	if( stringp(query("food_race")) )
		return notify_fail( "这可不是给人吃的东西！\n");

	if( !query("food_remaining") )
		return notify_fail( name() + "已经没什么好吃的了。\n");
	if( (int)me->query("food") >= (int)me->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

	me->add("food", query("food_supply"));

	me->add("jingli", query("food_supply")/5);
	if( me->query("jingli") > me->query("max_jingli")) 
	me->set("jingli", me->query("max_jingli"));

	if( me->is_fighting() ) me->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") ) {
		if( !stringp(str = this_object()->query("eat_all")) )
		str = "$N将剩下的$n吃得乾乾净净。\n";
		message_vision(str, this_player(),this_object());
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else  {
		if( !stringp(str = this_object()->query("eat_msg")) )
		str = "$N拿起$n咬了几口。\n";
		message_vision(str, this_player(),this_object());
	}
	me->start_busy(1);
	return 1;
}
