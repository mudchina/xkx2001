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
		"west" : __DIR__"road3",
	]));


        set("objects", ([
                        __DIR__"npc/yuan" : 1
	]));
	set("cost", 1);
	setup();
	set("outdoors","quanzhou");
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( present("yuan ziyi",me))
		return notify_fail("你想拐带良家妇女？小心红花会的英雄找你报仇！\n");

        return ::valid_leave(me, dir);
}

