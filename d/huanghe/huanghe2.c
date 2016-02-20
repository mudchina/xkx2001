//Cracked by Roath
// Jay 10/11/96

inherit ROOM;

void create()
{
        set("short", "黄河");
        set("long", @LONG
黄河沿蒙古高原南边向东流淌，遇太行山脉的阻拦，便转头
南下，形成晋陕的分界。
LONG
        );

        set("exits", ([
		"west" : __DIR__"hetao",
		"south" : __DIR__"weifen",
        ]));

	set("outdoors","forest");
	set("cost", 3);
        setup();
	replace_program(ROOM);
}

