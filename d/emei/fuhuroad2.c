//Cracked by Roath
// /d/emei/fuhuroad2.c 密林
// by Shan

inherit ROOM;

void create()
{
        set("short", "密林");
        set("long", @LONG
这是黑森森的一片密林，楠木参天，浓阴蔽日。这里西上是报国寺，东边
林间隐藏着一座庙宇。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"fuhu",
		"westup" : __DIR__"jietuo",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
