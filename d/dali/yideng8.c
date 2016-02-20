//Cracked by Roath
// yideng quest room 8

inherit ROOM;

void create()
{
        set("short", "山梁");
        set("long", @LONG
山路就到了尽头，前面是条宽约尺许的石梁，横架在两座山峰之间，云雾笼
罩，望不见尽处。石梁凹凸不平，又加终年在云雾之中，石上溜滑异常。前面不
远处的石梁突然断开了一段空缺(gap)。
LONG);
	set("item_desc",([
		"gap" : "一段一丈来长的空缺。迎面山风凛烈，脚下白云飘飘，如果摔下去 ... ...\n",
		]));
	set("exits", ([
		"down":__DIR__"yideng7",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoor","dali");
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();
	if ( !arg || arg != "gap" ) return notify_fail( "什么？\n");

	message_vision("$N纵身往空缺对面跳去。\n", me);
	if ( me->query_skill("dodge",1) <= 80)
	{
		message_vision("$N空中感到一阵浊气上涌，差了三寸没能跳到对面，发出一阵\n", me);
		message_vision("惨嚎，从空中直坠了下去。\n", me);
		me->receive_wound("qi", me->query("max_qi")+100, "摔成了肉酱");
	}
	if ( me->query_skill("dodge",1) > 80 )
	{
		me->move(__DIR__"yideng9");
		message("vision", me->name() + "纵身由对面跳了过来。\n",environment(me), ({me}) );
	}
	return 1;
} 
