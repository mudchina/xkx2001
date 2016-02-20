//Cracked by Roath
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "城隍庙");
        set("long", @LONG
城隍庙里的人群熙熙攘攘，摩肩接踵，这是城里最热闹的地方。
除了来拜祭土地爷爷还神请愿的，还有很多小孩贪城隍庙的小吃好吃，
拉着大人来的，有些姑娘小伙儿也趁着去城隍庙，多了一个相互多看
一眼的机会。但看庙门口的空地上，族拥着很多卖麦芽糖的、卖各种
小吃的、卖各种小杂碎的、打把式卖艺的，真是热闹。东西是厢房，
南面是庙前空地。
LONG
        );
        set("exits", ([
        ]));


        setup();
        set("outdoors","xixia");
        replace_program(ROOM);
}
