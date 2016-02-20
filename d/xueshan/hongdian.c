//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "红殿");
        set("long", @LONG
这里是大轮寺的红殿，殿内光线暗淡，壁上画像色暗。殿正中供
着密集金刚。金刚三面，戴宝冠，主面三睛，耳饰大环，上身裸，下
着长裙，结跏趺坐，六臂，两主臂拥明妃，其余两臂分张两侧各执法
器，明妃亦六臂，与金刚相向而拥，两腿盘腰後。金刚座(zuo)下有
石莲花、海石榴花、太平花和十字花。
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"zoulang",
        ]));
	set("item_desc", ([
		"zuo" :
	"金刚座高高在上。\n",
        ]) );

	set("cost", 1);
        setup();
}
void init()
{
        add_action("do_jump", "jump");
}


int do_jump(string arg)
{
	object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;
        if( arg=="zuo")
        {
                if (me->query_skill("dodge") < 30){
                    write("你试图跳上金刚座，无奈身法不够敏捷，只好做罢。\n");
		return 1;
		}
                else {
                    write("你纵身跃上了金刚座。\n");
                    message("vision",
                             me->name() + "一纵身跃上了金刚座。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"zuo");
                    message("vision",
                             me->name() + "从下面跃了上来。\n",
                             environment(me), ({me}) );
                return 1;
	 }
     }
}

int valid_leave(object me, string dir)
{
        return ::valid_leave(me, dir);
}
