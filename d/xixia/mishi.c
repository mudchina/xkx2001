//Cracked by Roath
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这是一品堂的密室，平时只有堂主一个人可以进来。密室不大却陈
设豪华，地上铺着猩红的新疆纯羊毛手织地毯，四个角落里点着牛油巨
烛，一张宽大的软床放在屋中央，粉色的纱帐罩在床的上方。床边的矮
几上摆着的新疆的马奶子葡萄看上去晶莹剔透，靠墙有张大理石制的桌
子，一缕甜香从桌上的青铜香炉里飘了过来。
LONG
        );
        set("exits", ([
	"east" : __DIR__"dating" ,
        ]));
	create_door("east","木门","west",DOOR_CLOSED);
        set("objects", ([
                __DIR__"npc/yanqing" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
