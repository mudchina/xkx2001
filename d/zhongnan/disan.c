//Cracked by Roath
// /d/zhongnan/disan.c
//广宁殿
// sdong 08/04/98

#include <ansi.h>

inherit ROOM;

void create()
{
		  set("short", HIC"广宁殿"NOR);
		  set("long", @LONG
这里是重阳宫的广宁殿，是全真七子集议之所。正中间是个敬香的大香
案，靠墙放着七张太师椅，地上放着几个蒲团。东西两侧是走廊，北边是广
场，南边通往三清殿。
LONG
		  );
		  set("valid_startroom", 1);

		  set("exits", ([
					 "north" : __DIR__"guangchang",
					 "south" : __DIR__"guangchang3",
					 "east" : __DIR__"donglang",
					 "west" : __DIR__"xilang",
		  ]));

		set("cost",1);

		set("objects", ([
				 CLASS_D("quanzhen") + "/hao" : 1,
			 ]));

		setup();
}
