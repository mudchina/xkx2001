//Cracked by Roath
// Chaos, 3/10/97

inherit ROOM;
#include <localtime.h>

string* dirs = ({
	"east", "southeast", "southeast", "southwest", "northeast", "northeast",
	"west", "south", "south", "northwest", "north", "north",
	});


void create()
{

	set("short", "桃花林");
        set("long", @LONG
你走了几步，忽然想到如果岛中有人，不如在原地静坐待变，如此乱闯终究不
是个了局。说也奇怪，开始你无论如何也离不开原地，现在想觅路回去，却发现自
己离原地好象越来越远了。
LONG
        );

                set("exits", ([
                "east" : __DIR__"thzhen6",
                "south" : __DIR__"thzhen6",
                "west" : __DIR__"thzhen6",
                "north" : __DIR__"thzhen6",
                "northeast" : __DIR__"thzhen6",
                "southeast" : __DIR__"thzhen6",
                "southwest" : __DIR__"thzhen6",
                "northwest" : __DIR__"thzhen6",
                ])); 
	
	set("cost", 25);
	set("outdoors", "taohua");

	setup();
     
}

int valid_leave(object me, string dir)
{
  mixed local;
  int count;
  mapping myfam;

  myfam = (mapping)me->query("family");

  local = localtime(time()*60);

  count = ((local[LT_HOUR]+1)%24)/2;

  if (dirs[count] == dir) {
        me->move("/d/taohua/shucong");
/*        if (!myfam || myfam["family_name"] == "桃花岛") {
	  if (me->query("combat_exp")<50000+random(10000)) 
            me->add("combat_exp",random((me->query_skill("qimen-dunjia",1))/20));
	  if (me->query("potential") < me->query("max_potential")
	  && me->query("combat_exp") < 200000+random(50000) )	  
	    me->add("potential",random((me->query_skill("qimen-dunjia",1))/20)); 
	}
*/
	me->start_busy(random(3));
        return notify_fail("\n");
  }
  return ::valid_leave(me,dir);
}
