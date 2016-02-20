//Cracked by Roath
// Room: /d/xingxiu/gcmaze2.c
// Date: June 30, 96   Jay

inherit ROOM;

void create()
{
	set("short", "高昌迷宫");
	set("long", @LONG
走在黑漆漆的甬道里，你不禁有些发抖。不知道什麽时候
才能走到头。
LONG
	);

	set("exits", ([
		"out" : __FILE__,
                "enter" : __FILE__,
	]));

	set("cost", 7);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir=="enter") me->add_temp("marks/step",1);
	if (dir=="out") me->add_temp("marks/step",-1);
	if (me->query_temp("marks/step")==5)
	return notify_fail(
"突然之间，前面一个阴森森的声"+
"音喝道：「我在这里\n已安安静静的住了一千年，谁也不敢来打扰我。那一个"
+"\n大胆过来，立刻就死！」\n");

	if (me->query_temp("marks/step")==10) {
	  me->move("/d/xingxiu/gcmaze3");
	  me->delete_temp("marks/step");
//	  return notify_fail("\n"）；
return notify_fail("\n");
	}

        if (me->query_temp("marks/step")==-10) {
          me->move("/d/xingxiu/gcmaze1");
          me->delete_temp("marks/step");
//          return notify_fail("你终於走出甬道。\n"）；
return notify_fail("\n");
        }

	return ::valid_leave(me, dir);
}	
