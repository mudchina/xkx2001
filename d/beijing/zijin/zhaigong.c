//Cracked by Roath
// Room: /d/beijing/zijincheng/zhaigong.c

inherit ROOM;

void create()
{
	set("short", "斋宫");
	set("long", @LONG
这里是皇帝在祭天，祭地等大祀之前，来此斋戒的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chengsudian",
  "west" : __DIR__"neizuomen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
