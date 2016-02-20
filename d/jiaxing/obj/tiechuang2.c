//Cracked by Roath
// Jay 8/9/96

inherit ITEM;

void create()
{
        set_name("铁床", ({"tie chuang","chuang","bed"}));
	set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long", @LONG 
一张硬梆梆的铁床，床上铺着草垫子被卷在一旁，露出刻在上面密密麻麻的字迹。
上面刻着：

    老夫生平快意恩仇，杀人如麻，囚居湖底，亦属应有之报。唯老夫任
    我行被困於此，一身通天彻地神功，不免与老夫枯骨同朽，後世小子
    ，不知老夫之能，亦憾事也。兹将老夫神功精义要旨，留书於此，後
    世小子习之，行当纵横天下，老夫死且不朽。

    功成之後，可用散功(sangong)将你的内力最大值降为零。这样就可以
    免除你内力过强之烦恼。
LONG
);
                set("unit", "张");
                set("material", "steal");
        } 
	setup();
}

void init()
{
 	add_action("do_du", "du");
        add_action("do_du", "study");
}

int do_du(string arg)
{
	int hglevel;

        object me = this_player();
        if (!(arg=="tie chuang" || arg=="chuang" || arg=="bed"))
	return 0;

        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
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

        if( (int)me->query("jing") < 35) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

	hglevel = me->query_skill("huagong-dafa", 1);
        if( (int)me->query("combat_exp") < (int)hglevel*hglevel*hglevel/10) {
		write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }                 
        if( me->query_skill("huagong-dafa", 1) > 149){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }

	if( me->query_skill("huagong-dafa", 1) < 50) {
		write("你研读了一会儿，但是发现上面所说的对你而言都太深了，完全无法领悟。\n");
        	return 1;
	}

	if( me->query_skill("force", 1)<10) {
		write("你的基本内功火候不足，不能学化功大法。\n");
		return 1;
	}
        if( me->query_skill("huagong-dafa", 1)>29 && 
	(me->query_skill("buddhism",1) || me->query_skill("mahayana", 1)
	|| me->query_skill("taoism",1))) {
                write("你的正派心法使你良心发现，不愿再学化功大法。\n");
                return 1;
        }

        me->receive_damage("jing", 35);
	me->improve_skill("huagong-dafa",me->query("int")/3);
	write("你在黑暗中摸索着铁板，领悟化功大法的要旨。\n");
        return 1;
}                         

