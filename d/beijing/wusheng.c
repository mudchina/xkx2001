//Cracked by Roath
// Room: wusheng 武胜镖局
// Ssy

inherit ROOM;

void create()
{
        set("short", "武胜镖局");
        set("long", @LONG
这是京城里招牌最老的镖局，大门口左右各有一座石狮子，张牙舞爪，面目
狰狞。门上有一赤红大匾，上书“武胜镖局”四个斗大的黑字，银钩铁划，刚劲
非凡。入口处几名镖头把守着。
LONG
        );

        set("exits", ([
                "west" : __DIR__"wangfudajie",
                "north" : __DIR__"biaoju",
        ]));

        set("objects", ([
                __DIR__"npc/biaotou" : 3,
        ]));

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

