//Cracked by Roath
// Room: /d/beijing/west/yonganmen.c

inherit ROOM;

string GATE_DESC_SHORT = "永安门";
string GATE_DESC_LONG = @LONG
这是京城南面的门户，从南方经天津上京的人们多从这里进城。
这里的守卫还是很严的，城门边上许多人正围着看告示 (gaoshi)，
两边的土路通向左安门和右安门。
LONG;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "east"  : __DIR__"tulu_yongan_e",
  "west"  : __DIR__"tulu_yongan_w",
  "north" : __DIR__"shizilukou",
  "south" : __DIR__"dadao_yongan_s",
]);

mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="north";
#include "outer_gate.h"
