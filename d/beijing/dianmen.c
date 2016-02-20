//Cracked by Roath
// Room: /d/beijing/dianmen.c

inherit ROOM;

string GATE_DESC_SHORT = "地安门";
string GATE_DESC_LONG = @LONG
地安门是皇城的后门，与皇城正面的天安门遥遥相对，虽
不如天安门气势恢宏，但红墙高耸，黄色琉璃瓦闪闪发光，富
丽堂皇，威严肃穆兼而有之。再往南就是紫禁城了. 
LONG;

mapping GATE_EXITS = ([
  "south" : __DIR__"jingshan",
  "north" : __DIR__"gulou",
]);

mapping GATE_OBJECTS = ([
__DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"
