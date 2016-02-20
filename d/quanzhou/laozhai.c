//Cracked by Roath
// room: laozhai.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string);

void create()
{
    set("short", "向阳老宅");
    set("long", @LONG
这里是福威镖局总镖头林震南在福建的旧居。室内的家具横七竖八地倒在
地上。房间的一角结着一张蜘蛛网，屋里到处是尘土，显然是已经很久没有人
住了。房间的尽头有一扇门，但已被坍塌的砖瓦挡住了。
LONG
    );

    set("exits", ([
        "north" : __DIR__"minzai3",
    ]));

    set("item_desc", ([
        "men" : "这扇门已被挡住无法通行，除非你打破(break)它。\n",
    ]) );
	set("cost", 1);
    setup();
}

void init()
{
    object book, me;
    me = this_player();
    add_action("do_break", "break");
    if ((objectp(book=present("pixie jianpu",me)))) {
	remove_call_out("buqun_rob");
	call_out("buqun_rob", 1, me, book);
    }
}

int do_break(string arg)
{
    int n;
    n = this_player()->query("neili");
    if( !arg || arg!="men" ) {
        write("不要随便打碎别人的东西！\n");
        return 1;
    }


    message_vision(
    "$N走到后门前，拜出骑马蹲裆式，深吸一口气，双掌同时拍出。\n", this_player());
        
    if (n>=200) {
        message_vision(
        "$N只听一声轰响，$N把门震开了！\n", this_player());
        set("exits/south", __DIR__"houyuan");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
    }

    return 1;
}

void close(object room)
{
    message("vision","门上的砖头瓦块稀里哗拉坍塌下来，又挡住了后门。\n", room);
    room->delete("exits/south");
}

void buqun_rob(object me, object book)
{
    message_vision(HIY "忽然，一个蒙面人从黑影里闪了出来，一招「有凤来仪」，"
        "手中长剑闪烁\n不定，刺向$N的咽喉！\n" NOR,  me);

    if( !me->query_skill("pixie-jian", 1) ) {
        message_vision("$N一愣之间，已被蒙面人刺中！\n", me);
        book->move(environment(me));
        destruct(book);
        me->unconcious();
    }
    else {
        message_vision(
        "$N身形飘忽，有如鬼魅，转了几转，移步到蒙面人的身后，躲过了"
        "蒙面人这一招。\n", me);
    }
    write("蒙面人双足点地，越墙而走。\n你感觉蒙面人的身法好像是华山派的。\n");
}
