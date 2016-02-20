//Cracked by Roath
// /d/xingxiu/rousiroom
// haowen Mar 31,1999

inherit ROOM;
#include <ansi.h>
void create()

{
        set("short", "柔丝索中");
        set("long", @LONG
你觉得似乎有千丝万缕缠绕着你，动弹不得。但似乎可以尝试挣扎(break)一下。
LONG
        );
        set("indoors", "xingxiu");
        set("cost", 1);
        set("invalid_startroom", 1);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_break", "break");
        add_action("do_practice", "practice");
        add_action("do_practice", "lian");
        add_action("do_practice", "dazuo");
        add_action("do_practice", "exercise");
        add_action("do_practice", "tuna");
        add_action("do_practice", "respirate");
        add_action("do_practice", "read");
        add_action("do_practice", "study");
        add_action("do_practice", "quit");
}

int do_practice()
{
        write("你现在手脚被缚，无法行动！\n");
        return 1;
}

int do_break()
{
        object dest,ob,me,*ob1;
        int i;
        me=this_player();
        dest=find_player(me->query_temp("current_catcher"));
        if(!dest)
        {
                me->delete_temp("current_catcher");
                me->move("/d/xingxiu/riyuedong");
                tell_object(me,"不知道什么时候柔丝索已经松开，也不知道这么来到这里。\n");
                return 1;               }       
//      ob=present("柔丝索",dest);


        ob1=all_inventory(dest);
        for (i=0;i<sizeof(ob1);i++)
                {
                if (ob1[i]->query("name")=="柔丝索")
                        ob=ob1[i];
                }

        if (!ob || !ob->query_temp("catched")||
		ob->query_temp("catched")!=me->query("id"))/*handle all the errors,won't stuck in here*/
                {
                me->delete_temp("current_catcher");
                me->move("/d/xingxiu/riyuedong");
                if(ob) {ob->delete("no_drop");
                        ob->delete_temp("catched");}
                tell_object(me,"不知道什么时候柔丝索已经松开，也不知道这么来到这里。\n");
                return 1;               }
        if (me->query("neili")<100)
                return notify_fail("你的内力太低，挣扎不开！\n");

        me->add("neili",-200);
        if (random(me->query_skill("force",1)+(me->query("combat_exp")/1000))>random(dest->query_skill("force",1)+(dest->query("combat_exp")/1000)))
                {               
                me->delete_temp("current_catcher");
                ob->delete_temp("catched");
                ob->delete("no_drop");
                me->move(environment(dest));
                message_vision("$N挣脱束缚，一跃而出！\n",me);
                }
        else {

tell_object(environment(dest),HIY"柔丝索中的人拼命扭来扭去，可是没有任何作用。\n"NOR);  
                tell_object(me,"你拼命挣扎，可是无法突破束缚！\n");
        }
        return 1;
}

