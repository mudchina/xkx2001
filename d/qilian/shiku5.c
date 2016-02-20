//Cracked by Roath
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "石窟");
  set ("long", @LONG
这一窟的浮雕和彩塑。人物面象丰满、鼻梁高隆直通额季、眉长
眼鼓、肩宽胸平。佛象所穿大红僧衣，有薄纱透体的感觉，俗称"曹衣
出水"。塑向体态健美、神情庄重、色彩明快、造形厚重、手法简普。
LONG);

  set("exits", ([ 
  "west" : __DIR__"dtongdao2",
]));
  set("objects", ([
                "/d/emei/obj/yugajing0" : 1,
                "/d/qilian/obj/fojing1" : 1,
                "/d/shaolin/obj/fojing10" : 1,
        ]));

	set("cost", 2);
  setup();
  replace_program(ROOM);
}

