//Cracked by Roath
// /d/xingxiu/mogaoku.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "石窟");
        set("long", @LONG
这里墙壁上绘制着与佛教相关的画面，有仙女飞天，反弹琵琶，和罗汉
伏虎图(tu)。你被这些瑰丽的文化之宝惊呆了。
LONG
        );
        set("exits", ([ 
             "out" : "/d/qilian/yueerquan",
	     "east" : "/d/qilian/dtongdao5",
	]));
	set("item_desc", ([
		"tu" : "图上绘着一个罗汉左手持杵，右手按住一只斑斓猛虎。\n",
	]));

	set("cost", 1);
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

   if (!arg || arg!="tu") {
	write("你要领悟什么？\n");
	return 1;
   }
   level = (int)me->query_skill("training",1);
   check = level*level*level;
   
   if ( level < 30) {
	write("图上所绘对你过于高深，你无法领悟。\n");
        return 1;
   }
   if ( level > 100) {
        write("图上所绘对你太浅，没有任何帮助。\n");
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
   me->improve_skill("training", me->query("int"));
   write("你比划着图中罗汉的样子，领悟了驭兽术的精髓。\n");
   return 1;
}


