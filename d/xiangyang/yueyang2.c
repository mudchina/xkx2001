//Cracked by Roath
// Room: /d/xiangyang/yueyang2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY "二楼" NOR);
	set("long", @LONG
二楼上留有许多唐代诗人李白、杜甫、白居易、李商隐等在此游湖登楼，留
的诗篇。宋庆历五年，滕子境守巴陵时重修，仲淹撰《岳阳楼记》，文情并茂
，其中“先天下之忧而忧，後天下之乐而乐”名句，千古传颂，岳阳楼随之名声
大著。二楼正面壁上嵌有一块仲淹撰《岳阳楼记》(ji)大木雕屏。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"yueyang1",
  "up" : __DIR__"yueyang3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
