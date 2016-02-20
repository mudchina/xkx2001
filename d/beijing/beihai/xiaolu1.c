//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条沿着湖的小路，路西边是一片松树林，东面可以看见琼岛上的白塔。
松树林里不时可以看见一只只松鼠跳来跳去。
LONG
	);
	set("cost", 2);
	set("exits", ([
                "south" : __DIR__"ximen",
                "north" : __DIR__"xiaolu2",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
