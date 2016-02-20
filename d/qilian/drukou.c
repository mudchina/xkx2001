//Cracked by Roath
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "入口");
  set ("long", @LONG
从这里往上再走就进入敦煌石窟了，里面壁画、浮雕、藏经，
浩浩如海。在路旁有一座巨大的云石碑(shibei)。其碑高十三尺，
宽七尺一寸。
LONG);

  set("item_desc", ([ 
  "shibei" : "石碑两面都刻有字，阳面八十八行，每行五十字。阴面三十行，\n"
	     "每行四十八字。其字如奔马腾龙，骄夭不可方物，碑石墨黑若\n"
	     "玉，被称为灵石。\n"
]));
  set("outdoors", "/d/qilian");
  set("exits", ([ 
  "eastdown" : __DIR__"mingsha",
  "westup" : __DIR__"shiku",
]));
  replace_program(ROOM);
	set("cost", 2);
  setup();
}

