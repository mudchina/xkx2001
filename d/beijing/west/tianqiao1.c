//Cracked by Roath
// Room: /d/beijing/west/tianqiao1.c

inherit ROOM;

void create()
{
	set("short", "天桥");
	set("long", @LONG
这里是北京城最繁华热闹的地方，龙蛇混杂，三教九流无所不包；
这在这里跑江湖卖解的，说书唱曲的，百货小吃，无所不有，不过这
里藏龙卧虎，其中也不乏深藏不露的隐士高人
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"chaguan",
	"north" : __DIR__"quanjude",
	"west" : __DIR__"caishikou",
	"east" : __DIR__"tianqiao2",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
