//Cracked by Roath
// kaiyuan.c 开元寺
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "开元寺");
	set("long", @LONG
这是一座规模宏大的千年古刹，莲宫桂宇，焕彩流金，刺桐掩映，古榕垂
荫。游人未抵门前，远远可见两座石塔凌空而起，矗立于千楼万舍之上。它建
于唐武则天二年，全寺占地庞大，是福建最大的佛教建筑之一。寺外正面和西
面，环立白石栏杆，并植刺桐。大门开启，接纳着络绎不绝的虔诚香客。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"tianwang",
		"south" : __DIR__"citong_w2",
	]));

        set("objects", ([ 
		__DIR__"npc/guest" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
