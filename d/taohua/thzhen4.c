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

	set("short", "�һ���");
	set("long", @LONG
��һ�߽����֣�������һ���һ�����һ����������ʱĿѣ���ԣ���ʧ�˷���
������и����˳�����ͷһ�ƣ���·���ڻ�������ʧ����Ӱ���٣�����ֻ��Ӳ��ͷ
Ƥ��ǰ���ˡ�
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
       /* if (!myfam || myfam["family_name"] == "�һ���") {
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

