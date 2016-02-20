//Cracked by Roath
// Room: /d/beijing/east/andingmen.c

inherit ROOM;

void create()
{
	set("short", "安定门");
	set("long", @LONG
这是北京城内城九大城门中朝北向的两个城门之一--安定
门。城墙建于明永乐年间，全部用砖包砌而成，城门洞也为砖
砌筒壳，十分坚固美观。西边是德胜门，再往北就是地坛了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"zhongtianlou",
  	"up" : __DIR__"andingmenlou",
//	"north" : __DIR__"ditan",
	]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
