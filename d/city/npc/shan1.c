//Cracked by Roath
// /d/city/npc/shan.c
// xbc: 96/11/19

inherit NPC;
inherit F_VENDOR;

int do_look(string);
string ask_me();

void create()
{
        set_name("小姗", ({ "shan", "xiao shan" }) );
        set("long", "这是扬州城月老亭里供应茶水的小姗姑娘，正坐在一旁读书。\n");
	set("title", "民女");
        set("gender", "女性");
        set("age", 16);
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
        set("combat_exp", 10000);

        set_skill("literate", 100);
        set_skill("dodge", 30); 
	set_skill("force", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 30);

        set("inquiry", ([
                "name" : "我就是小姗。" ,
                "here" : "这是月老亭，请问是来帮着写婚姻指南的还是来找对象的？",
		"marriage" : "火星人说了，婚姻就是把水做的女人和石头做的男人放在一起搅和，就是和泥。" ,
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
		"divorce" : "人说了，离婚，就是新生活的开始了。" ,
		"离婚" : "人说了，离婚，就是新生活的开始了。" ,
		"大水桶" : "噢，那桶里的凉开水是刚凉好的，你自己去灌吧。",
        ]) );

        setup();
        carry_object("d/city/obj/pink_cloth")->wear();
        carry_object("d/city/obj/flower_shoe")->wear();
        carry_object("u/qfy/obj/jiuzhuan");

/*
        set("vendor_goods", ({
                "u/xbc/obj/zhinan",
        }) );
*/
}

void init()
{
        object ob;

        ::init();
//        add_action("do_look","kiss");
      	add_action("do_look","kiss1");
       	add_action("do_look","kick");
      	add_action("do_look","slap");
	add_action("do_look","flirt");
	add_action("do_look","loveshoe");

//        add_action("do_buy", "buy");
//        add_action("do_list", "list");
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
        if (!me || environment(me) != environment())
                return;

        me->move("/d/city/dongdajie3");
         message("vision","只听“嘭”地一声，紧接着" +  me->query("name") +
                "从月老亭里飞了出来，脸上一个红手印，屁股上有一个小鞋印。\n", environment(me), me);
}

