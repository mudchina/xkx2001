//Cracked by Roath
// Room: /d/beijing/west/xuanwumen.c

inherit ROOM;

void create()
{
	set("short", "宣武门");
	set("long", @LONG
这是北京城内城九大城门中朝南向的三个城门之一--宣武
门。城墙建于明永乐年间，全部用砖包砌而成，城门洞也为砖
砌筒壳，十分坚固美观。东边就是皇城的正门天安门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"caishikou",
  "north" : __DIR__"xuanwudajie2",
  "up" : __DIR__"xuanwumenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
