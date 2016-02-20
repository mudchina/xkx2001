//Cracked by Roath
// 暗道 to huashan
// qfy August 17, 1996

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
华山暗道至此已到尽头，往上便是华山东村村口。
LONG
	);

	set("exits", ([
		"up" : "/d/village/eexit",
		"west":__DIR__"hsandao2",	
	]));

	set("objects",([
		CLASS_D("gaibang") + "/mo-bushou" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
