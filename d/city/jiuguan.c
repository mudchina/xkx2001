//Cracked by Roath
// jiuguan.c
// xQin 7/00

inherit ROOM;
void init();
#include <ansi.h>
void create()
{
        set("short", "高升酒馆");
        set("long", @LONG
这里是个开张不久的酒馆，几张新的桌子旁有几个酒客在喝酒吃小菜。人
来人往，时时传来劝酒，行酒令的阵阵喧哗，十分热闹。看来是个打听消息的
好地方。楼梯旁边的木柱挂著一个牌子(paizi)，楼上是雅座。              
LONG
        );

        set("exits", ([
                "east" : __DIR__"nandajie3",
                "up" : __DIR__"jiuguan2",

        ]));

        set("objects", ([
                __DIR__"npc/j_waiter" : 1,
                __DIR__"npc/zhang15" : 1,
        ]));
        set("item_desc", ([
                "paizi" : "五香花生(Huasheng)            ：十五文铜板\n"
                          "翡翠豆腐(Doufu)               ：二十五文铜板\n"
                          "烧酒(fill_shaojiu)            ：二十文铜板\n"
                          "米酒(fill_mijiu)              ：二十文铜板\n"
                          "汾酒(fill_fenjiu)             ：二十五文铜板\n"
        ]));

        set("cost", 0);
//        set("day_shop", 1);
        setup();
}
void init()
{
        add_action("do_fill_shaojiu", "fill_shaojiu");
        add_action("do_fill_mijiu", "fill_mijiu");
        add_action("do_fill_fenjiu", "fill_fenjiu");
        
}
int do_fill_shaojiu(string arg)
{
        object ob, obj, me = this_player();

        if (!objectp(obj = present("xiao er", environment(me))))
        {       write("酒馆小二不在！\n");
                return 1;
        }

        if (!living(obj)){
                write("你还是等酒馆小二醒过来再说吧。\n");
                return 1;
        }

        if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("你要把酒装在哪儿？\n");
                return 1;
        }

        switch (MONEY_D->player_pay(this_player(), 20)) {
        case 0: {
                write("穷光蛋，一边呆着去！\n");
                return 1;
                }
        case 2: {
                write("您的零钱不够了，银票又没人找得开。\n");
                return 1;
                }
       }	
        if( ob->query("liquid/remaining") )
                message_vision("$N将" + ob->name() + "里剩下的" + ob->query("liquid/name") + 
                "倒掉。\n", this_player());
        message_vision("$N给酒馆小二二十文铜板。\n酒馆小二给$N的"+ob->name()+"装满烧酒。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", "烧酒");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
        ob->set("liquid/drunk_apply", 4);
        return 1;
}
int do_fill_mijiu(string arg)
{
        object ob, obj, me = this_player();
        
        if (!objectp(obj = present("xiao er", environment(me))))
        {       write("酒馆小二不在！\n");
                return 1;
        }

        if (!living(obj)){
                write("你还是等酒馆小二醒过来再说吧。\n");
                return 1;
        }

        if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("你要把酒装在哪儿？\n");
                return 1;
        }

        switch (MONEY_D->player_pay(this_player(), 20)) {
        case 0: {
                write("穷光蛋，一边呆着去！\n");
                return 1;
                }
        case 2: {
                write("您的零钱不够了，银票又没人找得开。\n");
                return 1;
                }
       }	
        if( ob->query("liquid/remaining") )
                message_vision("$N将" + ob->name() + "里剩下的" + ob->query("liquid/name") + 
                "倒掉。\n", this_player());
        message_vision("$N给酒馆小二二十文铜板。\n酒馆小二给$N的"+ob->name()+"装满米酒。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", "米酒");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
        ob->set("liquid/drunk_apply", 3);
        return 1;
}
int do_fill_fenjiu(string arg)
{
        object ob, obj, me = this_player();
        
        if (!objectp(obj = present("xiao er", environment(me))))
        {       write("酒馆小二不在！\n");
                return 1;
        }

        if (!living(obj)){
                write("你还是等酒馆小二醒过来再说吧。\n");
                return 1;
        }

        if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("你要把酒装在哪儿？\n");
                return 1;
        }

        switch (MONEY_D->player_pay(this_player(), 25)) {
        case 0: {
                write("穷光蛋，一边呆着去！\n");
                return 1;
                }
        case 2: {
                write("您的零钱不够了，银票又没人找得开。\n");
                return 1;
                }
       }	
        if( ob->query("liquid/remaining") )
                message_vision("$N将" + ob->name() + "里剩下的" + ob->query("liquid/name") + 
                "倒掉。\n", this_player());
        message_vision("$N给酒馆小二二十五文铜板。\n酒馆小二给$N的"+ob->name()+"装满汾酒。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", "汾酒");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
        ob->set("liquid/drunk_apply", 5);
        return 1;
}