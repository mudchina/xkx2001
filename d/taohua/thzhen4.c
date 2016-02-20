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
你一走进桃林，看见东一簇桃花，西一丛桃树，顿时目眩神迷，迷失了方向。
你慌乱中刚想退出，回头一瞧，来路已在花丛中消失得无影无踪，看来只有硬着头
皮往前走了。
LONG
	);

		set("exits", ([
		"east" : __DIR__"thzhen4",
		"south" : __DIR__"thzhen4",
		"west" : __DIR__"thzhen4",
		"north" : __DIR__"thzhen4",
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
        me->move("/d/taohua/thzhen5");
       /* if (!myfam || myfam["family_name"] == "桃花岛") {
	if (me->query("combat_exp")<50000+random(10000)) 
	me->add("combat_exp",random((me->query_skill("qimen-dunjia",1))/30));

	if (me->query("potential") < me->query("max_potential")
	&& me->query("combat_exp") < 200000+random(50000))
	me->add("potential",random((me->query_skill("qimen-dunjia",1))/30));
          
        }
	*/
  	me->start_busy(random(3));
        return notify_fail("\n");
  }
  return ::valid_leave(me,dir);
}


