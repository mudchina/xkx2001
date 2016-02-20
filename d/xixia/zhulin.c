//Cracked by Roath
// Room: /d/xixia/zhulin.c

inherit ROOM;

void create()
{
	set("short", "紫竹林");
	set("long", @LONG
这是一片紫竹林，看上去不大，但你一走进来却仿佛迷了路，四面
都密密的紫竹，真奇怪在北方居然有这么紫的竹子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hut",
  "east" : __DIR__"garden",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
