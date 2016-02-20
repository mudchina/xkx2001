//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条沿着湖的小路，路西边是一片松树林，上的白塔。松树林里不时可以
看见一只只松鼠跳来跳去。东面隐隐可以看见一个亭子的一角。
LONG
	);
	set("cost", 2);
	set("exits", ([
                "northeast" : __DIR__"dukou1",
                "east" : __DIR__"wulong",
                "south" : __DIR__"xiaolu1",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
