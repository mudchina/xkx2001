//Cracked by Roath
// road: /zhongnan/laoqurock.c
// sdong 08/98

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","老妪岩");

        set("long",@LONG
一路过来，山路是越来越险。只见一块大岩石挡在路中，自空凭临，
宛似一个老妇弯腰俯视，但形状阴森可怖，令人望而生畏。不少游客在
此驻足观看，往南是一片茂密的松林。往北上是一条陡峭的山路。
LONG);

        set("exits",([ "southdown" : __DIR__"shulin3",
                        "northup" : __DIR__"shanlu5",
                      ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}


void init()
{
		  object ob = this_player(), robber, *inv;
		  int i, j=0;

		  if ( interactive(ob) &&  ob->query("family/family_name")=="全真教" && random(15)==1 &&
				  (
					present("chuanbei", ob) ||
					present("fuling", ob) ||
					present("gouzhi zi", ob) ||
					present("heshouwu", ob) ||
					present("huanglian", ob) ||
					present("jugeng", ob) ||
					present("jinyin hua", ob) ||
					present("shengdi", ob)
					)
			)
			{
					 message_vision(HIR"只听得一阵风响，一个毛贼自草堆里钻了出来拦住$N。\n"NOR, ob);
					 robber = new(__DIR__"npc/maozei");
					 robber->move(environment(ob));
					 ob->set_temp("herb_victim", 1);
					 return;
			}

		  inv = all_inventory(ob);

		  for (i=0; i<sizeof(inv); i++) {
					 if (inv[i]->query("value") >= 10000
					 && !inv[i]->query("money_id")) j++;
		  }
		  if (j>0) ob->set_temp("rob_victim", 1);

		  if ( interactive(ob) && ob->query_temp("biao/ma")
		  && present("hong biao", ob) && random(5)==1 || j>0 && random(30) ==0
			) {
					 message_vision(HIR"只听得一阵拨草声，一个草寇自草堆里钻了出来拦住$N。\n"NOR, ob);
					 robber = new("/d/village/npc/caokou");
					 robber->move(environment(ob));
					 return;
		  }
}

int valid_leave(object me, string dir)
{
	 object maozei = present("mao zei");
	 object caokou = present("cao kou");
	 if( maozei && ( me->query("id") == maozei->query_temp("victim") )) // me->query_temp("herb_victim",1)==1 &&
	 {
		 if ( dir != "northup" )
		 {
			  return ::valid_leave(me, dir);
		 }
		 message_vision(HIR"$N被挡住了去路。\n"NOR, me);
		 return notify_fail("毛贼喝道：想溜？没门！\n");
	}


	 if( me->query_temp("rob_victim", 1)==1 && caokou && ( me->query("id") == caokou->query_temp("victim") ) )
	 {
		 message_vision(HIR"$N被草寇挡住了去路。\n"NOR, me);
		 return notify_fail("草寇喝道：想溜？没门！\n");
	 }

	 return 1;

}
