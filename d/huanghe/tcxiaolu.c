//Cracked by Roath
// /d/huanghe/tcxiaolu.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这是一个宁静的小渔村，中间一条黄土路，两边有几间土坯泥房。门
外零零落落放着一些积满灰尘的渔具和渔网，看样子已经很久没人在此居
住打鱼了。
LONG );

        set("exits", ([
		"west"  : __DIR__"tckitchen",
		"east"  : __DIR__"tctuwu",
                "north" : __DIR__"tccunko", 
        ]));

    	set("cost", 1);

        set("outdoors", "huanghe");

        setup();
        replace_program(ROOM);
}
