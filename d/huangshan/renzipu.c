//Cracked by Roath
// 人字瀑
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "人字瀑");
    set("long", @LONG
一条形同人字的白练悬挂在紫云和朱砂二峰之间，鸣声如雷，声
震数里之外。隐隐中只见瀑床中间錾有云梯般的蹬道。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"wenquan",
	"west" : __DIR__"minghong",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
