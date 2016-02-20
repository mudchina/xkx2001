//Cracked by Roath
// 暗道 to huashan
// qfy August 17, 1996

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG
	);

	set("exits", ([
			"northwest" : __DIR__"hsandao2",
			"southeast" : __DIR__"undertre",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
