//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "庆宵楼");
	set("long", @LONG
这座庆霄楼为一踞山半之二层建筑，歇山顶。上层四周挑廊，是冬日
观冰嬉之所。站在这里可以清楚的看见琼岛以西的景色。
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "southdown" : __DIR__"yuexin",
                "northdown" : __DIR__"yuegu",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
