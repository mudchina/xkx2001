//Cracked by Roath
// Room: tiyf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "梯云峰");
	set("long", @LONG
此峰位于天池南侧，岩石裸露，形状如梯。山头终年云雾缭绕，即使是
晴天也看不到峰顶的轮廓。传说此峰直通天宫，是天庭和人间相连的天梯，
因此叫梯云峰。
LONG	);
	set("exits", ([ 
              "northdown" : __DIR__"tianchi",
              "northwest" : __DIR__"yuzf",
              "northeast" : __DIR__"longmf",
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
