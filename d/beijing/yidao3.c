//Cracked by Roath
//yidao3.c
inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上，四周静悄悄的。北方就是著名的山海关了，东面是
大海之滨。
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"southwest" : __DIR__"yidao2",
                 "east" : __DIR__"tanggu",
                 "north": "/d/changbai/shguan2",
        ]));
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
