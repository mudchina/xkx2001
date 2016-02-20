//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山镇街");
        set("long", @LONG
佛山镇街道平整。西面是镇西门，北面有一座北帝庙，建构宏伟，
好大一座神祠。
LONG
        );
        set("exits", ([
		"north" : __DIR__"beidi",
		"east" : __DIR__"street1",
		"west" : __DIR__"wgate",
	]));

	set("objects", ([
		"/d/city/npc/jiading" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
