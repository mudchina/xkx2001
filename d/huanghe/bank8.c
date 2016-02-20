//Cracked by Roath
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "黄河入海口");
        set("long", @LONG
黄河流经青藏高原、黄土高原、华北平原，总长一万零九百里，
在这里汇入大海。
LONG
        );

        set("exits", ([
		"southwest" : __DIR__"bank7",
//		"east" : __DIR__"sea1", // for fun. not serious.
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

