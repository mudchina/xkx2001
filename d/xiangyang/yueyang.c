//Cracked by Roath
// Room: /d/xiangyang/yueyang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR "岳阳楼" NOR);
	set("long", @LONG
相传岳阳楼的前身为三国吴将鲁肃操练水师的阅兵。唐开元四年中书令张
说谪守岳州时始建楼，定名“岳阳楼”。後几经兴废，自洞庭湖畔搬迁自此。楼
建在一大平中间，两头各有一座牌坊。正门外牌坊上有大书“巴陵胜状”四
字横匾，并配以“岳阳天下楼”，“洞庭天下水”的名句，气势轩昂。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 1, "y" : 3 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"jzjie1",
  "enter" : __DIR__"yueyang1",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
