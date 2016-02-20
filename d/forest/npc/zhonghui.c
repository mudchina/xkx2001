//Cracked by Roath
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("萧中慧", ({ "xiao zhonghui", "xiao", "zhonghui" }) );
        set("gender", "女性" );
        set("age", 18);
        set("long", 
	     "她姓萧名中慧，她爹爹便是晋阳大侠萧半和。\n");
        set("str", 25);
        set("dex", 30);
        set("con", 27);
        set("int", 30);
        set("shen_type", 1);

	set_skill("blade",60);
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("dodge", 75);

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 400);
	set("max_neili",400);
	set("jiali",20);

        set("combat_exp", 40000);

        set("attitude", "friendly");

	setup();

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	  "萧中慧叫道『女貌郎才珠万斛』\n",
	  "萧中慧使一招『天教丽质为眷属』\n",
	  "『清风引佩下瑶台』！萧中慧的刀飒飒生风\n",
	  "萧中慧道：『明月照妆成金屋』！\n",
	  "萧中慧使一招「喜结丝罗在乔木」\n",
	  "萧中慧道：「英雄无双风流婿」\n",
          "萧中慧道：「却扇洞房燃花烛」\n",
          "萧中慧道：「碧箫声里双鸣凤」\n",
          "萧中慧道：「今朝有女颜如玉」\n",
          "萧中慧叫道：「千金一刻庆良宵」\n",
          "萧中慧叫道：「占断人间天上福」\n",
          "萧中慧叫道：刀光掩映孔雀屏」\n",
	}));

        carry_object("/d/city/obj/pink_cloth")->wear();
	if (clonep())
	carry_object("/clone/unique/yangdao", "/clone/weapon/gangdao")->wield();
}

int accept_kill()
{
	object hus;

	if (hus=present("yuan guannan", environment(this_object()))) {
		remove_call_out("killhim");
		call_out("killhim",1,hus, this_player());
	}
	return 1;
}

void killhim(object hus, object badguy)
{
	message_vision("$N大吼一声：「休要伤我娘子！」\n",hus);
	hus->kill_ob(badguy);
}
