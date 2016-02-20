//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "九龙壁");
	set("long", @LONG
这里是小西天西之九龙壁，青白玉基台，上有绿琉璃须弥座，壁面前
后各有九条形态各异，奔腾在云雾波涛中的蛟龙浮雕。壁东面为江崖海水，
旭日东升流云纹饰，西面为江崖海水，明月当空流云纹饰。影壁用四百二
十四块七色琉璃砖砌筑而成。色彩绚丽，古朴大方。
LONG
	);
	set("cost", 2);
    
	set("exits", ([
                "south" : __DIR__"dukou1",
                "east" : __DIR__"xitian",
        ]));
	
	
	setup();
	replace_program(ROOM);
}