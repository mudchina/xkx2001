//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山镇街");
        set("long", @LONG
佛山镇街道横亘东西。南边有一座破败的庙宇，里面是一家
赌场，大门上写着“英雄会馆”四个大字。
LONG
        );
        set("exits", ([
		"south" : __DIR__"yxhuiguan",
		"east" : __DIR__"street2",
		"west" : __DIR__"street0",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
