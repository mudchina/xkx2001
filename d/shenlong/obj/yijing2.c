//Cracked by Roath
// yijing.c  『十四经发挥』
// by aln oct / 97

inherit ITEM;
void setup()
{}

void create()
{
	set_name("十四经发挥", ({ "yijing", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("long", "这是一本线装书，里面有各式图谱和详细说明。\n");
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

        if( (int)me->query_skill("medicine", 1) < 30 ) {
                write("你还是先去读一读『黄帝内经』吧。\n");
                return 1;
	}

        if( (int)me->query_skill("medicine", 1) > 59 ) {
                write("阁下已熟知人体经脉和各处穴位，不必再读『十四经发挥』。\n");
                return 1;
	}

        if ( me->query("jing") < 120 ) {
                write("你的精神欠佳，捧着医经连打呵欠。\n");
                return 1;
	}

        cost = 40 + 800 / (int)me->query("int");
        if( me->query_temp("lu/yi2") ) cost /= 2;
        cost += random(cost / 2);

        me->improve_skill("medicine", random(2 * me->query_int()));
        me->receive_damage("jing", cost, "心力绞瘁死了");
        message_vision("$N一会儿翻阅着『十四经发挥』，一会儿苦思冥想。\n", me);

        return 1;
}

                
        
