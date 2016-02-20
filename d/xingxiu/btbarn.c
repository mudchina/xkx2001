//Cracked by Roath
// room: /d/xingxiu/btbarn
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "蛇舍");
        set("long", @LONG
这是白驼山庄的蛇舍。屋里到处是毒蛇，墙上有一张「蛇经」(shejing)。
LONG
        );
        set("exits", ([ 
	    "south" : __DIR__"btyard",
        ]));
	set("item_desc", ([
		"shejing" : "白驼山训蛇密法：可将毒蛇变(bian)成蛇杖，\n"
			"用蛇杖击人可使其中毒。也可以把蛇杖变回毒蛇，用以害人。\n"
			"三十级以上驭兽术可做此事，越高成功率越高。\n",
	]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 3,
         ]) );
//        replace_program(ROOM);
	set("cost", 0);
        setup();
}


void init()
{
   add_action("do_lingwu","lingwu");
}
                
int do_lingwu(string arg)                
{
   object me = this_player();
   int level, check;

   if (!arg || arg!="shejing") {
        write("你要领悟什么？\n");
        return 1;
   }
   level = (int)me->query_skill("poison",1);
   check = level*level*level;
   
   if (!me->query("family") || me->query("family/family_name") != "白驼山") {
	write("你是未入白驼，难悟白驼经。\n");
        return 1;
   }

   if ( level < 30) {
        write("经中所言对你过于高深，你无法领悟。\n");
        return 1;
   }
   if ( level > 100) {
        write("经中所言对你太浅，没有任何帮助。\n");
        return 1;
   }
   if (check > (int)me->query("combat_exp")*10 ) {
        write("你实战经验不足，无法领悟。\n");
        return 1;
   }
   if ( (int)me->query("jing") < 30 ) {
      write("你精神无法集中。\n");
        return 1;
   }
   me->receive_damage("jing", 20);
   me->improve_skill("poison", me->query("int"));
   write("你钻研蛇经，领悟了施毒的法门。\n");
   return 1;
}

