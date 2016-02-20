//Cracked by Roath
// Room: /d/xiangyang/wofang2.c

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG
这间卧房是郭家大小姐郭芙的闺房，窗边一张梳妆，上点
著一对红烛，照得房内暖洋洋地。床前罗纱帐子低垂，床上放置著
一张白色绣缎被。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 5, "y" : -5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huilang1",
]));

	setup();
	replace_program(ROOM);
}
