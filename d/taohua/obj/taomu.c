//Cracked by Roath
// taomu.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(YEL"桃木"NOR,({ "taomu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("material", "wood");
                set("long", "这是一根三尺来长，刚砍下的桃木，略加雕琢(cut)既可做成一把桃木剑。\n");
                set("wield_msg", "$N拿出一跟$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(2);
        setup();
}

void init()
{
        add_action("do_cut", "cut");
}

int do_cut(string arg)
{
        object ob1, ob2, me;

        me = this_player();

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

        if (!arg || arg != "taomu")
                return notify_fail("你要雕刻什麽？\n");

        if( !objectp(ob1 = me->query_temp("weapon"))
        || (string)ob1->query("name") != "小铁斧")
                return notify_fail("你没有工具如何雕刻？！\n"); 

        message_vision(CYN"$N拿起小铁斧在桃木上细心的劈削着......\n"NOR, me);

        if (random(2) == 1) {
        message_vision(CYN"$N忙了半天，终于雕出一把粗糙的桃木剑，并在剑柄上刻上名字。\n"NOR, me);
        ob2 = new(__DIR__"taomujian");
        ob2->set("long", "这是一柄三尺来长，手工制成的桃木剑，似乎不是一件好兵器。\n"
                         "剑柄上刻着“"+me->name()+"”几个字。\n");
        ob2->set("owner", me->query("id"));
        ob2->move(me);
        destruct(this_object());
        } else {
        message_vision(CYN"$N一个不小心，“埃呀！喀嚓！”，桃木断掉了！\n"NOR,me);
        destruct(this_object());
        }

        return 1;
}
