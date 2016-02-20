//Cracked by Roath
// yideng quest room 1
// acep , mantian , mantian

inherit ROOM;

void create()
{
	set("short", "无名山");
	set("long", @LONG
此处正是山岭的顶部，山峰穿云插天，山石滑溜，空山寂寂，只见一道白龙
似的大瀑布(waterfall) 从对面双峰之间奔腾而下，声势甚是惊人，水声在山谷
间激荡回响，轰轰汹汹，从岭上望下去，瀑布旁有一间草屋。
LONG);
	set("item_desc", ([
		"waterfall" : "你目光随着瀑布向下流动，突然眼前金光闪烁，水底有物游动，定睛望去，\n只见一对金娃娃钻在山石之中，两条尾巴却在外乱晃。",
		]));
	set("objects", ([ 
		"/kungfu/class/dali/fisher" : 1,
        ]));
	set("exits", ([
		"out" : __DIR__"maze1",
		]));
	set("cost", 1);
	set("outdoor","dali");
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}
void init()
{
	add_action("do_dive", "dive");
}

int do_dive(string arg)
{
	object me = this_player();

	if ( !arg || arg != "waterfall" ) return notify_fail( "什么？\n");
	message_vision("$N纵身跳入了瀑布中。\n", me);
	if ( me->query_skill("dodge",1) <= 50 )
	{
		message_vision("$N双足一入水，瀑布的急流便冲得他左摇右晃，难以站稳。一会儿便发出\n", me);
		message_vision("一声惨嚎，被山洪冲得无影无踪了。\n", me);
		me->receive_wound("qi", me->query("max_qi")+100,"被山洪淹死了");
	}
	if ( me->query_skill("dodge",1) > 50 && me->query_skill("dodge",1) < 120 )
	{
		message_vision("$N双足一入水，瀑布的急流便冲得左摇右晃，难以站稳。只好勉力提气\n", me);
		message_vision("，回身跳向岸边。\n", me);
		me->unconcious();
	}
	if ( me->query_skill("dodge",1) >= 120 )
	{
		me->move(__DIR__"yideng2");
		message("vision", me->name()+"“噗咚”的一声跳了下来。\n",environment(me), ({me}) );
	}
	return 1;
}
