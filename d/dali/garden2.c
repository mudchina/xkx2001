//Cracked by Roath
// Room: /d/dali/garden2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"茶花园"NOR);
	set("long", @LONG
这花园在水边一排垂柳之后，一丛丛花树映水而红，灿若云霞。一眼望去，
都是红白缤纷的茶花，但似乎胡乱生长，并无佳品。
LONG);
	set("exits", ([
		"northwest" : __DIR__"garden4.c",
		"northeast" : __DIR__"garden3.c",
		"out" : __DIR__"garden1.c",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
