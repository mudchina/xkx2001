//Cracked by Roath
// Room: /d/beijing/west/deshengmen.c

inherit ROOM;

void create()
{
	set("short", "得胜门");
	set("long", @LONG
这是北京城内城九大城门中朝北向的两个城门之一--得胜
门。城墙建于明永乐年间，全部用砖包砌而成，城门洞也为砖
砌筒壳，十分坚固美观。东边就是安定门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"deshengjie",
  "up" : __DIR__"deshengmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
