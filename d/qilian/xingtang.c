//Cracked by Roath
// Summer 9/12/96
// Qfy 26/12/98
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "刑堂");
        set("long", @LONG
你刚进入这里，就觉得一股热浪迎面扑来，东面有一个两丈多高的火
炉，里面插着一些烧红的铁铲，铁钩，令人触目惊心，使人感到日月神教
的用刑之道确是博大精深。刑堂地上有个小门(door)通往牢房。
LONG
        );

        set("exits", ([
                "south" : __DIR__"houtin",
		"west" : __DIR__"jinqu",
        ]));

	set("objects", ([
            __DIR__"npc/rysj_guard" : 2,
        ]));

	set("cost", 1);
	setup();
}

void init()
{
	object *guard, me = this_player();
        int i, j;

        if ( interactive(me) ) {
                guard = all_inventory(environment(me));

                for ( i=0; i<sizeof(guard); i++ ) {
                        if ( guard[i]->query("id") == "rysj weishi" ) {
                                guard[i]->kill_ob(me);
                                j++;
                        }
                }

                if ( j ) message_vision("卫士大声对$N喝道：胆敢擅闯神教意图救人！纳命来！\n", me);
	}

	add_action("do_open", "open");
}

int do_open(string arg)
{
	object *guard, room, me=this_player();
	int i, j;

	if ( !arg || arg=="" ) return notify_fail("什么？\n");

	if ( !( room = find_object(__DIR__"dilao")) )
                room = load_object(__DIR__"dilao");

	if ( arg == "door" ) {
	   guard = all_inventory(environment(me));

           for ( i=0; i<sizeof(guard); i++ ) {
          	if ( guard[i]->query("id") == "rysj weishi" ) {
           	     	guard[i]->kill_ob(me);
                	j++;
                }
           }

	   if ( j ) {
		message_vision("卫士对着$N喝道：看招！别妄想在本大爷手下救人！\n", me);
		return 1;
	   }
	   else {
		message_vision("$N在墙上一阵抚摩，发现了机关枢钮。往下一按，牢门便自动开启了。\n", me);
		set("exits/down", __DIR__"dilao");
		room->set("exits/up", __DIR__"xingtang");
		message("info", "牢门缓缓地开启了．．．\n", room);
		remove_call_out("close_door");
		call_out("close_door", 10, room);
	   }
	}

	return 1;
}

int close_door(object room)
{
	object *rooms;

	rooms = ({ this_object(), room});

	delete("exits/down");
        room->delete("exits/up");
	message("info", "牢门又缓缓地自动关上了．．．\n", rooms);

	return 1;
}
	
/*
int valid_leave(object me, string dir)
{
	object room;

	if ( !( room = find_object(__DIR__"dilao")) )
                room = load_object(__DIR__"dilao");

        if( dir != "down" && ) {
		delete("exits/down");
		room->delete("exits/up");
        }

        return ::valid_leave(me, dir);
} 
*/
