//Cracked by Roath
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "田地");
        set("long", @LONG
这里林木渐渐稀疏，不远处有一些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，田里有一些正在耕作的农人。
LONG
        );

        set("exits", ([
                "south" : __DIR__"forest3",
		"east" : __DIR__"field3",
		"west" : __DIR__"field1",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

