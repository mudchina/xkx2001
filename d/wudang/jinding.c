//Cracked by Roath
// jinding.c 金顶 
// by Fang 8/20/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"金顶"NOR);
	set("long", @LONG
	你感到寒意阵阵袭来，原来你已到了武当山的主峰天柱峰的绝顶。前面
的金殿由铜铸成，镀以黄金，每当旭日临空，整个殿宇金光闪闪，故名金顶。天
柱峰高高独立于群峰之上，东西壁立二山，名叫蜡烛峰，中壁立一山似香炉，名
香炉峰，万山千壑，隐隐下伏。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"santian",
                "south" : __DIR__"zijin",
                "west" : __DIR__"liantai",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

