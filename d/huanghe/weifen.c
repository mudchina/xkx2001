//Cracked by Roath
// Jay 10/11/96

inherit ROOM;

void create()
{
        set("short", "渭汾流域");
        set("long", @LONG
汾河和渭河汇入黄河，增大了其水势，也带来了更多的泥沙。
这里河东是晋，河西是陕。
LONG
        );

        set("exits", ([
		"north" : __DIR__"huanghe2",
		"south" : __DIR__"bank1",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

