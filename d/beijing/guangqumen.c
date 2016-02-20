//Cracked by Roath
// Room: /d/beijing/guangqumen.c

inherit ROOM;

string GATE_DESC_SHORT="广渠门";
string GATE_DESC_LONG=@LONG
这是京城外城朝东向的城门。这里的城墙相比显得略微
破旧，守备也不如内城森严，但毕竟京畿重地，气度不凡；
过往的行人都在围看一张告示(gaoshi).
LONG;

mapping GATE_EXITS=([
  "west" : __DIR__"chongwendajie",
  "north" : __DIR__"tulu_guangqu_n",
  "south" : __DIR__"tulu_guangqu_s",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"
