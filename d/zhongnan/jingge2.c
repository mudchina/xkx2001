//Cracked by Roath
// road: /zhongnan/jingge2.c
// sdong 08/05/98 藏经阁二楼

#include <ansi.h>
inherit ROOM;

string* books = ({
		  "laozi1",
		  "daodejing-i",
		  "laozi2",
		  "daodejing-i",
		  "laozi8",
		  "daodejing-i",
		  "laozi13",
		  "laozi1",
		  "laozi16",
		  "daodejing-i",
		  "laozi18"
});


void create()
{
		  set("short",HIM"藏经阁二楼"NOR);

		  set("long",@LONG
这ㄦ是重阳宫藏经阁二楼，不少教内的书典便是存放在此。只见靠墙是一
排排书架，摆满了道教的典籍。中央有一个长方形的大桌子，上面也堆满了书。
一个道童正在整理书籍。
LONG);

		  set("exits",([ "down" : __DIR__"jingge.c",
							  "up"	: __DIR__"jingge3.c",
							 ])
			  );
		  set("cost",1);

		  set("objects", ([
				 CLASS_D("quanzhen") + "/tan" : 1,
				 __DIR__"obj/"+books[random(sizeof(books))] : 1,
				 __DIR__"obj/"+books[random(sizeof(books))] : 1
		  ]));
		  setup();
}

int valid_leave(object me, string dir)
{
		  if (  (dir == "up")
			  && (!me->query_temp("qz_authorized",1) && !wizardp(me) )
			  ) {
				 message_vision("未经许可，不得进入三楼！", me);
				return notify_fail("\n");
			  }

		  return ::valid_leave(me, dir);
}


