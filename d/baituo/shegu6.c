//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "蛇谷平地");
	set("long", @LONG
这是蛇谷的一处较平坦开阔的地带，地上满是矮小无叶的骆驼刺
和碎小的乱石。平缓的地势从这里往西边略为延伸，此外各方向都是
斑驳的林木。
LONG
	);

	set("exits", ([ 
	    "southeast" : __DIR__"shegu5",
	    "west" : __DIR__"shegu7",
	    "northeast" : __DIR__"shegu13",
	]));

	set("objects", ([
	    "/d/city/obj/stone" : 1,
	]));

	set("resource/grass", 1);
	set("cost", 1);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}
