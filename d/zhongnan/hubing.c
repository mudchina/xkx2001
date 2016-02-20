//Cracked by Roath
// road: /zhongnan/hubing.c
// by sdong 08/98

#include <ansi.h>
inherit ROOM;

int do_jump();

void create()
{
		  set("short",HIC"太乙池湖滨"NOR);
		  set("long",@LONG
这里就是太乙池(chi)西岸的湖滨，背山靠水，四处绿草如茵，鲜花盛开，几只蝴蝶正
翩翩起舞，还有不少水鸟，叽叽喳喳飞来飞去。往池中望去，池面碧波荡漾，山光水影，
风景十分优美。西边是一座陡峭的山峰，半山腰上可以望见一个巨大的山洞，由两大花岗
岩夹峙而成。往西有一条陡峭的小路通往山上。
LONG);

		  set("exits",([
							  "westup" : __DIR__"shanlu16",
							 ])
			  );


		  set("item_desc", ([
		"chi" :
"\n\n这是一个很大的山间湖，碧波荡漾，湖水清澈见底，让人忍不住想跳(jump)下去\n"
"畅游一番。\n\n\n",
])  ) ;

		  set("no_clean_up", 0);

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump()
{
	object me = this_player();

	if ( me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	message_vision(HIY"\n$N往太乙池中跳去。\n"NOR, me);
	me->set_temp("taiyi_swimming", 1);
	me->move("/d/zhongnan/taiyici3");
	message_vision(HIY"\n$N往太乙池中跳了进来。\n"NOR, me);

	return 1;
}
