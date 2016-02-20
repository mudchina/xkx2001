//Cracked by Roath
// shandong2.c 独孤求败埋骨山洞
// qfy July 9, 1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "大山洞");
        set("long", @LONG
这洞其实甚浅，行不到三丈，已抵尽头，洞中除了一张石桌、一张石
凳之外更无别物。洞角一堆乱石高起，极似一个坟墓(grave)。洞壁(wall)
全被尘封苔蔽，黑暗中什么瞧不清楚。
LONG
        );

	set("exits", ([
                "out" : __DIR__"dongqian",
        ]));

	set("item_desc",([
	    "wall"  : "一面铺满尘苔的石壁。\n",
	    "grave" : "一个乱石堆成的坟墓，不知道是那位前辈的埋骨之所。\n"
        ]));

	set("cost", 2);
        setup();
}

void init()
{
	add_action("do_kneel", "kneel");
	add_action("do_use", "use");
}

int do_use(string arg)
{
    object me = this_player();

    if( !arg || arg=="" ) return 0;

    if (!present("fire", me))  return 0;

    if( arg=="fire" ) {
	write("你点燃了火折，伸手抹去洞壁上的青苔，突然现出三行字来，字迹笔\n");
	write("划甚细，入石却是极深，显是用极锋利的兵刃划成。看那三行字道：\n\n");
	write("纵横江湖三十馀载，杀尽仇寇，败尽英雄，天下更无抗手，无可奈何\n");
	write("惟隐居深谷，以雕为友。呜呼，生平求一敌手而不可得，诚寂寥难堪\n");
	write("也。\n");
	write("\t\t\t\t\t剑魔独孤求败\n");
	me->set_temp("marks/墙", 1);
    }	

    return 1;
}

int do_kneel(string arg)
{
	object me = this_player();

	if( !arg || arg != "grave" ) 
	   return notify_fail( "什么？\n" );

	message_vision("$N在石墓之前恭恭敬敬地跪了下来，拜了几拜。\n", me);
	me->set_temp("marks/墓", 1);

	return 1;
}
