//Cracked by Kafei
// road: /zhongnan/houtang.c

inherit ROOM;
#include <ansi.h>
void create()
{
		  set("short","後堂");

		  set("long",@LONG
这里就是後堂了。只见堂上空空荡荡的没什麽陈设。几张椅子靠着墙
放着。一些女弟子正坐在那ㄦ聊天。在东西两壁上各挂着一幅画(hua1)(hua2)。
往北是一个通往大厅的小门。
LONG);

		  set("item_desc",(["hua1" : "
西壁画中是两个姑娘。一个二十五六岁，正在对镜梳装。另一个是十
四五岁的丫鬟，手捧面盆，在旁侍候。画中镜里那年长女郎容貌极美，秀
眉入鬓，眼角之间却隐隐带着一层杀气。
				\n",
									"hua2" : "
东壁画中是一个身材甚高的中年道人。只见他腰悬长剑，右手食指指着东
北角，只是背脊向外，面貌却看不见。
				\n",
								  ]));

		  set("exits",([ "north" : __DIR__"dating",

							 ])
			  );
                set("objects",([
//                "/kungfu/class/gumu/longnu" : 1
                ]));
	  set("cost",1);

	  setup();
}

void init()
{
         add_action("do_ketou", "ketou"); 
         add_action("do_tuo", "tuo");
         add_action("do_tuo", "tu");
         add_action("do_tuo", "pei");
}

int do_ketou(string arg)
{
          mapping fam;
          object me = this_player();
        if ((!arg) || (arg != "hua1")) return 0;
          message_vision("$N向西跪倒，双膝及地，恭恭敬敬向祖师婆婆的画像磕了一个响头. \n", me);
          me->add_temp("marks/ketou", 1);
        if (me->query_temp("marks/tuo") == 2 && me->query_temp("marks/ketou") == 4
          && (!(fam = me->query("family")) || fam["family_name"] != "古墓派") && me->query("combat_exp") < 10000){
          me->set("family_name", "古墓派");
          me->set("title", "古墓传人");
          me->create_family("古墓派", 5, "传人");
          me->set("class","swordsman");
          write(HIR"恭喜你自愿成为一名古墓弟子。\n"NOR);
          me->delete_temp("marks/tuo");
          me->delete_temp("marks/ketou");
          return 1;
          }
}

int do_tuo(string arg)
{
           object me = this_player();
           if (me->query_temp("marks/tuo") == 2)
             return notify_fail("你唾够了没有？\n");
           if ( arg=="hua2"){
           message_vision("$N朝王重阳的画像狠狠唾了一口. \n", me);
           me->add_temp("marks/tuo", 1);
           return 1;
           }
          return notify_fail("你不要随便乱唾口水！\n");
}
