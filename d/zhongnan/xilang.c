//Cracked by Roath
// xilang.c 西厢走廊
// by Sdong 07/98

inherit ROOM;

void create()
{
        set("short", "西厢走廊");
        set("long", @LONG
你走在一条走廊上，东边是广宁殿，西边有一座丹房，丹房有一扇门
(men)，可是却紧闭着。
LONG
        );

        set("item_desc", ([
                "men" : "这扇门后便是丹房。\n",
        ]));

        set("exits", ([
					 "east" : __DIR__"disan",
                "north": __DIR__"c_xilang",
		  ]));

			set("objects", ([
				 __DIR__"npc/wang-zj" : 1,
			 ]));

        set("cost", 1);
        setup();
}

void init()
{
        add_action("do_unlock", "unlock");
        if (present("li zhichang", environment(this_player())))
                delete("exits/west");
}


int do_unlock(string arg)
{
		  object ob;
		  object room;

		  if (query("exits/west"))
					 return notify_fail("这扇门已经是打开的。\n");
		  if (!arg || (arg != "men" && arg != "west"))
					 return notify_fail("你要打开什么？\n");
		  if (!(ob = present("danfang key", this_player())))
					 return notify_fail("你不会撬锁。\n");
		  set("exits/west", __DIR__"danfang1");
		  message_vision("$N用一把钥匙打开房门。\n", this_player());

		  if(!( room = find_object(__DIR__"danfang1")) )
					 room = load_object(__DIR__"danfang1");
		  if(objectp(room))
		  {
					 room->set("exits/east", __FILE__);
					 message("vision", "吱地一声，外面有人把大门打开了。\n", room);
					 remove_call_out("close_door");
					 call_out("close_door", 10);
		  }

		  return 1;
}

void close_door()
{
		  object room;

		  if(!( room = find_object(__DIR__"danfang1")) )
					 room = load_object(__DIR__"danfang1");
		  if(objectp(room))
		  {
					 delete("exits/west");
								message("vision", "大门慢慢地自动关上了。\n", this_object());
					 room->delete("exits/east");
					 message("vision", "大门慢慢地自动关上了。\n", room);
		  }
}


