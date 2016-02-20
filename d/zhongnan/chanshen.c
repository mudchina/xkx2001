//Cracked by Roath
// /d/zhongnan/chanshen.c
//长生殿
// sdong 08/04/98

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", HIM"长生殿"NOR);
		  set("long", @LONG
这里是重阳宫的长生殿。正中间是个敬香的大香案，地上放着几个蒲团。
这里香火极旺，众多香客们正在进香，祈求长生不老。北边通往后殿，南边通
往长春殿。
LONG
		  );
		  set("valid_startroom", 1);

		  set("exits", ([
					 "northdown" : __DIR__"taijie",
					 "southdown" : __DIR__"taijie2",
		  ]));

		set("cost",1);

		set("objects", ([
				 CLASS_D("quanzhen") + "/liu" : 1,
			 ]));

		setup();
}

