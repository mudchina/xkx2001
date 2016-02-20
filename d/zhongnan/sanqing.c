//Cracked by Roath
// /d/zhongnan/sanqing.c
// sdong 07/98

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIM"三清殿"NOR);
        set("long", @LONG
这里是重阳宫的三清殿，是全真教会客的地点。供着元始天尊、太上道
君和太上老君的神像。正中间是个敬香的大香案，靠墙放着几张太师椅，地
上放着几个蒲团。东西两侧是走廊，北边是广场，南边通往山门殿。
LONG
        );
        set("valid_startroom", 1);
        
        set("exits", ([
                "north" : __DIR__"guangchang3",
                "southdown" : __DIR__"taijie1",
                "east" : __DIR__"cedian2",
                "west" : __DIR__"cedian1",
		  ]));

        set("objects", ([
                CLASS_D("quanzhen") + "/wang" : 1,
			  ]));

	  set("cost",1);

      setup();
}    
