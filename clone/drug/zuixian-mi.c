//Cracked by Roath
// zuixianmi.c
// fixed bug, sdong, 7/16/1999

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"醉仙蜜"NOR, ({"zuixian mi", "mi"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "这是一包石梁派温家祖传的迷药。\n" );
                set("unit", "包");
                set("value", 1000);
                set("medicine", 1);
        }
        setup();
}

void init()
{
        add_action("do_pour", "pour");
}

int do_pour(string arg)
{
        int da;
        string me, what;
        object ob;
        function f;

        if( !arg
        ||      sscanf(arg, "%s in %s", me, what)!=2
        ||      !id(me) )
                return notify_fail("命令格式: pour <药> in <物品>。\n");

        ob = present(what, this_player());
        if( !ob )
                return notify_fail("你身上没有" + what + "这样东西。\n");
        if( !ob->query("liquid/remaining") )
                return notify_fail(ob->name() + "里什么也没有，先装些酒水才能溶化药粉\n");
        da = ob->query("liquid/drunk_apply");

        if (da > 8 )da = 8; // must set uplimit, otherwise pour in jiuping with guiyuan dan can add nieli 100M

        ob->set("liquid/drunk_apply",da*5);
        ob->set("zuixian",1);
        message_vision("$N将一包"+ name() + "倒进" + ob->name() 
                + "摇晃了几下。\n", this_player());
        destruct(this_object());
        return 1;
}
