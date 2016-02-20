//Cracked by Roath
// /d/emei/emroad5.c 小路
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里一条静悄悄的黄土路，两旁有些小土屋，疏疏落落的。路上行人很少，
都行色匆匆向前赶路。
LONG
        );
        set("exits", ([
                "east" : __DIR__"emroad6",
                "southwest" : __DIR__"emroad4",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

