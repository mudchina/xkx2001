//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "泥潭");
	set("long", @LONG
这里是一个片大泥潭，向前望去，眼前一团茫茫白雾裹着一方一圆两间茅屋，
隐隐约约有灯光从方屋中射出。此茅屋无门无户，连窗户都没有一个，不知道土
墙(wall)那边有些什么。
LONG);
	set("item_desc",([
		"wall" : "一堵看起来不是很高的土墙。\n",
		]));
	set("exits", ([
		"north" : "/d/dali/maze1",
		]));
	set("cost", 4);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali" );
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

	if ( !arg || arg != "wall") return notify_fail( "什么？\n");
	message_vision("$N纵身往土墙上跳去。\n", me);
	if ( me->query_skill("dodge",1) <= 50)
	{
		message_vision("$N通的一声摔进了泥潭，满身臭气。\n", me);
		me->receive_wound("qi", 100);
	}
	if ( me->query_skill("dodge",1) > 50 )
	{
		me->move("/d/dali/yingroom2");
		message("vision", me->name() + "纵身由墙上跳了过来。\n",environment(me), ({me}) );
	}
	return 1;
} 
