//Cracked by Roath
// road: /zhongnan/jingge3.c
// sdong 08/05/98 藏经阁三楼

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
		  set("short",HIM"藏经阁三楼"NOR);

		  set("long",@LONG
这ㄦ是重阳宫藏经阁三楼，教内最重要的书典便是存放在此。只见靠墙是一
排排书架，摆满了道教的典籍。中央有一个长方形的大桌子。这里寂静得令人害
怕。此处是重阳宫禁地，一般人是不许进来的。
LONG);

		  set("exits",([ "down" : __DIR__"jingge2.c",
							 ])
			  );
		  set("cost",1);

		  set("objects", ([
				 __DIR__"obj/"+books[random(sizeof(books))] : 1,
				 __DIR__"obj/"+books[random(sizeof(books))] : 1
		  ]));
		  setup();
}

int valid_leave(object me, string dir)
{
		  if (  (dir == "down")
			  && (!me->query_temp("qz_authorized",1) && !wizardp(me) )
			  ) {
				 message_vision("未经许可，不得离开这里！", me);
				return notify_fail("\n");
			  }

		  return ::valid_leave(me, dir);
}

