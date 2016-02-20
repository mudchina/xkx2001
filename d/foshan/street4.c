//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山镇街");
        set("long", @LONG
佛山镇街东西相连。东边是镇东门，南面一堵高墙，墙后便是
凤天南开的“英雄典当”。
LONG
        );
        set("exits", ([
		"south" : __DIR__"yxpawn",
		"east" : __DIR__"egate",
		"west" : __DIR__"street3",
	]));

	set("objects", ([
		"/d/city/npc/jiading" : 2,
		"/d/city/npc/wolfdog" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
