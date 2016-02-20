//Cracked by Roath
//ryu, 11/17/96. 

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}

void create()
{
        set_name("八埋茶刹罗经", ({ "shu", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 400);
                set("material", "paper");

        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	int neili_lost;

	if (!(arg== "book" || arg== "shu"))
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

        if (!id(arg)) {	
                write("你要读什么？\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

	if(me->query("class") != "lama")
                return notify_fail("你未入佛门，尘缘不断，无法修持密宗神法。\n");

        message("vision", me->name() + "仔细地研读《八埋茶刹罗经》。\n", environment(me), me);
        if( (int)me->query("jing") < 15 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

        if ( me->query_skill("necromancy", 1) > 200) neili_lost = 20;
	     else if ( me->query_skill("necromancy", 1) > 100) neili_lost = 10;
	     else neili_lost = 5;


        if( (int)me->query("neili") < neili_lost) {
		write("你内力不够。\n");
                return 1;
        }

            if ((!objectp(ob = present("kulou guan", me)) ) ||
               (!ob->query("equipped") )) {
                write("你觉得头上仿佛少了点什麽，读得头昏眼花。\n");
                return 1;
        }
            if ((!objectp(ob = present("rentou lian", me)) ) ||
               (!ob->query("equipped") )) {
                write("你觉得身上仿佛少了点什麽，读得头昏眼花。\n");
                return 1;
        }
            if ((!objectp(ob = present("lubo", me)) ) ||
               (!ob->query("equipped") )) {
                write("你觉得手中仿佛少了点什麽，读得头昏眼花。\n");
                return 1;
        }
	if(me->query_skill("lamaism", 1) < 30){
		write("你研读了一会儿，但是发现上面所说的对你而言太深奥了。\n");
		return 1;
	}
        if( me->query_skill("necromancy", 1) > 300){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }
	if ( me->query_skill("necromancy", 1) >= me->query_skill("lamaism", 1)){ 
                write("你的密宗心法修为不够，再怎么读也没用！\n");
		return 1;
	}
        me->receive_damage("jing", 40);
	me->set("neili",(int)me->query("neili")-neili_lost);
        if( !me->query_skill("necromancy", 1) ) {
                me->set_skill("necromancy", 0);
        }
        me->improve_skill("necromancy", (int)me->query_skill("literate", 1)/3+1);
        write("你研读《八埋茶刹罗经》，颇有心得。\n");
        return 1;
}
