//Cracked by Roath
// /d/changbai/gaoliangdi.c

inherit ROOM;

void create()
{
        set("short", "高粱地");
        set("long", @LONG
这里是北京近郊的高粱地，共二三十亩，高粱稀稀落落。高粱田后有两
间农舍，过了篱笆，推开板门，你发现角里堆了不少农具。后面有一个小院子。
LONG
        );

        set("outdoors", "shenlong");

        set("exits", ([
                "south" : __DIR__"yidao2",
        ]));

        set("objects",([
            //    "/kungfu/class/shenlong/hong" : 1,
                "/kungfu/class/shenlong/xu" : 1,
                
        ]));

        set("cost", 3);

        setup();
        replace_program(ROOM);
}
