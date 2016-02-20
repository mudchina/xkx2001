//Cracked by Roath
// /d/shenlong/ship.c
// ywz 09/18/96
#include <room.h>

inherit ROOM;
void create()
{
       set("short","海船");
       set("long", @LONG
这是辽阔的海面，海风「呼呼」在你耳边吹过，海浪一个接着一个向你泼打
过来，突然一个巨浪打来几乎把你所乘的船掀翻。你快要陷入这个旋涡中了，
还是催促渔夫赶紧摇船走出着鬼地方吧。
LONG
     );
	set("cost", 5);

//	set("exits", ([
//		"east" : __FILE__,
//		"west" : __DIR__"dahai2",
//		"south" : __DIR__"dahai3",
//		"north" : __DIR__"dahai4",
//	]));
        setup();

}

/*
int valid_leave(object me, string dir)
{
        if ( dir == "west")
            me->add_temp("mark/steps",1);
        if ( dir == "east")
            me->add_temp("mark/steps",-1);
	if ( dir == "north")
	    me->add_temp("mark/nsteps",1);

        if (me->query_temp("mark/steps") == 10)
         {
	    me->move("/d/shenlong/tanggukou");
            me->delete_temp("mark/steps");
	     return notify_fail("终于你看见了前方的陆地，啊，谢天谢地 ！\n");
         }

     if (me->query_temp("mark/steps") == -10)
            {
	       me->move("/d/shenlong/haian");
           me->delete_temp("mark/steps");
	     return notify_fail("终于你看见了前方的陆地，啊，谢天谢地 ！\n");
	}

      if (me->query_temp("mark/nsteps") == 10)
         {
	    me->move("/d/shenlong/lushunkou");
	    me->delete_temp("mark/nsteps");
	     return notify_fail("终于你看见了前方的陆地，啊，谢天谢地 ！\n");
         }


        return ::valid_leave(me,dir);
}

void init()
{
	object me = this_player();

	if( interactive(me = this_player()) )
	{
	    remove_call_out("arrive");
	    call_out("arrive", 10);
	}

}

void arrive()
{
	message("vision", "渔夫说：“大陆到啦，上岸吧”。\n",this_player());
	this_player()->move("/d/shenlong/tanggu");
}
*/

int valid_leave(object me, string dir)
{
        object room;

        if ( !::valid_leave(me, dir) )
                return 0;

        if(!(room = find_object(__FILE__)) )
                room = load_object(__FILE__);
        if(objectp(room))
        {
                room->add_temp("person_inside", -1);
                if ((int)room->add_temp("person_inside", -1) <= 0)
                        room->delete_temp("person_inside");
        }

        return 1;
}

