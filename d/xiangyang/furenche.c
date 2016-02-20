//Cracked by Roath
// Room: /d/xiangyang/furencheng.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC "夫人城" NOR);
	set("long", @LONG
相传东晋宁康初年，梁州刺史朱序镇守襄阳时，前秦大将苻丕领兵来攻，朱
母韩夫人登城巡视，发现这城桓防守薄弱，遂率女婢和城内妇女在此起一道
约二十米长的新城。後苻丕领兵从西北攻城，并攻破旧城，幸有新城防守，才击
退攻城之敌。为了纪念韩夫人这一功劳，人们将这段城墙命名为“夫人城”。
LONG
	);
        set("coordinates", ([ "x" : -4, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"beijie3",
]));
	set("no_clean_up", 0);
        set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
