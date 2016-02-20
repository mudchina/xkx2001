//Cracked by Roath
// 山路
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "山路");
    set("long", @LONG
山路盘沿在眉毛，清潭，香炉等峰的山腰里。沿路山上开满你从
未见过的山花。隐隐约约地你好象听到丝竹管弦之声，你停步仔细一
听，原来那是山林中鸟雀在流啭争鸣。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"baizpu",
	"northeast" : __DIR__"yungu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
