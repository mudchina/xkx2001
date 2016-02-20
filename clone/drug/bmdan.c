//Cracked by Roath
// /d/shenlong/obj/bmdan.c 天王保命丹
// by Aln  1/98

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
        set_name("天王保命丹", ({"baoming dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 4000);
                set("long", 
"这天王保命丹是由三百年老山人参、白熊胆、雪莲等物炼成的灵丹\n");
                set("medicine", 1);
                set("no_drop", "天王保命丹炼制，哪能乱扔！ \n");
        }

        setup();
}

int cure_ob(object me)
{
        if( (int)me->query("eff_qi")*10 > (int)me->query("max_qi")*3 
        &&  (int)me->query("eff_jing")*10 > (int)me->query("max_jing")*3 ) {
                write("你现在用不着服天王保命丹。\n");
                return 1;
        }

        if( !me->is_fighting() ) {
                write("现在又不是危急关头，别浪费了！\n");
                return 1;
        }

        message_vision("$N吃下一颗" + name() + "。\n", me);

        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("eff_jing", (int)me->query("max_jing"));

        message_vision(YEL "$N只觉伤势全愈了。\n\n" NOR, me);
        destruct(this_object());
        return 1;
}
