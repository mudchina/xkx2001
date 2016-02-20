// yangguo.c 杨过
// By Xuanyuan 2001-9-5 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int des_object()
{
	message_vision( "却听得$N朗声说道：“今番良晤，豪兴不浅，他日江湖相逢，再当杯酒言欢。咱们就此别过。”说着袍袖一拂，飘然下山。\n", this_object() );
        destruct(this_object());
        return 1;
}
int ask_strike();
int ask_youju();

void create()
{
	set_name("杨过", ({ "yang guo", "yang" }));
	set("title", "神雕大侠");
	set("gender", "男性");
	set("age", 32);
	set("per",30);
	set("con",30);
	set("int",30);
	set("str", 30);
	set("dex", 30);
	set("class","swordman");
	set("long", "他是一位高大的男子，相貌俊秀。\n"+
	"一只长袖空空如也，显是断了一臂，尽管如此，\n"+
	"仍然掩不住他迷人的风采。\n");
	set("combat_exp", 3500000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 8000); 
	set("max_neili", 8000);

	set_skill("force", 400);
	set_skill("strike", 400);
	set_skill("dodge", 380);
	set_skill("parry", 380);
	set_skill("literate", 100);
	set_skill("xiaohun-zhang",400);
	set_skill("yunu-xinjing", 400);
	set_skill("gumu-shenfa",380);
	set_skill("yunu-jue", 300);
	map_skill("parry", "xiaohun-zhang");
	map_skill("strike","xiaohun-zhang");
	map_skill("dodge", "gumu-shenfa");
	map_skill("force", "yunu-xinjing");
        prepare_skill("strike", "xiaohun-zhang");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: perform_action, "parry.xiaohun" :),
                
        }) );
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);

        set("inquiry", ([
                "小龙女" : "She is my wife。\n",
		"黯然销魂掌" : (: ask_strike :),
		"古墓幽居" : (: ask_youju :),
       ]) );
	create_family("古墓派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 2);
}
void init()
{
        ::init();
        add_action("do_yuanyi","yuanyi");
}
void attempt_apprentice(object ob)
{
        command("say 我不收弟子，这位"+RANK_D->query_respect(ob)+"还是请回吧。");
	return;
}

int accept_kill(object obj)
{
        object ob = this_player();
	command("chat* oh " + obj->query("id") + "" );
	command("chat 原来这世上还有" + ob->name() + "这等不怕死的"+RANK_D->query_respect(ob)+"。");
	return 1;
}
void die()
{
	object ob, me;
	me = this_object();

	if( !living(this_object()) ) revive(1);
	command("chat* disapp");
	if( objectp(ob = me->query_temp("last_damage_from")) )
	{
		command("chat " + ob->name() + "德配天地，威震寰宇，古今无比。");
		command("chat* admire2 yang guo");
	}
	::die();
}
int ask_strike()
{
        object ob = this_player();
	int my_strike, add_level;
	my_strike = ob->query_skill("xiaohun-zhang", 1);

	if ( ob->query("yangguo_taught") ) {
		command( "say 我能教你的已经教了，日后只有靠你自己苦练才能体会黯然销魂的意境。\n");
		des_object();
		return 1;
	}
        if ( ob->query("family/family_name") != "古墓派" ) {
                command("say 这是我在海潮之中苦练，悟出的一十七招掌法。");
		des_object();
                return 1;
        }
	if ( ob->query("gender") != "男性" ) {
                command("say 这是我在海潮之中苦练，悟出的一十七招掌法。");
                command("say 这套掌法我本可以传授与你，怎耐其要求掌力纯以刚猛为主，故女子是不宜修习的。");
                command("sigh2");
		des_object();
                return 1;
        }

	command("say "+RANK_D->query_respect(ob)+"既然一场来到，你我可谓有缘，待我指点你一些武功吧。");
	message_vision( "杨过开始为$N解说黯然销魂掌的精义。\n", ob );
	tell_object( ob, "你的黯然销魂掌增加了二十级！\n");
        command("say 这套掌法定名为“黯然销魂掌”，取的是江淹「别赋」中那句“黯然销魂者，唯别而已矣”之意。");
        command("say 当你能领悟这句话含义的时候，所发出的威力不能开山也能碎石！");
	add_level = my_strike + 20;
	ob->set_skill("xiaohun-zhang", add_level);
	ob->set("yangguo_taught", 1);
	ob->add("combat_exp", 15000);
	des_object();
	return 1;
}

int ask_youju()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "古墓派") {
                command("say 这是“美女拳法”最后一招的收式，是我所自创的。");
		des_object();
                return 1;
        }
	if (ob->query("family/master_name") == "李莫愁") {
                command("say 这是“美女拳法”最后一招的收式，是我所自创的。");
                command("say 你是我师伯李莫愁的弟子，我本不该指点于你。");
                command("say 既然一场来到，如果你愿意让我为化去你身上的邪气，指点你这招“古墓幽居”。你愿意(yuanyi)否？");
        	ob->set_temp("mark/youju", 1);
		return 1;
		}     
        if (ob->query("gumu/youju") > 0 ) {
                command("say 你不是已经学会了吗？");
		des_object();
                return 1;
        }
        if ((int)ob->query_skill("cuff", 1) < 120) {
                command("say 要使用这样的绝招需要高深的拳法，你还是多练习练习“美女拳法”再说吧。");
		des_object();
                return 1;
        }
	command("say 这是“美女拳法”最后一招的收式，是我所自创的。");
	command("say 好，既然一场来到，你我可谓有缘，待我指点你这招“古墓幽居”。");
	message_vision( "$N仔细给$n讲解了“古墓幽居”的精要所在。\n",this_object(), ob );
        ob->set("gumu/youju", 1);
	des_object();
        return 1;
}

int do_yuanyi()
{
        object me=this_player();

        if (!me->query_temp("mark/youju"))
                return 0;
      
	message_vision("$n伸手在$N身上几处命门大穴连拍数下。\n", me, this_object() );
        write("你感到头脑中一阵通泰。\n");
        me->set("shen", 0);
	command("say 好，孺子可教，我就指点你这招“古墓幽居”。");
	message_vision( "$N仔细给$n讲解了“古墓幽居”的精要所在。\n",this_object(), me );
        me->delete_temp("mark/youju", 1);
        me->set("gumu/youju", 1);
	des_object();
        return 1;
}
