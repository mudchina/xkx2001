//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "后门");
	set("long", @LONG
这里是北海花园的后门，门是虚掩着的。门前面站着两个卫士。门
两边长着茂盛的植物。一些苦力背着东西进进出出，甚是忙碌。由门向
北是一条官道。
LONG
	);
	set("cost", 2);
	set("exits", ([
                "west" : __DIR__"jingqing",
                "south" : __DIR__"huafang",
                ]));
	
	
	setup();
	replace_program(ROOM);
}
