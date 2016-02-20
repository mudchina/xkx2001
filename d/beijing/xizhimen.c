//Cracked by Roath
// Room: /d/beijing/xizhimen.c

inherit ROOM;
string GATE_DESC_SHORT="西直门";
string GATE_DESC_LONG=@LONG
这是北京城西面的城门，一条大路通往山西，转至祈连山
乃至西域。这里的城墙建于明永乐年间，全部用砖包砌而成，
城门洞也为砖砌筒壳，十分坚固美观。门口有张告示(gaoshi).
LONG;

mapping GATE_EXITS=([
  "north" : __DIR__"tulu_xizhi_n",
  "south" : __DIR__"tulu_xizhi_s",
  "east" : __DIR__"xizhidajie",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":3,
]);

string GATE_ENTER_DIR="east";
#include "outer_gate.h"
