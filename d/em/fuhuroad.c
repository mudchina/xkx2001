//Cracked by Roath
// fuhuroad.c 密林
// by Shan

inherit ROOM;

void create()
{
        set("short", "密林");
        set("long", @LONG
这是黑森森的一片密林，楠木参天，浓阴蔽日。这里东下二里是报国寺，
西边林间隐藏着一座庙宇。
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"baoguo",
		"west" : __DIR__"fuhu",
        ]));

//	set("outdoors", "emei");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
