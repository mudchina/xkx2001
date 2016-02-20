//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "茶亭");
        set("long", @LONG
这是一家路边的小茶亭，赶山路的人常在此处歇歇脚。亭子里
有几张桌子和几支条凳。周围是一片树林。
LONG
        );
        set("exits", ([
		"northwest" : __DIR__"jxnanmen",
	]));


        set("objects", ([
                        __DIR__"npc/xiang" : 1
	]));
	set("cost", 1);
	setup();
	set("outdoors","quanzhou");
        replace_program(ROOM);
}
