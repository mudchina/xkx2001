//Cracked by Roath
// /kungfu/class/emei/ji.c 纪晓芙
// xuy: 96/11/22

#include <ansi.h>

inherit F_UNIQUE;
inherit NPC;
inherit F_MASTER;

int auto_perform();
string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
	"/d/shaolin/fzlou",
	"/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/taishan/huima",
        "/d/huashan/laojun",
        "/d/village/square",
        "/d/xingxiu/tianroad3",
        "/d/forest/bank3",
        "/d/emei/baoguomen",
        "/d/emei/xixiang",
        "/d/qilian/qilian",
	"/d/dali/wangfu1",
	"/d/xixia/square",
});

void create()
{
        set_name("纪晓芙", ({ "ji xiaofu", "ji", "xiaofu" }));
        set("long", 
		"她是金鞭纪家的峨嵋派弟子纪晓芙。她肤色雪白，长挑身材，是个美貌女郎。\n");
	set("gender", "女性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 50000);

	set("str", 29);
	set("int", 20);
	set("con", 28);
	set("dex", 29);
	set("per", 30);
	
	set("max_qi", 1400);
	set("max_jing", 1400);
	set("jiali", 90);
	set("neili", 2400);
	set("max_neili", 2400);

	set("combat_exp", 950000);
	set("score", 5000);

	set_skill("beauty", 120);
        set_skill("force", 120);
        set_skill("linji-zhuang", 120);
        set_skill("strike", 120);
        set_skill("jinding-zhang", 120);
        set_skill("finger", 120);
        set_skill("tiangang-zhi", 120);
        set_skill("blade", 110);
        set_skill("sword", 130);
        set_skill("yanxing-dao", 110);
        set_skill("emei-jian", 130);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("zhutian-bu", 120);
        set_skill("throwing", 110);
        set_skill("persuading", 120);

        map_skill("force", "linji-zhuang");
        map_skill("finger", "tiangang-zhi");
        map_skill("strike", "jinding-zhang");
        map_skill("blade", "yanxing-dao");
        map_skill("sword", "emei-jian");
        map_skill("parry", "emei-jian");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("finger", "tiangang-zhi");
	prepare_skill("strike", "jinding-zhang");

	create_family("峨嵋派", 4, "弟子");

        set("inquiry", ([
		"出家" : "你去峨嵋山的庵堂里找我静字辈师妹吧。她们在福寿庵、千佛庵、\n万年庵、万行庵和卧云庵修行。\n",
            "灭绝师太" : "她是本派掌门人，在华藏庵修行。\n",
        ]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("stay_chance", 1);

	set("no_clean_up", 1);
	setup();
        ::create();
	carry_object("/clone/weapon/ruanjian")->wield();
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}

void init() 
{
	::init();
	set_heart_beat(1);
}

int chat()
{
        object *inv, me = this_object();
	object where = environment();
	object *chars = ({});
	object *injured = ({});
	object target;
	int i;

	if (!clonep()) return 1;

	::chat();

	if (add("tick", 1)%3 == 1) return 1;
	
	inv = all_inventory(where);

	for(i=0;i<sizeof(inv);i++)
	    if ((string)inv[i]->query("race") == "人类"
	      && inv[i] != me )
		if (inv[i]->is_fighting()) {
		    chars += ({inv[i]});
		    if ( interactive(inv[i]) ) 
			chars += ({inv[i], inv[i]});
		} 
		else if ((interactive(inv[i]) || inv[i]->query("family/family_name") == "峨嵋派")
		      && inv[i]->query("eff_qi")<inv[i]->query("max_qi")) {
		    injured += ({inv[i]});
		    if (inv[i]->query("family/family_name") == "峨嵋派" 
		     || inv[i]->query_temp("last_persuader") == "ji xiaofu" )
			injured += ({inv[i], inv[i]});
		}

	if (sizeof(chars)>0 && !me->query_temp("persuading")) {
		add("stay_chance", 2);
		if ( me->is_busy() ) return 1;
		target = chars[random(sizeof(chars))];
		remove_call_out("do_persuade");
		call_out("do_persuade", 1, me, target);
	} else if (sizeof(injured)>0 && !me->is_fighting() ) {
		target = injured[random(sizeof(injured))];
		me->set("neili", me->query("max_neili"));
		message_vision(CYN"$N对$n说道：“这位"
		        +RANK_D->query_respect(target)
			+"受伤不轻，让我给你运功疗伤。”\n"NOR,
			me, target);
		command("exert lifeheal "+target->query("id"));
		set("jiali", 90);
	}

	add("stay_chance", -1);
	if ((int)query("tick") > 600 ) { 
		set("tick", 0);
		return_home(where);
	}
		
	if (sizeof(chars)<1 && me->query("stay_chance")<1) 
	{
		set("stay_chance", 1+random(3));
		random_move();
	}

	if ( !me->query_temp("weapon") ) {
		me->carry_object("/clone/weapon/ruanjian");
		command("wield ruanjian");
	}

	return 1;
}

int do_persuade(object me, object target)
{
	if (objectp(target) && target->is_fighting()) {
		target->delete_temp("last_persuader");
		command("persuade " + target->query("id"));
		remove_call_out("do_persuade");
		call_out("do_persuade", 3, me, target);
	}
	return 1;
}

int accept_kill(object who)
{
	object me = this_object();
	if (who->is_killing(me->query("id")) ) return 0;
	remove_call_out("do_persuade");
	call_out("do_persuade", 1, me, who);
	return 1;
}

int return_home(object home)
{
	        // Are we at home already?
        if( !environment()
        ||      environment()==home )
                return 1;

        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting() ) return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                environment(), this_object());
	
	home = load_object(homes[random(sizeof(homes))]);
        if (home) return move(home);
	return 0;
}

#include "/kungfu/class/emei/sujia.h"
#include "/kungfu/class/emei/auto_perform.h"
