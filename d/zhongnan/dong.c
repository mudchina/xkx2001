//Cracked by Kafei
// road: /zhongnan/dong.c

inherit ROOM;

void create()
{
        set("short", "山洞");

        set("long",@LONG
在这小山洞的深处，一股强大的水流自地上流出，形成一条小河流向 
洞外。如果想再进一步深入的话，就得要跳入水中了。往外可到小河边。 
往里就要潜水了。 
LONG);

		  set("exits",([  "westdown" : __DIR__"water2",
				"out" : __DIR__"river",
							 ])
			  );
		  set("cost",2);

		  setup();
}

int valid_leave(object me, string dir)
{
		  if (  (dir == "westdown")
			  && ( me->query_skill("swimming",1) < 20 )
			  ) {
                  message_vision("这么急的水，你想跳下去自杀呀？", me);
		  return notify_fail("\n");
		  }
		  return ::valid_leave(me, dir);
}


