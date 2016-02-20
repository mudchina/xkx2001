//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大堂");
        set("long", @LONG
你所在的是一个金壁辉煌的大厅，这是日月神教议事的场所。
地上铺着红色地毯，墙壁上挂着一个大匾，上面写着三个金色的大
字“日月神教”，正前方立着一面屏风，上绘一条巨龙，通体黑色，
张牙舞爪似欲扑出。
LONG
        );
        set("exits", ([
                "south" : __DIR__"neiyuan",
                "north" : __DIR__"houtin",
        ]));

	set("objects", ([
            __DIR__"npc/rysj_guard" : 2,
        ]));

	set("cost", 1);
	setup();
}

void init()
{
	object *guard, me = this_player();
	int i, j;

	if ( interactive(me) ) {
		guard = all_inventory(environment(me));

                for ( i=0; i<sizeof(guard); i++ ) {
                        if ( guard[i]->query("id") == "rysj weishi" ) {
                                guard[i]->kill_ob(me);
				j++;
			}
                }

		if ( j ) message_vision("卫士大声对$N喝道：来者何人？胆敢私闯神教分舵！纳命来！\n", me);
	}
}
	

int valid_leave(object me, string dir)
{
        object room, *guard;
	int i, j;

        if( dir == "north"  ) {
		guard = all_inventory(environment(me));

		for ( i=0; i<sizeof(guard); i++ ) {
			if ( guard[i]->query("id") == "rysj weishi" ) {
				guard[i]->kill_ob(me);
				j++;
			}
		}

		if ( j ) return notify_fail("卫士对你喝道：看招！别妄想闯入本教重地！\n");
        }

        return ::valid_leave(me, dir);
} 
