//Cracked by Roath
// Room: /d/xiangyang/yueyang1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIM "一楼" NOR);
	set("long", @LONG
岳阳楼主楼平面呈长方形，宽十七米，深十五米，楼有三层三檐，通高二十
米，重檐盔顶，纯木结构，四面环以明廊，腰檐设有平台，顶层为黄色琉璃瓦顶
，檐下为蜂窝状拱，楼中有四根擎天大柱，四面有雕花窗棂，建精湛，气势
雄伟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"yueyang",
  "up" : __DIR__"yueyang2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
