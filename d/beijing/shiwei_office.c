//Cracked by Roath
//
inherit ROOM;

void create()
{
        set("short", "厅堂");
        set("long", @LONG
这里是侍卫总管多隆大人办公之所。时常可以看见侍卫们
进进出出来讨令。正中央红木桌上端坐着的就是多大人啦。
LONG
        );

        set("exits", ([
                "out" : __DIR__"jiaochang",
        ]));
        set("objects", ([
                __DIR__"npc/duolong" : 1,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

