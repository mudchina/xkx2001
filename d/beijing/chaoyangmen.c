//Cracked by Roath
// Room: /d/beijing/zhaoyangmen.c

inherit ROOM;

string GATE_DESC_SHORT="朝阳门";
string GATE_DESC_LONG=@LONG
这是京城东向的朝阳门。城墙建于明永乐年间，全部用
砖包砌而成，城门洞也为砖砌筒壳，十分坚固美观。出门往
东是通往东北的大道。门口有一张告示(gaoshi).
LONG;

mapping GATE_EXITS=([
  // "east": __DIR__"yidao3",
  "west" : __DIR__"chaoyangdajie",
  "north": __DIR__"tulu_chaoyang_n",
  "south": __DIR__"tulu_chaoyang_s",
]);

mapping GATE_OBJECTS=([
    __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"
