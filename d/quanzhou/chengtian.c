//Cracked by Roath
// chengtian.c 承天寺
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "承天寺");
	set("long", @LONG
这是泉州市民祭天求安的寺庙，以保佑年年得以五谷丰登，风调雨顺。寺
内广场中央有一法坛。承天寺西方通往刺桐南路。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"gtxiang",
		"west" : __DIR__"citong_s2",
	]));

	set("objects", ([ 
                __DIR__"npc/monk" : 1,
	]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
}
