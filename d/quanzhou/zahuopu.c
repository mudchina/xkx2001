//Cracked by Roath
// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这里是一家专卖女人用的东西的小铺子。
LONG
	);

	set("exits", ([
                "south" : __DIR__"citong_w1",
	]));

	set("objects", ([
                 __DIR__"npc/chen" : 1,
    	]) );

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

