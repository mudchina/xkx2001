//Cracked by Roath
// Room: /d/beijing/guanganmen.c

inherit ROOM;
string GATE_DESC_SHORT="广安门";
string GATE_DESC_LONG=@LONG
这是京城西边的城门之一。由于不是很繁华，这里的城墙已经
有些不那么光鲜了。绕城的土路也没有许多人来往。西面远处听说
时常有强人出没。门边的告示 (gaoshi) 也已经有些褪色。
LONG;

mapping GATE_EXITS=([
  "south" : __DIR__"tulu_guangan_s",
  "east"  : __DIR__"caishikou",
  "north" : __DIR__"tulu_guangan_n",
]);

mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="east";
#include "outer_gate.h"
