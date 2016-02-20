//Cracked by Roath
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "崖顶");
        set("long", @LONG
这里是摩天崖崖顶。向下望去，村庄、河流都成了小点，令人头晕
目眩。
LONG
        );

        set("exits", ([
                "down" : __DIR__"middle",
		"north" : __DIR__"mty1",
        ]));

	set("cost", 1);
	set("outdoors", "city");
        setup();
        replace_program(ROOM);
}


