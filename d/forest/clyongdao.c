//Cracked by Roath
// changle/clyongdao.c
// by aln 2 / 98

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
长长的甬道通向一个石室，旁边壁上每隔不远便有一盏油灯，头
上是高高的拱顶，显得有些阴森可怖。几名帮众在这里把守，闲杂人等
不能随意前进。
LONG );

        set("exits", ([
	       "east" : __DIR__"clshishi",
	       "west" : __DIR__"clhuayuan",
        ]));

	set("cost", 0);

        set("objects",([
               __DIR__"npc/cl_bangzhong" : 1,
        ]));

        setup();

        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "east" )
                 return ::valid_leave(me, dir);

        if( !(ob = present("changle bangzhong", environment(me))) )
                 return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        message_vision("$N拦在$n面前，说道：里面是关押本帮叛徒的地方，你请回吧。\n", ob, me);
        return notify_fail("");
}

