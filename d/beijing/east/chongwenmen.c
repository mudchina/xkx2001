//Cracked by Roath
// Room: /d/beijing/east/chongwenmen.c

inherit ROOM;

void create()
{
	set("short", "崇文门");
	set("long", @LONG
这是北京城内城九大城门中朝南向的三个城门之一--崇文
门。城墙建于明永乐年间，全部用砖包砌而成，城门洞也为砖
砌筒壳，十分坚固美观。西边是正阳门，再往北就是长安街了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chongwendajie",
  "north" : __DIR__"dongchangan2",
  "up" : __DIR__"chongwenmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
