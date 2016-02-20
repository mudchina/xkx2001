//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "山腹石室");
	set("long", @LONG
这是白玉峰中的石室，只见四面石壁都是晶莹白玉，景色
绮丽。地下放着几张桌椅，仍是坚牢完固，原来山洞密闭，不
受风侵，是以洞中物事并不朽烂。
LONG
	);

	set("exits", ([
		"north" : __DIR__"jaderoad1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/obj/yujian" : 1,
	]) );

	set("cost", 1);
	setup();
}
