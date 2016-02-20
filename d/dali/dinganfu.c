//Cracked by Roath
// Room: /d/dali/dinganfu.c

inherit ROOM;

void create()
{
	set("short", "定安府");
	set("long", @LONG
这是大理的司法机关，接管的主要是一些民族之间的纠纷和误解，因此府里
有汉族，白族，摆夷族，哈尼族，壮族官员各一名，以示公正。另外，府里还雇
了通译，以便讯问。近年来事态安和，定安府门前清清淡淡，衙役们靠着墙聊着
天。南边是大理低级官员的住所。
LONG);
	set("objects", ([
		"kungfu/class/dali/fusigui" : 1,
		__DIR__"npc/weishi5" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dinganfu1",
		"south" : __DIR__"dinganfu2",
		"west" : __DIR__"dalicheng1",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	if (me->query("family/family_name")!="大理段家"
		&& !me->query("dali/employee")
		&& dir == "south"
		&& living(ob=present("fu sigui", find_object(__DIR__"dinganfu.c"))))
		return notify_fail("守卫喝道：闲杂人等，不得乱闯。\n");

	return ::valid_leave(me, dir);
}
