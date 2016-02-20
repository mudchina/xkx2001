//Cracked by Roath
// /d/zhongnan/chanshen.c
//长生殿
// sdong 08/04/98

#include <ansi.h>

inherit ROOM;

void create()
{
		  set("short", HIM"养心殿"NOR);
		  set("long", @LONG
这里是重阳宫的养心殿。正中间是个敬香的大香案，地上放着几个蒲团。
养心殿四周是密密的竹林，环境十分幽雅，是全真宫真人们修身养性的地方。
据说在这里打坐、吐呐可以事半功倍。东面有一条小路通往长春殿。
LONG
		  );
		  set("valid_startroom", 1);

		  set("exits", ([
					 "eastdown" : __DIR__"taijie3",
		  ]));

		set("cost",1);

		set("objects", ([
				 CLASS_D("quanzhen") + "/sun" : 1,
			 ]));

		setup();
}



