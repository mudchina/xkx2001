//Cracked by Roath
// xiakedao/shanlu3.c
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "山路");
        set("long", @LONG
小路曲曲折折地通向山顶，脚步声惊起一群飞鸟，扑簌簌地消失
在空中。空气中却有些腥气，路边草丛 (grass)间不时传来沙沙的轻
响，可能是毒蛇，还是快点离开的好。
LONG );

      set("exits", ([
		     "eastup" : __DIR__"shanding",
		     "westdown"  : __DIR__"xiaolu2",
      ]));
	set("item_desc",([
	    "grass" : "乱草丛中长着几朵不起眼的小花。\n",
	]));
	set("objects", ([ 
            "/d/city/npc/maque.c" : 3,
          "/d/city/obj/branch3" : 1,
          "/d/city/obj/branch4" : 1,
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	setup();
}

void init()
{
        ::init();

	add_action("do_push", "push");
}

int do_push(string arg)
{
	object snake, me = this_player();

	if ( !arg )
		return notify_fail("你要推什么？\n");

	if ( arg != "grass" )
		return notify_fail("什麽？\n");

	if (present("snake",environment(me)))
                return notify_fail("老蛇要咬死你了，你还有闲情玩？块跑吧。\n");

        if( objectp(query("mysnake")) )
                return notify_fail( "你四处拔弄了一下，结果什么都没发现。\n");

	message_vision("$N拨开杂草，惊醒了一只毒蛇。快离开吧。\n", me);
	snake = new("/clone/beast/snake.c");
	snake->move(this_object());
        set("mysnake", snake);

        remove_call_out("do_destroy");
        call_out("do_destroy", 20, snake);
	return 1;
}

void do_destroy(object snake)
{
        if( !snake ) return;

        if( snake->is_fighting() || snake->is_busy() || !living(snake) ) {
                call_out("do_destroy", 20, snake);
                return;
        }

        message_vision("$N飞快地游走了。\n", snake);
        destruct(snake);
        delete("mysnake");
}
