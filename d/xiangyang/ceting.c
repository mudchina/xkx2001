//Cracked by Roath
// Room: /d/xiangyang/ceting.c

inherit ROOM;

void create()
{
	set("short", "侧厅");
	set("long", @LONG
这屋子虽说是制置使平时接见将官所在，房中却摆满了刀枪剑戟。见地上
铺着虎皮豹皮，墙上挂着弓矢刀剑，不脱武人粗犷本色。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -3, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bingyi",
  "south" : __DIR__"djtai",
]));

	setup();
	replace_program(ROOM);
}
