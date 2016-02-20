//Cracked by Roath
// emroad4.c 小路
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是陕西境内。一条静悄悄的黄土路，两旁有些小土屋，疏疏落落的。
但路上行人很少，都行色匆匆向前赶路。
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"emroad5",
					 "west" : __DIR__"emroad3",
                "north": "/d/zhongnan/daolu",
        ]));

        set("objects", ([
            "/d/city/obj/stone" : 2,
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

