//Cracked by Roath
// drop.c

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if(!arg) return notify_fail("你要丢下什么东西？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开丢弃。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			me->save();
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("好了，你能扔的全扔了。\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;
	string str, martial;

	if( stringp(martial = me->query_condition("perform"))
	  )
		return notify_fail("你正忙着呢。\n");

	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
	
	if (obj->move(environment(me))) {
		if( obj->is_character() )
			message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
		else {
			message_vision( sprintf("$N丢下%s%s$n。\n",	
				obj->query_amount() ? chinese_number(obj->query_amount()) : "一",
				obj->query_amount() ? obj->query("base_unit") : obj->query("unit")),
				me, obj );
			if( me->query_skill_mapped("dodge")=="dugu-jiujian" 
			&& (string)obj->query("skill_type")=="sword" )
				me->map_skill("dodge");
			if( !obj->query("value") && !obj->value() ) {
				write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : drop <物品名称>
 
这个指令可以让你丢下你所携带的物品.
 
HELP
    );
    return 1;
}
 
