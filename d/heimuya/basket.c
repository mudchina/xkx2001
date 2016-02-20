//Cracked by Roath
// Room: /d/heimuya/basket.c
// Date: fear 1999/12/18

inherit ITEM;
#include <ansi.h>;

void on_basket();
void arrive();
void close_passage();
int do_knock(string arg);
void reset();

void create()
{
        set("short","大竹篓");
	set("long",@LONG
这是一只大竹篓，足可装得十来石米。旁边挂着一个小铜锣。
LONG);
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}

void init()
{
    add_action("do_knock", "knock");
}

void on_basket()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "只觉竹篓一动,开始缓缓移动。\n",
        this_object() );

    if( room = find_object(__DIR__"basket") )
    {
        room->delete("exits/out");
        message("vision", "竹篓不住移动，一片片轻云从头顶飘过，你身入云
雾，俯视篓底，却什么也望不到。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 40);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"basket") )
    {
        room->set("exits/out", __DIR__"clifftop");
        message("vision", "只觉得脚下一震，竹篓已停了下来。再也没半分动静。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 1);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"basket") ) {
        room->delete("exits/out");
        message("vision","大竹篓正开始缓缓移动。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_knock(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="tongluo" ) arg = "铜锣";
        message_vision("铛铛铛，$N使出吃奶的力气敲了铜锣三下。\n",
            this_player());
    if( arg=="铜锣")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("你要敲什么？\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"basket") )
        room->delete("yell_trigger"); 
}
