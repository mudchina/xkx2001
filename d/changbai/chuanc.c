//Cracked by Roath
// Room: chuanc.c

inherit ROOM;

#include <localtime.h>

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();

void create()
{
	set("short", "船厂");
	set("long", @LONG
这里是古镇船厂。船厂是位于关外大平原中部的一个古老的小镇，此镇
西、南、北、三面是以高墙垒筑，利于坚守。东面临松花江天成东险，乃兵
家必争的要地。松花江在冬春时结冰可通行，夏秋化冻你只好找船家帮忙了。
LONG	);

	set("exits", ([ 
              "south" : __DIR__"xuedi3",
              "east" : __DIR__"damk",
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
}

void init()
{
        add_action("do_yell", "yell");
}

int valid_leave(object me, string dir)
{
        mixed *local;
        object *ob;
        int i;

        if( dir == "east" ) {
                local = localtime(time()*60);
                if( local[LT_MON] > 3 && local[LT_MON] < 10 )
                        return notify_fail("松花江化冻了，你喊(yell)条船过江吧。
\n");
                else {
                        ob = all_inventory(environment(me));
                        for(i=0; i<sizeof(ob); i++){
                                if( ob[i]->query("rider") == me )
                                        ob[i]->move(__DIR__"bingmian");
                        me->set_temp("new_valid_dest", __DIR__"bingmian");
                        tell_object(me, "你见江面结冻，便壮起胆子踩冰而过。\n");
                        }                 
                        return 1;
                }
        }

        return ::valid_leave(me, dir);
}

int do_yell(string arg)
{
        mixed *local;
        string dir;

        local = localtime(time()*60);
        if( !(local[LT_MON] > 3 && local[LT_MON] < 10) ) 
                return 0;       

        if( !arg || arg=="" ) return 0;

        if( (int)this_player()->query("age") < 16 )
                message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", this_player());
        else if( (int)this_player()->query("neili") > 500 )
                message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远传"
                "了出去。\n", this_player());
        else    message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", this_player());

        if( arg == "船家" ) {
                check_trigger();
                return 1;
        } else  message_vision("江面上远远传来一阵回声：“" + arg +
                "～～～”\n", this_player());
        return 1;
}

void check_trigger()
{
        object room;

        if( !query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
                room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
                if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object());
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
                } else
                message("vision", "只听得江面上隐隐传来：“别急嘛，"
                "这儿正忙着呐……”\n", this_object());
        }  else
                message("vision", "ERROR: boat not found\n", this_object() );
        } else 
                message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来伞n", this_object() );
}

void on_board()
{
        object room;

        if( !query("exits/enter") ) return;

        message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n", this_object());

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");
                message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
                "竹篙一点，扁舟向\n江心驶去。\n", room);
        }

        delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive", 20);
}

void arrive()
{
        object room;

        if( room = find_object(__DIR__"duchuan") ) {
                room->set("exits/out", __DIR__"damk");
                message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
                "搭上堤岸。\n", room );
        }

        remove_call_out("close_passage");
        call_out("close_passage", 20);
}

void close_passage()
{
        object room;

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");
                message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room)
;
                room->delete("yell_trigger"); 
        }
}

void reset()
{
        object room;

        ::reset();

        if( room = find_object(__DIR__"duchuan") )
                room->delete("yell_trigger"); 
}


	  

