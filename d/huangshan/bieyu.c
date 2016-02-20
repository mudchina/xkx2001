//Cracked by Roath
// 鳖鱼峰
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "鳖鱼峰");
    set("long", @LONG
鳖鱼峰因其形状像一张嘴遨游的鳖鱼而得名。山上还有一洞，洞
里阴气阵阵，还是不要进去为妙。再往上就到天海了，往下是百步云
梯。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"baibu",
	"northup" : __DIR__"tianhai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
