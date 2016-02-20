//Cracked by Roath
// yijing.c  『黄帝内经』
// by aln oct / 97

#include <ansi.h>

inherit ITEM;
void setup()
{}

void create()
{
	set_name("黄帝内经", ({ "yijing", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("long", "这是一本线装书，里面密密麻麻的写满了文字。\n");
		set("value", 300);
                set("material", "paper");
//              set("no_drop","这样东西不能离开你。\n");
	}
}

void init()
{
        add_action("do_study","study");
        add_action("do_study", "du");
}

int do_study(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        int cost;

        if( !(arg == "yijing" || arg == "book") )
        return 0;

        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

/*      if(!arg || !objectp(ob = present(arg, me)) ){
                write("你要读什么？\n");
                return 1;
        }
*/
        if (!id(arg)) {
                write("你要读什么？\n");
                return 1;
        }

        if( (int)me->query_skill("literate", 1) < 20 ) {
                write("你识的字不多，读不懂书中的讲解。\n");
                return 1;
	}

        if( (int)me->query_skill("medicine", 1) > 29 ) {
                write("阁下对医理略有见识，不必再读『黄帝内经』了。\n");
                return 1;
	}

        if ( me->query("jing") < 80 ) {
                write("你的精神欠佳，捧着医经连打呵欠。\n");
                return 1;
	}

        if( (int)me->query("sg/exp") < 1000 && !me->query_temp("sgbook_poison") ) {
                message_vision("$N伸食指在口中一舔，蘸了些唾液翻阅起书来。\n", me);
                me->set_temp("sgbook_poison", 1);
                call_out("poison", 5, me);
        }

        cost = 30 + 600 / (int)me->query("int");
        if( me->query_temp("lu/yi1") ) cost /= 2;
        cost += random(cost / 2);

        me->improve_skill("medicine", random(2 * me->query_int()));
        me->receive_damage("jing", cost, "心力绞瘁死了");
        message_vision("$N一会儿翻阅着『黄帝内经』，一会儿苦思冥想。\n", me);

        return 1;
}

void poison(object me)
{
        tell_object(me, HIR"你突然感到一阵晕旋，原来是书上剧毒发作了！\n"NOR);
        me->receive_wound("qi", 50, "剧毒发作死了");
        call_out("extra", 20, me);
}

void extra(object me)
{
        me->delete_temp("sgbook_poison");
        tell_object(me, HIR"你突然感到一阵晕旋，原来是书上剧毒发作了！\n"NOR);
        message("vision", me->name()+"脚下几个踉跄，双脚一蹬便不动了，眼、耳、鼻、口中都流出黑血来！\n", environment(me), ({me}) );
        if( (int)me->query_skill("force") < 120 )
                me->receive_wound("qi", me->query("max_qi")+100, "剧毒发作死了");
        else    me->unconcious();
}

        







