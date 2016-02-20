//Cracked by Roath

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("七伤拳经", ({"qishang jing", "jing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "
	五行之气调阴阳，
	损心伤肺摧肝肠，
	藏离精失意恍惚，
	三焦齐逆兮魂魄飞扬\n");
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

	if (!present("qishang jing", me)) return 0;

	if ( me->query_skill("cuff", 1) < me->query_skill("qishang-quan",1)*2/3){
		write("你的基本拳法火候不够。\n");
	return 1;
	}
	if ( me->query_skill("qishang-quan",1) > 100 ) {
		write("你觉得经中所诉过于粗浅，无法再学到新东西了。\n");
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

	message("vision", me->name() + "仔细地研读《七伤拳经》。\n",environment(me), me);

	me->improve_skill("qishang-quan", random(me->query_int()*3/2));
	me->receive_damage("jing", 1500 / (int)me->query("int"));
	me->add("potential", -1);
	me->apply_condition("qs_self_damage", 5+random(5));

	write("你研读《七伤拳经》，颇有心得。\n");
	return 1;
}
