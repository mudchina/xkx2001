//Cracked by Roath
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "田地");
        set("long", @LONG
这里是一片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，田里有一些正在耕作的农人。村里不时传出一声声
的犬吠。
LONG
        );

        set("exits", ([
		"north" : "/d/huanghe/bank1",
//		"east" : "/d/village/wexit",
		"southwest" : __DIR__"field3",
        ]));

        set("objects", ([ "/d/village/npc/dog": 1 ]) );

	set("outdoors", "forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

