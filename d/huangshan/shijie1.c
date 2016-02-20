//Cracked by Roath
// 石阶
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "石阶");
    set("long", @LONG
一条长长的石阶向下沿伸，据说有五千九百石级。你走在这长长
的石路上，每下一层石级，就对清凉二字增加一层体会。环四周，犹如
潜入了海底。山谷之中填满了乳白色的雾气，像一位披了面纱的少妇。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"qinglian",
	"down" : __DIR__"shijie2",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
