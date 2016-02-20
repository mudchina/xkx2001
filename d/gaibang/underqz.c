//Cracked by Roath
// 暗道 to huashan
// qfy August 17, 1996

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
暗道上方连着泉州南门旁的一所破旧的土地庙。平时人烟罕至，
是以丐帮选此为根据地之一。
LONG
	);

	set("exits", ([
		"up" : "/d/quanzhou/tudi",
		"north":__DIR__"qzandao2",	
	]));

	set("objects",([
		CLASS_D("gaibang") + "/kuaihuo-san" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
