//Cracked by Roath
// Room: /d/shaolin/guangchang4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "精进场");
	set("long", @LONG
这是后殿前的精进场，广场青砖铺地，因为多年的踩踏而凹
凸不平。前后各是两堵高墙，把整个广场夹在中间，形成一个窄
窄的长方形。西边开了扇小门，一股香气袅袅地飘了过来。北面
是个大门，几位僧人在此把守。
LONG
	);

	set("exits", ([
		"south" : __DIR__"guangchang3",
		"northup" : __DIR__"houdian",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		CLASS_D("shaolin") + "/hui-kong" : 1,
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "少林派"
	&& !me->query("luohan_winner")
	&& dir == "northup" 
	&& objectp(present("huikong zunzhe", environment(me))))
			return notify_fail("慧空喝道：你不是少林弟子，不得进入后殿。\n");

	return ::valid_leave(me, dir);
}

