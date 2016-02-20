//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "阿拉沟");
	set("long", @LONG
这里是穿越天山的主要隘口。小路幽深曲折，山势陡峭，山泉汇
聚成溪，有时跌落为瀑布。一路上山青水秀，景色宜人。从阿拉沟上
溯三十里，村庄毗连，阡陌纵横。
LONG
	);
	set("exits", ([
                "north" : __DIR__"alagou2",
                "southdown" : __DIR__"shankou",
        ]));
	set("cost", 3);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
