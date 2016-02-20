//Cracked by Roath
#include <ansi.h>
inherit NPC;

int ask_pixie();
int ask_liandan();
//int auto_perform();

void create() 
{
	set_name("东方不败", ({ "dongfang bubai", "dongfang", "bubai" }));
	set_color("$HIW$");
	set("title", "日月神教教主");
	set("long", "这人便是夺取了日月神教教主之位、十余年来号称武功天下第一的东方不败。\n"
		"可是此刻他剃光了胡须，脸上竟然施了脂粉，身上那件衣衫式样男不男、女不\n"
		"女，颜色之妖，便穿在盈盈动人的少女身上，也显得太娇艳、太刺眼了些。这\n"
		"样一位惊天动地、威震当世的武林怪杰竟是如此模样。\n");
	 set("gender", "无性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("canuse_guimei",1);
	set("canuse_cixin",1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 10000);
	set("max_jing", 15000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("max_jingli", 15000);
	set("jingli", 15000);
	set("jiali", 300);
	set("combat_exp", 6400000);
    set("shen_type", -1);
        set("shen", -6400000);



	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("strike", 400);
	set_skill("pixie-jian", 400);
	set_skill("taiji-shengong",400);

    map_skill("force", "taiji-shengong");
    map_skill("dodge", "pixie-jian");
    map_skill("parry", "pixie-jian");
    map_skill("sword", "pixie-jian");
    set("no_get", "想将教主带走？做梦！");

/*	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
*/
	set("inquiry", ([
		"辟邪剑法" : (: ask_pixie :),
		"炼丹" : (: ask_liandan :),

	]));

	setup();
	carry_object("/d/quanzhou/obj/xiuhua")->wield();
	carry_object("d/city/obj/pink_cloth")->wear();

}
int ask_liandan()
{
	object me = this_player();
	object ob = this_object();
	string a1,a2,a3,a4,a5;
	string b1,b2,b3,b4,b5;
	int random_a;
		if(me->query_skill("pixie-jian", 1) <1)
	{
		message_vision("$N对$p娇声说道：你并未练习辟邪剑法呀，问奴家这个做甚？\n", ob,me);
		return 1;
	}
	if(me->query_skill("pixie-jian", 1) <200)
	{
		message_vision("$N对$p娇声说道：你辟邪剑法修为不算很高，无需丹药辅佐练功。\n", ob,me);
		return 1;
	}
	if(me->query("can_dfbb")!=1)
	{
		message_vision("$N对$p娇声说道：你为我日月神教所做事情甚少，问我这个做甚？\n", ob,me);
		return 1;
	}

	if(me->query("drug_list"))
	{
		message_vision("$N对$p娇声说道：你不是知道秘方吗？要来问我做甚？\n", ob,me);
		return 1;
	}
	message_vision("$N对$p娇声说道：既然你忠心我教，我就将这炼丹的秘方儿告知你。\n", ob,me);
	message_vision("$N手指飞快点过$p几个秘穴，点了点头。\n", ob,me);

	random_a=random(3);
	if(random_a==1)
	{
		a1="无花果";
		b1="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a1="阴阳草";
			b1="yinyang cao";
		}
		else
		{
			a1="葵花粉";
			b1="kuihua fen";
		}

	random_a=random(3);
	if(random_a==1)
	{
		a2="无花果";
		b2="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a2="阴阳草";
			b2="yinyang cao";
		}
		else
		{
			a2="葵花粉";
			b2="kuihua fen";
		}

random_a=random(3);
	if(random_a==1)
	{
		a3="无花果";
		b3="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a3="阴阳草";
			b3="yinyang cao";
		}
		else
		{
			a3="葵花粉";
			b3="kuihua fen";
		}
random_a=random(3);
	if(random_a==1)
	{
		a4="无花果";
		b4="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a4="阴阳草";
			b4="yinyang cao";
		}
		else
		{
			a4="葵花粉";
			b4="kuihua fen";
		}
		random_a=random(3);
	if(random_a==1)
	{
		a5="无花果";
		b5="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a5="阴阳草";
			b5="yinyang cao";
		}
		else
		{
			a5="葵花粉";
			b5="kuihua fen";
		}
	message_vision("\n$N对$p娇声说道：你需按照计量和顺序去炼丹，千万错不得。\n"
		HIW"炼药的秘方是"+a1+"、"+a2+"、"+a3+"、"+a4+"、"+a5+"，每当你辟邪剑法提高时就吃一个。\n"NOR
		"\药方我只说一次，忘记了可就永远练不成了，切记。\n"
		"\好了，我该去找莲亭了，他近来处理教务甚是辛苦，我得多关心他。\n"
		"$N往外走了出去。\n",ob,me);
		
		me->set("drug_list/1",b1);
		me->set("drug_list/2",b2);
		me->set("drug_list/3",b3);
		me->set("drug_list/4",b4);
		me->set("drug_list/5",b5);
		me->delete("can_dfbb");
		destruct(this_object());

	return 1;
}

int ask_pixie()
{
	object book;
	object me = this_player();
	object ob = this_object();
	
	if(me->query_skill("pixie-jian", 1) <1)
	{
		message_vision("$N对$p娇声说道：你并未练习辟邪剑法呀，问奴家这个做甚？\n", ob,me);
		return 1;
	}
	if(me->query_skill("pixie-jian", 1) <120)
	{
		message_vision("$N对$p娇声说道：你辟邪剑法修为太差，多多练习再来问奴家吧。\n", ob,me);
		return 1;
	}
	if(me->query("can_dfbb")!=1)
	{
		message_vision("$N对$p娇声说道：你为我日月神教所做事情甚少，问我这个做甚？\n", ob,me);
		return 1;
	}

	
	if(me->query("canuse_cixin")==1&&me->query("canuse_guimei")==1)
	{
		message_vision("$N对$p娇声说道：你已领悟辟邪剑法的精要，奴家没有什么可以传授你的了。\n", ob,me);
		return 1;
	}
    if ( query("book_count") <0)
	{
		message_vision("$N对$p娇声说道：今天奴家身子不适，什么问题也不愿意回答。\n", ob,me);
		return 1;

	}
	if(me->query("canuse_guimei")==1)
	{

		book = new(__DIR__"obj/cixin_book");
		book->move(me);
        add("book_count", -1);
		message_vision("$N对$p娇声说道：这里有本小册子，你拿去看吧，也许对你辟邪剑法会有提高。\n", ob,me);
		book->set("master",me->query("id"));


	}
	else{
		book = new(__DIR__"obj/guimei_book");
		book->move(me);
        add("book_count", -1);
		message_vision("$N对$p娇声说道：这里有本小册子，你拿去看吧，也许对你辟邪剑法会有提高。\n", ob,me);
		book->set("master",me->query("id"));


	}
		message_vision("$N对$p娇声说道：好了，我该去找莲亭了。\n", ob,me);
		message_vision("$N往外走了出去。\n", ob,me);
		me->delete("can_dfbb");
		destruct(this_object());
		return 1;

}

