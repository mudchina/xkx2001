//Cracked by Roath
// acep , mantian , mantian

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "万劫谷谷口");
	set("long", @LONG
这里是一个山谷的谷口，一大片平坦的草地，两边山壁陡峭，没有出路。远
处尽头又全是一株株大松树，其中一株(songshu)看起来有些特别。
LONG);
	set("item_desc", ([
		"songshu" : "这株松树上削下了长许长，尺许宽的一片，漆了白漆，写着九个大字：\n“姓段者入此谷" RED "杀" NOR "无赦”，八字漆黑，那“杀”字却作殷红色。\n",
		]));
	set("exits", ([
		"out"   : __DIR__"senlin1.c",
		"north" : __DIR__"wjg2.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
