//Cracked by Roath
// Room: /d/beijing/andingmen.c

inherit ROOM;
string GATE_DESC_SHORT="安定门";
string GATE_DESC_LONG=@LONG
这是京城正北的安定门。西边是得胜门，南边是去鼓楼的大道。
这里远离闹市，只有些乡农来往运菜进京。城门口的告示(gaoshi)
似乎也没什么人看。
LONG;
mapping GATE_EXITS=([ /* sizeof() == 2 */
  	"south" : __DIR__"zhonglou",
  	"west"  : __DIR__"tulu_anding_w",
        "east"  : __DIR__"tulu_anding_e",
	]);
mapping GATE_OBJECTS=([
    __DIR__"npc/bj_bing":3,
]);

string GATE_ENTER_DIR="south";

#include "outer_gate.h"
