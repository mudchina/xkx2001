//Cracked by Roath
// yideng quest room 9

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "庙前");
        set("long", @LONG
这里是深山巅峰，平地上有一座小小寺院，庙前有一个荷塘，一座小桥横跨
其上。旁边陡峭的山崖上有一条铁链和一些人工凿出来的台阶，似乎是一条上下
山的捷径。
LONG);
	set("exits", ([
		"south" : __DIR__"yideng8",
		"enter" : __DIR__"yideng11",
		"down" : __DIR__"maze1",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoor","dali");
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
