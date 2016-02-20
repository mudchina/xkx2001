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
                "southwest" : __DIR__"forest5",
		"east" : __DIR__"field2",
        ]));

	set("outdoors","forest");
	set("objects", ([
		"/clone/beast/banjiu" : random(2), 
	]));

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

