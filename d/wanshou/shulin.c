//Cracked by Roath
// /d/wanshou/shulin.c
// snowbird July 1999
// 1.1.1.1

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这是万兽山庄所驯养的野兽栖息的林子。往南便是山庄驯兽场，
北面通向山庄后面的峭壁。
LONG
        );
        set("exits", ([
		        "north" : __DIR__"juebi",
				"south" : __DIR__"xunshouchang",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();

}

void init()
{
        add_action("do_howl", "howl");
}

int do_howl(string arg) 
{
   object me = this_player();
   object animal, *animals;
   object here = environment(me);
   string file = "/u/snowbird/wanshou/npc/animal2";
   int i, num;

   animals = filter_array(children(file), (: clonep :));

   num = sizeof(animals);

   if (num > 0) {
       for (i=0; i<num; i++) {
		  if(animals[i]->query_lord() == me)
              return notify_fail("你纵声长啸，等了好一会儿，树林里依旧静悄悄的毫无动静。\n");

       }
   }
   animal=new(file);
   animal->animal_special_init(me);
   message_vision(HIG"$N呼啸一声，一只$n从树林深处窜了出来，乖乖地伏在$N的脚边。\n"NOR, me, animal);
   animal->move(here);

   return 1;
}
