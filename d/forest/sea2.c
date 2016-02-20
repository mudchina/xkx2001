//Cracked by Roath
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "黄海");
        set("long", @LONG
这里是黄海。
LONG
        );

        set("exits", ([
		"northwest" : __DIR__"sea1",
		"southeast" : __DIR__"sea3",
        ]));

	set("outdoors","forest");
	set("cost", 5);
        setup();
	replace_program(ROOM);
}

