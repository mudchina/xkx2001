//Cracked by Roath
// Room: /d/beijing/east/zhaoyangmen.c

inherit ROOM;

void create()
{
	set("short", "朝阳门");
	set("long", @LONG
这是北京城内城九大城门中朝东向的两个城门之一--朝阳
门。城墙建于明永乐年间，全部用砖包砌而成，城门洞也为砖
砌筒壳，十分坚固美观。再往北就是东直门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhaoyangdajie",
  "up" : __DIR__"zhaoyangmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
