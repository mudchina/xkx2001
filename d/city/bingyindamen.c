//Cracked by Roath
// Room: /city/bingyindamen.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "兵营大门");
	set("long", @LONG
你正站在兵营的门口，面对着一排简陋的营房，可以看到穿着制服的官兵正
在操练，不时地传来呐喊声。老百姓是不允许在此观看的，你最好赶快走开。
LONG
	);

	set("exits", ([
		"north" : __DIR__"bingyin",
		"south" : __DIR__"xidajie2",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 4,
	]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "north")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

