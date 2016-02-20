//Cracked by Roath
// 百丈瀑
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "百丈瀑");
    set("long", @LONG
一条白练挂在清潭和紫云二峰之间，攀岩千尺飞泻而下，故得名
“百丈瀑”。枯水季节涓涓细流，如轻纱缥缈，又称百丈泉。百丈泉
上叫布水源，下面有百丈潭。旁边是专供游客观瀑的观瀑亭。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"wenquan",
	"northeast" : __DIR__"shanlu1",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
