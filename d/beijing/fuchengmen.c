//Cracked by Roath
// Room: /d/beijing/fuchengmen.c
inherit ROOM;

string GATE_DESC_SHORT="阜成门";

string GATE_DESC_LONG=@LONG
这是京城西面的阜成门。城墙建于明永乐年间，
全部用砖包砌而成，城门洞也为砖砌筒壳，十分坚
固美观。门口有张告示(gaoshi)。
LONG;

mapping GATE_EXITS=([
  "north" : __DIR__"tulu_fucheng_n",
  "south" : __DIR__"tulu_fucheng_s",
  "east"  : __DIR__"fuchengdajie",
]);

 
mapping GATE_OBJECTS=([
        __DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="east";
// all the real definitions goes here
#include "outer_gate.h"
