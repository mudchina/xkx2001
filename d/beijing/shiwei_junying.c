//Cracked by Roath
//
inherit ROOM;

void create()
{
        set("short", "营房");
        set("long", @LONG
这里是侍卫们饮食起居的地方。有的侍卫在睡觉。你
想睡就赶紧吧。
LONG
        );
        set("sleep_room",1);

        set("exits", ([
                "out" : __DIR__"jiaochang",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

