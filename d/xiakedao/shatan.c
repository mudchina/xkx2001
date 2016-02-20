//Cracked by Roath
// Copy from  /d/shaolin/hanshui1.c
// Date: Long /8/1/97
// modified by  aln  5 / 98

inherit __DIR__"no_pk_room";

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();

void create()
{
    set("short", "沙滩");
    set("long", @LONG
蓝蓝的大海一望无边。岸边不远处停着几只小船，细细的白沙，
踩在脚下软软的好不舒服。不时有几只小蟹横行而过。一排浅浅的足
迹指向北边。一个渔夫打扮的人正对着你微笑。
LONG
    );

    set("exits", ([
		   "east" : __DIR__"shatans2",
		   "north" : __DIR__"xiaolu",
		   "northwest": __DIR__"haibian3",
    ]));
    set("objects", ([ 
		     __DIR__ +"npc/yufu" : 1, 
    ]));
    set("no_fight", "1");
    set("outdoors", "xiakedao");
    setup();
}

void init()
{
        object me = this_player();

        ::init();

        me->set("xkd/set", 1);
//        if ((int)me->query_temp("marks/离") > 0)
//		  {       call_out("check_trigger", 1);
//        }
		call_out("check_trigger", 1);
}

void check_trigger()
{
	 object room;

	 if(!query("exits/enter") ) {
		  if( !(room = find_object(__DIR__"chuan")) )
				room = load_object(__DIR__"chuan");
		  if( room = find_object(__DIR__"chuan") ) {
				if((int)room->query("yell_trigger")==0 ) {
					 room->set("yell_trigger", 1);
					 set("exits/enter", __DIR__"chuan");
					 room->set("exits/out", __FILE__);
					 message("vision", "渔夫招了招手一条小船驶了过来\n", this_object());
					 message("vision", "船慢慢地靠向了岸边。\n", room);
					 remove_call_out("on_board");
					 call_out("on_board", 15);
				}
				else
					 message("vision", "渔夫抱歉地说道：船都出海了，你待会儿再来吧。\n",this_object() );
		  }
		  else
				message("vision", "ERROR: boat not found\n", this_object() );
	 }
	 else
		  message("vision", "渔夫说道：船正等着你呢，上去吧。\n", this_object() );
}

void on_board()
{
	 object room;

	 if( !query("exits/enter") ) return;

	 message("vision", "船慢慢地向海上驶去。\n",
		  this_object() );

	 if( room = find_object(__DIR__"chuan") )
	 {
		  room->delete("exits/out");
		  message("vision", "船身微微一动，离岸向海上驶去。\n", room );
	 }
	 delete("exits/enter");

	 remove_call_out("arrive");
	 call_out("arrive", 20);
}

void arrive()
{
	 object room;
	 if( room = find_object(__DIR__"chuan") )
	 {
		  room->set("exits/out", __DIR__"shatan3");
		  message("vision", "船身微微一震，船靠岸了。\n",room );
	 }
	 remove_call_out("close_passage");
	 call_out("close_passage", 20);
}

void close_passage()
{
	 object room;
    if( room = find_object(__DIR__"chuan") ) {
        room->delete("exits/out");
        message("vision","船慢慢地离岸，驶向海上。\n", room);
        room->delete("yell_trigger"); 
    }
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"chuan") )
        room->delete("yell_trigger"); 
}
int valid_leave(object me, string dir)
{
	object *iv;
	int i;

//        if ( (! me->query_temp("marks/离") ) && (dir =="enter"))
//					 return notify_fail("渔夫把手一拦说道：没有岛主同意，你不可离岛。\n");

	iv = all_inventory(me);

		  if ( dir == "enter") {
					 for (i=0; i<sizeof(iv); i++) {
								if (iv[i]->is_character())
		return notify_fail("你不能带着其他玩家离开侠客岛。\n");
					 }
	}
		  return ::valid_leave(me, dir);
}


