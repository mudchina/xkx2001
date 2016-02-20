//Cracked by Roath
#include "room.h"
inherit ROOM;
void create()
{
  set ("short", "鸣沙山");
  set ("long", @LONG
鸣沙山实际上并不是一座山，而是由源于祈连山脉的赤河带来的
碎石泥沙所堆积而成的一座小沙丘。微风吹动，沙山发出嗡嗡的响声。
故而当地人称之为鸣沙山。沙土中似乎有一种虫子在蠕动。在夕阳下
抬头西望，只见对面三危山(mountain)顶上金光四射。据说当年乐尊
大师就是仰望此景而发下宏愿，在鸣沙山西壁断层上开凿了第一个石
窟。
LONG);

  set("item_desc", ([ 
  "mountain" : "三危山是剥蚀残山，山上无草木，山石红褐，内含石英、云母，\n"
               "太阳反射，灿烂照出金光。\n",
]));
  set("outdoors", "/d/qilian");
  set("exits", ([ 
  "east" : __DIR__"sulew",
  "westup" : __DIR__"drukou",
]));
  set("objects", ([
               "/d/xingxiu/npc/shachong" : 1 ]));
	set("cost", 3);
  setup();
  replace_program(ROOM);
}

