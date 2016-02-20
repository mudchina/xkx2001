//Cracked by Roath
//Kane

#include "/d/taihu/guiyun.h"
inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这是一处典型的江南园林，规模虽不大，构造得却颇为精致，
想必当年建园之人很费了一番心力。园中花气袭人，莺啼燕舞，柳
条随风，绿波荡漾，只待得片刻便令人如沐春风，流连忘返。
LONG
	);

	set("exits", ([
		"east" : __DIR__"liangong",
		"north" : __DIR__"chufang",
		"south" : __DIR__"huating",
	]));
	set("cost", 1);
	set("outdoors", "taihu");
	set("objects", ([
		"/d/taihu/npc/xiaoju" : 1,
//		"/d/taihu/npc/xiaoping" : 1,
	]));

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
	
    if ( (!myfam || myfam["family_name"] != "桃花岛") && dir == "east" ) {
//        if ( (!myfam || myfam["family_name"] != "桃花岛") && dir != "north" )
           return notify_fail("归云庄不留外客，你不能往这边走！\n");
    }
    return ::valid_leave(me, dir);
}
