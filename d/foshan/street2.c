//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山镇街");
        set("long", @LONG
佛山自古与朱仙、景德、汉口并称天下四大镇，端是民丰物阜，市面
繁华。一条大街横亘东西。路南一家三开间门面的大酒楼，招牌上写着
“英雄楼”三个金漆大字，两边敞着窗户，酒肉香气阵阵喷出。
LONG
        );
        set("exits", ([
		"north" : __DIR__"ngate",
		"south" : __DIR__"yxlou",
		"east" : __DIR__"street3",
		"west" : __DIR__"street1",
	]));

	set("objects", ([
		__DIR__"npc/sisao" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
