//Cracked by Roath
// Room: /d/xiangyang/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
四周一片荒凉，原本的良田如今杂草丛生，水沟还时时可见战争所遗留
下的骸骨。冷风袭来，一股凄凉之意油然而生。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 1, "y" : 10 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "westdown" : __DIR__"migonglu",
  "northeast" : __DIR__"wangcg",
  "east" : __DIR__"huiguan",
]));

	setup();
	replace_program(ROOM);
}
