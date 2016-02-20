//Cracked by Roath
// room: /d/mingjiao/shijie1.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "石阶");
    set("long",@LONG
这是一条长长的青石阶，两旁站着几个明教护卫，每人的左袖上都绣
有一血红的火焰。在石阶的尽头，耸立着两个高十丈的箭楼。如有外人闯
进这里，箭楼上的弓箭手将会发动攻击。
LONG
	);

 	set("exits",([
		      "north" : __DIR__"yongdao",	
		      "southeast" : __DIR__"shanmentongdao",	
		      	]));
	set("outdoors", "mingjiao");
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

