//Cracked by Roath
// Room: /d/beijing/zhengyangmen.c

inherit ROOM;

string GATE_DESC_SHORT = "正阳门";
string GATE_DESC_LONG = @LONG
正阳门是京城内城九大城门中南三门之一。再往北就靠近紫禁
城了。往那里去的大都是军机要员，老百姓偶尔路过的都被严加查
问。门边上的告示 (gaoshi) 似乎写着些什么。
LONG;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "south" : __DIR__"zhengyangdajie",
  "north" : __DIR__"changanjie",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"

