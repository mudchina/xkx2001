//Cracked by Roath
// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，有的
独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视着四
周。西边有一个门(door)，北面有一个小窗口(window)。
LONG
	);

	set("item_desc", ([
		"door" : "这是一扇极厚的铁门。\n",
	]));
	set("exits", ([
		"west" : __DIR__"jail",
		"south" : __DIR__"bingyindamen",
	]));

	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 4,
	]));

	create_door("west", "铁门", "east", DOOR_CLOSED);
	set("cost", 0);
	setup();
}
void init()
{
	add_action("do_visit", "look");
	add_action("do_pass", "pass");
}

int do_pass(string arg)
{
	object ob;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要送什么？\n");

	if (ob->query_weight() > 5000)
		return notify_fail(ob->query("name")+"太大了，不能从窗口里塞进去。\n");

	if (ob->query("id") == "huashi fen" || ob->query("id") == "tie he" || ob->is_container() || ob->query("hsf"))
		return notify_fail("这个东西放不进去。\n");

	message_vision("$N把一"+ob->query("unit")+"$n从窗口塞了进去。\n", this_player(), ob);
	ob->move("/d/city/dalao");
	message("vision", this_player()->name()+"从窗外塞进来一"
		+ob->query("unit")+ob->query("name")+"。\n",environment(ob), ob);
	return 1;
}
int do_visit(string arg)
{
	object env, me = this_player();	

	if (arg != "window") return 0;

	if(!( env = find_object("/d/city/dalao")) )
	        env = load_object("/d/city/dalao");

	message_vision("$N趴在窗台上往里望去。\n", me);
	tell_room(env, "你感到有一双眼睛在窗外打量你。\n");
	return COMMAND_DIR"std/look"->look_room(me, env);
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "west")
		return notify_fail("官兵拦住了你的去路。\n");

	return ::valid_leave(me, dir);
}

