//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "兜天大士院");
        set("long", @LONG
这里是天龙寺众僧练武的所在，宽敞的院子里青石铺地，
在缝隙间则是用细铁沙和石灰填平，若大的一个场子看起来
关滑如镜。
LONG
        );
        set("objects", ([
"/d/shaolin/obj/mu-ren" : 1,
        ]));

        set("exits", ([
		"west" : __DIR__"tianls9.c",
        "north" : __DIR__"tianls12",
        "south" : __DIR__"tianlong2",		]));
    set("cost", 1);
        setup();
        replace_program(ROOM);
}

