//Cracked by Roath
// Room: /d/beijing/jingshan.c

inherit ROOM;

string GATE_DESC_SHORT="景山";
string GATE_DESC_LONG = @LONG
这是一条位于鼓楼西南面的背街，十分僻静冷落，路上几乎见不
到什麽行人，东北面鼓楼大街喧哗声不时传到这里来。街边有一间小
庙，上有几个大字『火神庙』。
LONG;
mapping GATE_EXITS = ([ /* sizeof() == 2 */
  "north" : __DIR__"dianmen",
  "east"  : __DIR__"chaoyangdajie",
  "west"  : __DIR__"huoshenmiao",
]);

mapping GATE_OBJECTS = ([
    __DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"
