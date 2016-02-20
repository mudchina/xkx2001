//Cracked by Roath
// yin.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object dest;

	if(!arg) return notify_fail("你要让谁喝水？\n");

	if( !objectp(dest = present(arg, environment(me))) )
		return notify_fail("这里没有这样东西。\n");

	if( !dest->is_character() )
		return notify_fail("什么？\n");

	if( dest->query("race") == "人类" )
		return notify_fail("你不能喂人喝水！\n");

	if( dest->query_lord() != me )
		return notify_fail("你不是它的主人！\n");

	if( !environment(me)->query("resource/water") )
		return notify_fail("这里没有水源！\n");

	if( dest->query("water") >= dest->max_water_capacity() )
		return notify_fail("它已经喝得太足了，再也喝不下了。\n");

	dest->add("water", 20);
	dest->add("jingli", 20);
	if( dest->query("jingli") > dest->query("max_jingli")) 
	dest->set("jingli", dest->query("max_jingli"));

	message_vision("$N牵过" + dest->name() + "来喂著它喝了几口水。\n", me);

	if( dest->is_fighting() ) dest->start_busy(2);

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : drink|yin <某动物>
 
这个指令可以让你喂某动物喝水。
 
HELP
    );
    return 1;
}
