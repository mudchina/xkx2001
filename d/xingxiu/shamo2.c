//Cracked by Roath
// Room: /d/xingxiu/shamo2.c

#include <room.h>
inherit ROOM;

void create()
{
       set("short","��ɳĮ");
       set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����һ��������ʧ�˷���
����Ҫ�߳����ɳĮ�������¡�
LONG
     );
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"shamo3",
		"south" : __DIR__"shamo4",
		"north" : __DIR__"shamo1",
	]));
	set("cost", 5);
	setup();
	set("outdoors", "xingxiu-hai");
}

#include "/d/xingxiu/shamo.h"