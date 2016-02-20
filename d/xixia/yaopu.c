//Cracked by Roath
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "药铺");
        set("long", @LONG
这是一家神秘的药铺，座落在西大街和南大街的交界处，普通的
门面和招牌，街坊们都说这家药铺的药灵验的很。从药柜上的几百个
小抽屉里散发出来的一股浓浓的药味, 让你几欲窒息。老板坐在柜台
旁，独自算算着账，看也不看你一眼。一个小姑娘在柜台后默默地加
工着新采集来的药材。据说这家店铺有一种很神密的药物。
LONG
        );
        set("exits", ([
        ]));


        setup();
        replace_program(ROOM);
}
