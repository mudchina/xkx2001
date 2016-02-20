//Cracked by Roath

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("龙象般若经", ({"longxiang jing", "jing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册厚厚的经书。\n");
		set("material", "paper");
		set("value", 500);
	}
	::create();
}
void init()
{
	add_action("do_study", "du");
	add_action("do_study", "study");
}
int do_study(string arg)
{
	object me = this_player();
	object ob = this_object();

	if (!id(arg)) return 0;

	if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}
	if(me->query("class") != "lama"){
        	write("你未入佛门，尘缘不断，无法修持密宗神法。\n");
		return 1;
	}
	if ( me->query_skill("lamaism", 1) < 150){
		write("这本书对你来说太深奥了。\n");
		return 1;
	}
	if (!present("longxiang jing", me)) return 0;

	if ( me->query_skill("force", 1) < me->query_skill("longxiang-banruo", 1)*2/3){
		write("你的基本内功火候不够。\n");
	return 1;
	}
	if ( me->query("jing") < 60){
		write("你现在过于疲倦，无法专心下来研读新知。\n");
		return 1;
	}
	if (me->is_busy()) {
                write("你现在正忙着呢。\n");
		return 1;
	}
	if (environment(me)->query("pigging")){
                write("你还是专心拱猪吧！\n");
		return 1;
	}

	if ( me->is_fighting() ){ 
                write("你无法在战斗中专心下来研读新知！\n");
		return 1;
	}

	if ( me->query("potential") < 1){
		write("你的潜能不够！\n");
		return 1;
	}

	message("vision", me->name() + "仔细地研读《龙象般若经》。\n", environment(me), me);

	me->improve_skill("longxiang-banruo", random(me->query_int()*3/2));
	me->receive_damage("jing", 1500 / (int)me->query("int"));
	me->add("potential", -1);

	if(me->query_skill("longxiang-banruo", 1) > 200){
        me->add("potential", -1);
        me->receive_damage("jing", 1500 / (int)me->query("int"));
        }
	write("你研读《龙象般若经》，颇有心得。\n");
	return 1;
}
