//Cracked by Roath
#include <room.h>

inherit ROOM;
void create()
{
       set("short","战船");
       set("long", @LONG
这是辽阔的海面，海风「呼呼」在你耳边吹过，海浪一个接着一个向你
泼打过来，突然一个巨浪打来几乎把你所乘的船掀翻。 
LONG
     );

	set("invalid_startroom", 1);
	set("cost", 5);
        set("outdoors", "quanzhou");
        setup();
}

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

