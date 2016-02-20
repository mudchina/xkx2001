//Cracked by Roath
// xiakedao/dadong.c
// modified by aln 5 / 98
// modified by sdong to forbid bringing laba zhou out, 6/99
// Modified by xQin to forbid players return to xkd to ask laba zhou 7/00

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "大山洞");
        set("long", @LONG
眼前豁然开阔，宽大的山洞中整整齐齐摆放了一百多张桌子，周
围遍插牛油蜡烛。数名黄衣厮仆穿梭来去，引导客人入座。大洞西侧
空着两张巨大的石椅。下首主位後有两块大屏风，上面是巨幅的写意
山水，气势恢弘。
LONG );

      set("exits", ([
      	"south" : __DIR__"yongdao3",
//	"enter" : __DIR__"yongdao10", 
      ]));

	set("cost", 0);
	set("objects", ([ 
	    __DIR__ + "npc/sipu" : 1,
      ]));
	set("food_count", 5);
	set_temp("opened", 0);
    //call_other("/clone/board/xkd_b", "???");
	setup();
    "/clone/board/xkd_b"->foo();
    "/clone/board/xkd_b"->save();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object *inv;
        int found, i;
        
        myfam = (mapping)me->query("family");


		  inv = all_inventory(me);
		  for (i=0; i<sizeof(inv); i++) {
					 if ( inv[i]->is_container() && present("zhou", inv[i]) )  found = 1;
		  }

		  if ( present("zhou", me) || found )
					 return notify_fail("快把腊八粥吃下再出去！\n");

		  return ::valid_leave(me, dir);
}
void init()
{
        object me = this_player();

        if ((me->query("combat_exp") > 10000) && (wizhood(me) == "(player)"))
	{	
	message_vision(" 岛主吩咐，你和侠客岛缘份以尽，待老奴再送你一程。\n", me);
	message_vision("$N不由自主的被厮仆拉著，转眼间便来到大车跟前。\n", this_player());
	message_vision("厮仆拱了拱手说道：“保重，后会无期！”\n",me); 
	me->move("/d/xiakedao/shatan3");


}
}