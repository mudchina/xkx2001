//Cracked by Roath
// Room: /d/xiangyang/yueyang3.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW "三楼" NOR);
	set("long", @LONG
登楼南望岘山群峰竟秀，岗峦起伏；北瞰汉水缭绕烟云，碧波萦带。风景极
佳，为江南名楼之一，历有“洞庭天下水，岳阳天下楼”的盛誉。三楼壁上有“
鲁肃练兵”、“张说题辞”两幅故事画。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"yueyang2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
