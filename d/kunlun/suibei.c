//Cracked by Roath
// room: /mingjiao/suibei.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "随北山");
        set("long", @LONG
这里草深林密，藤蔓交错，似乎从未有人走过。你穿行在山间密林之
中，行走极为艰难。风中不时夹杂着怪异的啸声，令人不寒而栗。俗说深
山多猛兽，如不是胆气十足，最好还是原路返回吧。
LONG );

        set("exits", ([
                "southdown" : __DIR__"yushuquan",
                "north" : __DIR__"moli",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}