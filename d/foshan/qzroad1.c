//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间道");
        set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。西面是岭南重镇佛山，
东边通向福建泉州。
LONG
        );
        set("exits", ([
		"west" : __DIR__"egate",
		"east" : __DIR__"qzroad2",
	]));

	set("objects", ([
		__DIR__"npc/chaotang" : 1,
		__DIR__"npc/zhangkang" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
