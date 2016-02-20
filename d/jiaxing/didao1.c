//Cracked by Roath
// room: mishi.c
//Jay 8/12/96

inherit ROOM;

void create()
{ 
       set("short","地道");
       set("long", @LONG
这里是在一条地道中。两旁的墙壁上挂着些油灯，有的已经熄灭
了。壁上和脚下的潮气让人很不舒服。
LONG
     );
        set("exits", ([
                "out" : __DIR__"qinshi",
		"northdown" : __DIR__"didao2",
        ]));       

        set("no_clean_up", 0);
	set("cost", 1);
        setup();
        replace_program(ROOM);

}

 
