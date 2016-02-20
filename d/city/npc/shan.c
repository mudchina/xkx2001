// Change by Server
// /d/city/npc/shan.c
// xbc: 96/11/19

inherit NPC;
inherit F_DEALER;

int do_look(string);
string ask_me();
string ask_beauty();
string ask_ugly();
string ask_age();
string ask_exp();
string ask_marriage();
string ask_fat();
string ask_pk();
string ask_balance();
string ask_mudage();
string ask_lit();
int env_cmp(object o1, object o2);

void create()
{
        set_name("小姗", ({ "shan", "xiao shan" }) );
        set("long", "这是一个看起来傻傻的卖花小姑娘。\n");
	set("title", "民女");
        set("gender", "女性");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 18);
        set("int", 23);
        set("con", 19);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 80000);

        set_skill("literate", 100);
        set_skill("dodge", 30); 
	set_skill("force", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 30);

        set("inquiry", ([
                "name" : "我就是小姗。" ,
                "here" : "这是月老亭。你可以问我 age, balance, beauty, exp, fat, literate, marriage, mudage, pk, ugly, ",
		"婚姻" : "火星人说了，婚姻就是把水做的女人和石头做的男人放在一起搅和，就是和泥。" ,
		"结婚" : "火星人说了，婚姻就是把水做的女人和石头做的男人放在一起搅和，就是和泥。" ,
		"kiss" : "你无聊不无聊啊，这是婚姻介绍所，你走错地方了吧。",
		"sex" : (: ask_me :),
		"make love" : (: ask_me :),
		"love" : "ＬＯＶＥ？嘻嘻，王八看绿豆，看对眼啦。" ,
		"爱情" : "爱情？嘻嘻，王八看绿豆，看对眼啦。" ,
		"boyfriend" : "男朋友？愁烟说了，你千万不要先说你喜欢他。" ,
		"男朋友" : "男朋友？愁烟说了，你千万不要先说你喜欢他。" ,
		"girlfriend" : "愁烟说了，想交女朋友，你得先多学些文化，装得甜一点才行。" ,
		"女朋友" : "愁烟说了，想交女朋友，你得先多学些文化，装得甜一点才行。" ,
		"wife" : "不知听谁说的，妻子就是一个你结婚前爱得要命，结婚后讨厌得不得了的女人。" ,
		"妻子" : "不知听谁说的，妻子就是一个你结婚前爱得要命，结婚后讨厌得不得了的女人。" ,
		"husband" : "我表舅妈说了，丈夫就是一个大娃娃啊。" ,
		"丈夫" : "我表舅妈说了，丈夫就是一个大娃娃啊。" ,
		"divorce" : "离婚，就是新生活的开始了。" ,
		"离婚" : "离婚，就是新生活的开始了。" ,
		"大水桶" : "噢，那桶里的凉开水是刚凉好的，你自己去灌吧。",
	    "beauty" : (: ask_beauty :),
	    "ugly" : (: ask_ugly :),
	    "age" : (: ask_age :),
	    "exp" : (: ask_exp :),
	    "marriage" : (: ask_marriage :),
	    "fat" : (: ask_fat :),
	    "pk" : (: ask_pk :),
	    "pker" : (: ask_pk :),
	    "balance" : (: ask_balance :),
	    "rich" : (: ask_balance :),
	    "mudage" : (: ask_mudage :),
	    "literate" : (: ask_lit :),
        ]) );

        setup();
        carry_object("d/city/obj/pink_cloth")->wear();
        carry_object("d/city/obj/flower_shoe")->wear();

        set("vendor_goods", ({
                "d/city/obj/rose",
        }) );
}

void init()
{
        object ob;

        ::init();
      	add_action("do_look","kiss1");
       	add_action("do_look","kick");
      	add_action("do_look","slap");
	add_action("do_look","flirt");
	add_action("do_look","loveshoe");
        add_action("do_list", "list");
        add_action("do_buy", "buy");

        if( interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

int ask_me()
{
        object me;
 
        me = this_player();
        switch( random(5) ) {
                case 0:
	                message("vision",
   "小姗向" + me->name() +"怒道：你无聊不无聊呀。流氓！你出去！\n", me );
                        command("slap " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 1:
		        message("vision",
   "小姗向" + me->name() +"怒道：你无聊不无聊呀。流氓！你出去！\n", me );
                        command("kick " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 2:
                        command("faint " + me->query("id"));
                        break;
                case 3:
                        command("rascal " + me->query("id"));
			command("slap " + me->query("id"));
                        break;
                case 4:
			command("xixi " + me->query("id"));
                        command("benger " + me->query("id"));
                        break;
        }
   	return 1;
}

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="shan" || target=="xiao shan") 
        if ((string)me->query("gender") != "女性") {
                   message("vision",
   "小姗向" + me->name() +"道：你无聊不无聊呀。\n", me );

	switch( random(5) ) {
		case 0:
                        command("slap " + me->query("id"));
			remove_call_out("kicking");
			call_out("kicking", 1, me);
                        break;
                case 1:
                        command("kick " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 2:
                        command("faint " + me->query("id"));
                        break;
                case 3:
                        command("stare " + me->query("id"));
                        break;
                case 4:
                        command("rascal " + me->query("id"));
			command("slap " + me->query("id"));
                        break;
        }
	}
        return 1;

}

/*
void greeting(object ob)
{
	object zhn;

        if( !ob || environment(ob) != environment() ) return;

        switch( random(2) ) {
                case 0:
                say( "小姗姑娘坐在一旁读书，见有人来了，抬起头来望了一眼，指了指墙上的
四周的柱子道：你自己看吧，想留言的就找个空位留吧。说完又埋头读书去了。\n");
          	break;

                case 1:
                say( "小姗姑娘坐在一旁读书，见有人来了，放下手里的书说：这位" + RANK_D->query_respect(ob) + "，
请进请进，喝杯水，慢慢看吧，柱子上可贴了有不少启示呐。\n");
		break;
        }
        zhn = new("/u/xbc/obj/zhinan");
        zhn->move(ob);
        message_vision("小姗给了$N一本小册子。\n", ob);

	return;
}

*/

void kicking(object me)
{
        if (!me || environment(me) != environment()
	|| environment(this_object())->query("short") != "月老亭")
                return;

        me->move("/d/city/dongdajie3");
         message("vision","只听“嘭”地一声，紧接着" +  me->query("name") +
                "从月老亭里飞了出来，脸上一个红手印，屁股上有一个小鞋印。\n", environment(me), me);
}

int env_cmp(object o1, object o2)
{
        string env1, env2;
        object where;
        env1 = (where = environment(o1)) ? base_name(where) : "none";
        env2 = (where = environment(o2)) ? base_name(where) : "none";
        return strcmp(env1, env2);
}

string ask_beauty()
{
	object where, ob, obj1, obj2,*ob_list;
	string msg, name1, name2;
	int i, per = 0;

	ob_list = users();
        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                if( ob_list[i]->query("per") > per 
                && ob_list[i]->query("gender") == "女性"
		&& !wizardp(ob_list[i])
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj1 = ob_list[i];
                        per = obj1->query("per");
                }
        }

	per = 0;
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("per") > per 
		&& ob_list[i]->query("gender") != "女性"
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj2 = ob_list[i];
			per = obj2->query("per");
		}
	}

	if ( !obj1 && !obj2 ) {
		msg ="咦，人呢？\n";
		return msg;
	}

	obj1->set_temp("top_girl",1);
	obj2->set_temp("top_boy",1);
	name1 = obj1->query("name")+"("+obj1->query("id")+")";
	name2 = obj2->query("name")+"("+obj2->query("id")+")";
	msg ="嘻嘻，现在侠客行里数"+name1+"最漂亮，"+name2+"最英俊。\n";

	return msg;
}

string ask_ugly()
{
	object where, ob, obj,*ob_list;
	string msg, name;
	int i, per = 30;

	ob_list = users();

	per = 30;
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("gender") != "女性"
		&& !wizardp(ob_list[i])
		&& ob_list[i]->query("per") < per 
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			per = obj->query("per");
		}
	}

	if ( !obj ) {
	msg ="大家都很英俊的紧呢。\n";
	return msg;
	}

	obj->set_temp("ugly_boy",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="嗯，现在侠客行里数"+name+"最丑样。\n";

	return msg;
}

string ask_age()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, age = 0;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("combat_exp") > 1000 
		&& !wizardp(ob_list[i])
		&& ob_list[i]->query("mud_age") > age 
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			age = obj->query("mud_age");
		}
	}

	if ( !obj ) {
		msg ="咦，咋没人了呢？\n";
		return msg;
	}

	obj->set_temp("oldest",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="嘻嘻，除了大米和神仙外，现在侠客行里数"+name+"年纪最大。\n";

	return msg;
}

string ask_exp()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, exp = 0;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("combat_exp") > exp 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			exp = obj->query("combat_exp");
		}
	}

	if ( !obj ) {
		msg ="咦，现在怎么一个高手都没有了？\n";
		return msg;
	}

	obj->set_temp("highhand",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="啊，现在侠客行里数"+name+"的武功最高！\n";

	return msg;
}


string ask_marriage()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, married_times = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("married_times") > married_times 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			married_times = obj->query("married_times");
		}
	}

	if ( !obj ) {
		msg ="咦，现在怎么都没人结过婚？\n";
		return msg;
	}

	obj->set_temp("most_married",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="嘻嘻，现在侠客行里数"+name+"结婚的次数最多。\n";

	return msg;
}

string ask_fat()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, fat = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->max_food_capacity() > fat 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			fat = obj->max_food_capacity();
		}
	}

	if ( !obj ) {
		msg ="咦，现在的人怎么都这么瘦？\n";
		return msg;
	}

	obj->set_temp("fat",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="嘻嘻，现在侠客行里数"+name+"最能吃。\n";

	return msg;
}

string ask_pk()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, pk = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("PKS") > pk 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			pk = obj->query("PKS");
		}
	}

	if ( !obj ) {
		msg ="现在这里没人杀过人。\n";
		return msg;
	}

	obj->set_temp("pk_most",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="呃，……，现在这里数"+name+"杀的人最多！\n";

	return msg;
}

string ask_balance()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, balance = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("balance") > balance 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			balance = obj->query("balance");
		}
	}

	if ( !obj ) {
		msg ="现在这里没人杀过人。\n";
		return msg;
	}

	obj->set_temp("richest",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="嘻嘻嘻，这里数"+name+"最有钱。\n";

	return msg;
}

string ask_mudage()
{
	object me = this_player();
        int t, mm, d, h, m, s;
        string time, msg;

        t = me->query("mud_age");
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t % 30;             t /= 30;
        mm = t;

        if(mm) time = chinese_number(mm) + "月";
        else time = "";

        if(d) time += chinese_number(d) + "天";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        msg ="你已经在侠客行泥潭里泡了" + time + "。\n";
        return msg;

}

string ask_lit()
{
        object where,ob,obj,*ob_list;
        string msg, name;
        int i, lit_level = 0;

        ob_list = users();
        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                if( ob_list[i]->query_skill("literate", 1) > lit_level 
                && !wizardp(ob_list[i])
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        lit_level = obj->query_skill("literate", 1);
                }
        }

        obj->set_temp("highest_lit",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="现在侠客行里数"+name+"读的书最多。\n";

        return msg;
}

