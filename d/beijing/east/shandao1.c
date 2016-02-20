//Cracked by Roath
// Room: /d/beijing/east/shandao1.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你正走在一条平缓的石板路上，路旁古树参天，花草
丛中蝴蝶纷飞，不时还可以看到几只小兽从旁边跑过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"guoyuan",
  "southup" : __DIR__"wanchunting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
