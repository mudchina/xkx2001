//Cracked by Roath
// room: didao3.c
//Jay 8/12/96

inherit ROOM;

void create()
{ 
       set("short","地道");
       set("long", @LONG
这里是在一条地道中。两旁的墙壁上挂着些油灯，有的已经熄灭
了。壁上和脚下的潮气让人很不舒服。这里地道很窄，必须弓身而前。
前面一扇铁门，铁门上有尺许见方的一个洞孔。
LONG
     );
        set("exits", ([
                "southup" : __DIR__"didao2",
		"enter" : __DIR__"dilao1",
        ]));       

        set("no_clean_up", 0);
	set("cost", 1);
        setup();
        replace_program(ROOM);

}

 
