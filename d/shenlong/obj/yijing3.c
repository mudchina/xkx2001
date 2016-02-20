//Cracked by Roath
// yijing.c  『孙思邈千金方』
// by aln oct / 97

inherit ITEM;
void setup()
{}

void create()
{
	set_name("孙思邈千金方", ({ "yijing", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("long", "这是一本线装书，里面密密麻麻的写满了文字。\n");
		set("value", 300);
                set("material", "paper");
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

        if( (int)me->query_skill("medicine", 1) < 60 ) {
                write("你还是先去读一读『十四经发挥』吧。\n");
                return 1;
	}

        if( (int)me->query_skill("medicine", 1) > 89 ) {
                write("阁下已熟知各类伤痛治疗方法和药物配制，不必再读『孙思邈千金方』。\n");
                return 1;
	}

        if ( me->query("jing") < 150 ) {
                write("你的精神欠佳，捧着医经连打呵欠。\n");
                return 1;
	}

        cost = 50 + 1000 / (int)me->query("int");
        if( me->query_temp("lu/yi3") ) cost /= 2;
        cost += random(cost / 2);

        me->improve_skill("medicine", random(2 * me->query_int()));
        me->receive_damage("jing", cost, "心力绞瘁死了");
        message_vision("$N一会儿翻阅着『孙思邈千金方』，一会儿苦思冥想。\n", me);

        return 1;
}

                
        
