//Cracked by Roath
// 白堤
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", HIG"白堤"NOR);
    set("long", @LONG
白堤横旦湖上，把西湖分成里湖与外湖。堤上种满了杨柳，碧桃。
每逢春至，“翩翩柳丝泛绿，树树桃颜带笑”。白居易曾有“乱花渐
欲迷人眼，浅草才能没马蹄。最爱湖东行不足，绿杨荫里白沙堤。”
来描述这里的景色。朝西南走过了锦带桥便是“平湖秋月”。东边则
是断桥。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"duanqiao",
	"southwest" : __DIR__"pinghu",
		 ])
	 );
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
