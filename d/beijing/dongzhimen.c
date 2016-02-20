//Cracked by Roath
// Room: /d/beijing/dongzhimen.c

inherit ROOM;

string GATE_DESC_SHORT = "东直门";
string GATE_DESC_LONG = @LONG
这是京城东北的一座城门，门口挂这一张告示 (gaoshi)。
这里往南就是朝阳门，进城的东直门大街直通鼓楼。
LONG;

mapping GATE_EXITS=([ /* sizeof() == 2 */
  "west" : __DIR__"dongzhidajie",
  "north" : __DIR__"tulu_dongzhi_n",
  "south" : __DIR__"tulu_dongzhi_s",
]);

mapping GATE_OBJECTS=([
   __DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"
