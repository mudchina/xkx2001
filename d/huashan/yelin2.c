//Cracked by Roath
// 华山荒山野林２
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "荒山野林");
	set("long", @LONG
这是华山后山的一片荒山野林，四周都是一株株高巨无比的大树。大
树茂密的枝叶，互相交织着，是以阳光难以渗透，使人有不辨天日之感。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"yelin2",
  		"west" : __DIR__"yelin2",
		"south" : __DIR__"yelin2",
		"north" : __DIR__"yelin2",
	]));

	set("cost", 4);
        setup();
}

int valid_leave(object me, string dir)
{
	me->add_temp("marks/步", 1);
	me->add("jingli", -10);

	if ( me->query_temp("marks/步") == 3 ) {
	   set("exits/northeast", __DIR__"yelin2");
	   set("exits/northwest", __DIR__"yelin2");
	   set("exits/southeast", __DIR__"yelin2");
	   set("exits/southwest", __DIR__"yelin2");
	   delete("exits/east");
	   delete("exits/west");
	   delete("exits/north");
	   delete("exits/south");
	}
	else if( me->query_temp("marks/步") == 6 ) {
	  set("exits/west", __DIR__"yelin2");
	  set("exits/north", __DIR__"yelin2");
	  delete("exits/northeast");
	  delete("exits/southeast");
	}
	else if( me->query_temp("marks/步") == 9 ) {
	  set("exits/east", __DIR__"yelin2");
	  set("exits/south", __DIR__"yelin1");
          set("exits/northeast", __DIR__"yelin2");
          set("exits/southeast", __DIR__"yunu");
          set("exits/southwest", __DIR__"yelin1");
	  delete("exits/west");
	  delete("exits/north");
	  delete("exits/northwest");
	  write("你在荒山野林里乱走乱闯，却找不到出路，觉得很累。\n" );
	}
	else if( me->query_temp("marks/步") == 10 && dir == "southeast" ) {
	  write( "你几经艰难，终于走出了荒山野林。你感到十分疲惫，还是赶块休息吧。\n" ); 
	  me->delete_temp("marks/步");
          set("exits/east", __DIR__"yelin2");
          set("exits/west", __DIR__"yelin2");
          set("exits/south", __DIR__"yelin2");
          set("exits/north", __DIR__"yelin2");
	  delete("exits/northeast");
          delete("exits/southwest");
          delete("exits/southeast");
	}
	else if( me->query_temp("marks/步") == 10 && dir != "southeast" ) {
	  me->delete_temp("marks/步");
	  set("exits/east", __DIR__"yelin2");
	  set("exits/west", __DIR__"yelin2");
	  set("exits/south", __DIR__"yelin2");
	  set("exits/north", __DIR__"yelin2");
	  delete("exits/northeast");
	  delete("exits/southwest");
	  delete("exits/southeast");
	  write("你在荒山野林里乱走乱闯，却找不到出路，觉得很累。\n" );
	}
	else {
	  write("你在荒山野林里乱走乱闯，却找不到出路，觉得很累。\n" );
	}
	
	return 1;
}

void init()
{
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
        object obj, obj2, me = this_player();
        int i, amount;
        string item;

        if(!arg) return notify_fail("你要丢下什么东西？\n");

        if(!objectp(obj = present(arg, me)))
                return notify_fail("你身上没有这样东西。\n");

	message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")), me, obj );
	message_vision("一只猴子“嗖”地一声跑了过来，捡起"+(string)obj->name()+"便跑进密林不见啦。\n", me);
	destruct(obj);

	return 1;
}
