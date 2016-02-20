//Cracked by Roath
// yideng quest room 2

inherit ROOM;

int do_jump(string);
int do_lift(string);

void create()
{
	set("short", "瀑布下");
	set("long", @LONG
这里是瀑布水底，水流急冲直下，你双足使劲，以「千斤坠」的功夫牢牢站
稳，恰似中流砥柱，崎立不动。你发现金娃娃已经藏到一块巨石(stone) 下面去
了。
LONG);

	set("item_desc",([
        "stone" : "一块巨大的岩石。\n",
        ]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_lift", "lift");
}
int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg != "bank" ) return notify_fail( "什么？\n");

	message_vision("$N纵身往岸上跳去。\n", me);
	me->move(__DIR__"yideng1");
	return 1;
}
int do_lift(string arg)
{   
	object me = this_player();

	if ( !arg || arg != "stone" ) return notify_fail( "什么？\n");

	message_vision("$N伸手向大石下抬去。\n", me);
	if ( me->query_str() < 26 )
	{
		message_vision("$N伸手掀了几掀，但大石纹风不动。\n", me);
		me->receive_damage("qi", 100, "体力透支过度死了");
	}
	else
	{
		message_vision("$N运足气力推去，那巨石受水力与掌力夹击，摇晃了几下，擦过$N\n身旁，蓬蓬隆隆，滚落下面深渊中去了，响声在山谷间激荡发出回音，\n轰轰然良久不绝。\n... ...\n\n", me);
		me->move(__DIR__"yideng3");
	}
	return 1;
} 
