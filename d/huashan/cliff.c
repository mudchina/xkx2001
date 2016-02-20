//Cracked by Roath
// cliff.c 绝壁

inherit ROOM;

void create()
{
        set("short", "绝壁");
	set("long", @LONG
除了身前的一面峭壁外(wall)，周围都是白茫茫的云雾，什么也看不
到。
LONG
        );

	set("item_desc",([
		"wall" : "一面峭壁。\n",
	]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
	set("invalid_startroom", 1);

	set("cost", 7);
        setup();
//      replace_program(ROOM);
}

void init()
{
	if ( this_player()->query_temp("exit") ||  this_player()->query("jinshe") )
		set("exits/enter", __DIR__"yongdao3");

	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_break", "break"); 
	add_action("do_break", "dig");
	add_action("do_break", "wa");
	add_action("do_sleep", "sleep");
//	add_action("do_quit", "quit");
}
/*
int do_quit()
{
	object me = this_player();

	me->move("/d/huashan/fengding");
	me->command("quit");
	return 1;
}
*/
int do_sleep()
{
	write("你身在半空中如何睡觉？\n");
	return 1;
}

int do_climb(string arg)
{
        object me = this_player();

        if ( arg && arg != "up" )
                return notify_fail("什么？\n");

        if ( !me->query_temp("tied") )
                return notify_fail("没东西支撑你怎么爬呀？\n");

        message_vision("$N拉着绳子开始往崖顶上爬去。\n", me);
        message("vision", me->name()+"一会儿便消失在云气里了。\n", environment(me), ({me}) );

	me->move(__DIR__"fengding");
	message("vision", me->name()+"气喘嘘嘘地由绝壁下爬了上来。\n", environment(me), ({me}) );

	me->receive_damage("qi", 150, "体力透支过度死了");

	return 1;
}

int do_break(string arg)
{
	object weapon, me = this_player();

        if ( !arg || arg != "wall" ) return 0;

	if ( objectp(weapon=me->query_temp("weapon")) && weapon->name() != "铁锹" ) {
		message_vision("$N拿起"+weapon->name()+"在峭壁上挖了几下。\n", me);
		message_vision("只听得“啪”地一声，"+weapon->name()+"断为几截！\n", me);
		destruct(weapon);
		return 1;
	}

	if ( !weapon ) {
		message_vision("$N用手在峭壁上挖了几下，突然一声痛叫，似乎被什么东西刺着，搞得手上鲜血淋漓！\n", me);
		me->receive_wound("qi", 20, "受伤过重死了");
		return 1;
        }

	if ( random(10) == 1 ) {
		message_vision("$N用铁锹挖掘了一阵，突然觉得壁上一阵松动，忙加紧掘破封泥，露出一个小洞穴。\n", me);
		set("exits/enter", __DIR__"yongdao3");
		me->set_temp("exit", 1);
	}
	else message_vision("$N用铁锹挖掘了一阵，什么也没发现。\n", me);

	me->receive_damage("qi", 20, "体力透支过度，失手跌下绝壁死了");
	
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !me->query("jinshe") && me->query("age") > 22 && me->query_str() > 20 ) 
		return notify_fail("你身体太大了，挤不进洞里去！\n");

	return ::valid_leave(me, dir);
}
