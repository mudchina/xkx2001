//Cracked by Roath
// hsforest4
// qfy Oct 15, 97

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
树林里生着北方常见的榆树和杨树，树木高大，遮掩得天色都黯淡了
下来。无数枝叶在风中摇摆，发出奇异的响声。落叶踩下后又慢慢恢复原
状，竟不留任何足迹。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"hsforest1",
		"north" : __DIR__"hsforest18",
		"west" : __DIR__"hsforest6",
		"east" : __DIR__"hsforest5",		
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

#include "/d/huashan/hsforest.h"