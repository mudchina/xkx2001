//Cracked by Roath
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "黄河岸边");
        set("long", @LONG
这里是黄河岸边。黄河流淌到这里，河床宽阔。黄色的河水在
静静地向东流去，使人忘记它发洪水时的狂威。
LONG
        );

        set("exits", ([
		"northeast" : __DIR__"bank7",
		"southwest" : __DIR__"bank5",
        ]));

	set("objects", ([
		__DIR__"npc/qiu.c" : 1,
	]));

	set("outdoors", "huanghe");
	set("cost", 2);
        setup();

	replace_program(ROOM);
}

