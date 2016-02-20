//Cracked by Roath
// Room: /d/beijing/west/fuchengmen.c

inherit ROOM;

void create()
{
	set("short", "阜成门");
	set("long", @LONG
这是北京城内城九大城门中朝西向的两个城门之一--阜成
门。城墙建于明永乐年间，全部用砖包砌而成，城门洞也为砖
砌筒壳，十分坚固美观。再往北就是西直门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"fuchengmenlou",
  "east" : __DIR__"fuchengmenjie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
