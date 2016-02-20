//Cracked by Roath
// Room: /d/beijing/qianqing/yangxindian.c

inherit ROOM;

void create()
{
    set("short", "内膳房");
	set("long", @LONG
皇帝进膳多在养心殿.乾清宫等处,内膳房设在养心殿前很方便.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north": __DIR__"yangxind",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
