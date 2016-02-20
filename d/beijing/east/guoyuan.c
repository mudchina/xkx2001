//Cracked by Roath
// Room: /d/beijing/east/guoyuan.c

inherit ROOM;

void create()
{
	set("short", "果园");
	set("long", @LONG
这里种植了很多果树。每到秋季，果实累累。花草丛中蝴蝶
纷飞，不时还可以看到几只小兽从旁边跑过。南面便是景山了，远
远望去，可以隐约看到几座亭子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shouhuangdian",
  "southup" : __DIR__"shandao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
