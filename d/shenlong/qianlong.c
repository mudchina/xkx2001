//Cracked by Roath
//潜龙堂 /d/shenlong/qianlong
// ALN Sep 9 / 97

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "潜龙堂");
        set("long", @LONG
这是神龙教的潜龙堂，居中两张大竹椅，下面设了五张板凳，教主和五龙
使常在此商量密事，这儿非教主允许是不可以进入此地的。
LONG
        );

	set("exits", ([
                "out" : __DIR__"zhulin1",
        ]));
	set("cost", 1);

	set("objects", ([
                  "/kungfu/class/shenlong/hong" : 1,
                  "/kungfu/class/shenlong/su" : 1,
        ]));
        setup();
}

void init()
{
        object me = this_player();
        object *inv;

        if( !(me->query("family/family_name") == "神龙教" || me->query("sg/spy")) ) {
                inv = all_inventory(this_object());
                for(int i = 0; i < sizeof(inv); i++ )
                        if( (inv[i]->query("family/family_name") == "神龙教" || inv[i]->query("sg/spy")) && living(inv[i]) )
                                inv[i]->kill_ob(me);
                me->start_busy(1);
        }
}
