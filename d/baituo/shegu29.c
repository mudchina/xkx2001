//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;
string look_cave();

void create()
{
	set("short", "山壁");

	if(random(3) != 0 ) {
		set("long", @LONG
这是白驼山的蛇谷之中，附近紧邻山壁，到处都是石砾。石壁上
稀稀疏疏地长着几棵小树，风吹过来，不时有一些小石头从壁上滑落
下来。山壁一角有个小洞(cave)。
LONG
		);

		set("item_desc", ([
		"cave" : (: look_cave :),
		]));

		set("hide_snake", 1);
		set("cave", 1);
	}
	else {
		set("long", @LONG
这是白驼山的蛇谷之中，附近紧邻山壁，到处都是石砾。石壁上
稀稀疏疏地长着几棵小树，风吹过来，不时有一些小石头从壁上滑落
下来。
LONG
		);
		set("objects", ([
		    "/d/city/obj/stone" : 1,
		    "/d/quanzhou/npc/laoshu" : 1,
		]));
	}

	set("exits", ([ 
	    "northwest" : __DIR__"shegu14",
	    "northeast" : __DIR__"shegu28",
	]));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
