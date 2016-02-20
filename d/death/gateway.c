//Cracked by Roath
// Room: /d/death/gateway.c

inherit ROOM;

void create()
{
	set("short", "酆都城门");
	set("long", @LONG
你现在来到一座黑色城楼之前，城楼上刻著三个大字：酆都城。往
南不远处有一座桥，桥上鬼影幢幢，但是却听不到半点声音，往北走进
城楼只见一片黑漆漆的，只有少许暗红色的火光若隐若现地闪烁著。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : "/d/death/road1",
		"south" : "/d/death/gate",
	]));
	set("objects", ([
		__DIR__"npc/bgargoyle": 1
	]) );

	set("no_fight", 1);
	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south") {
		return notify_fail("一个空洞的声音在你耳边响起....\n"+
			       "没有回头路了!\n");
	}
	else return 1;
}

void init()
{
	add_action("do_suicide","suicide");
}

int do_suicide(string arg)
{
        object me = this_player();
        tell_object(me, "你还死着呢。\n");
        return 1;
}

