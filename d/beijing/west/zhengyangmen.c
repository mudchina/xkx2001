//Cracked by Roath
// Room: /d/beijing/west/zhengyangmen.c

inherit ROOM;

void create()
{
	set("short", "正阳门");
	set("long", @LONG
这是北京城内城九大城门中朝南向的三个城门之一--正阳
门。城墙建于明永乐年间，全部用砖包砌而成，城门洞也为砖
砌筒壳，十分坚固美观。再往北就是天安门了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"zhengyangmenlou",
  "north" : "/d/beijing/zijin/tianansquare",
  "south" : __DIR__"zhengyangdajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
