//Cracked by Roath
// xiang.c  <-- 向问天, not  翔少爷.
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("向问天",({ "xiang wentian","xiang" }) );
        set("gender", "男性");
        set("age", 45);
	set("long",
		"他容貌清矍，一丛疏疏朗朗的花白长须垂在胸前，眼望远处"
		"黄土大地和青天相接之处。\n");
        set("nickname","天王老子");
        set("title","日月神教右使");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");
        set_skill("unarmed", 90);

	set_skill("force",90);
        set_skill("parry", 90);
        set_skill("dodge", 90);

	set("jing",35);
	set("max_jing",215);
	set("eff_jing",35);
	set("qi",100);
	set("eff_qi",100);
	set("con",-9);
//	set("max_neili",500);
//	set("neili",500);
	set("jiali",45);
       setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_yishang","yishang");
}

int accept_object(object me, object obj)
{
        switch ((string)obj->query("name")) {
	case "金创药":
       	message("vision",me->name()+"给向问天一包金创药。\n",environment(me),
	    ({me}));
	command("thank "+me->query("id"));
	if (!query("giveyao")) {
	  set("giveyao",1);
	  call_out("eatyao",1);
	  call_out("create_shashou",10);
	}
	return 1;
	case "铁球":
        message("vision",me->name()+"给向问天一只铁球。\n",environment(me),
            ({me}));
        command("say 这位"+RANK_D->query_respect(me)+"的救命之恩向某没齿不忘。");
	command("bow "+me->query("id"));
	command("look "+me->query("id"));
	command("ah");
	command("say 恩公看起来深受内伤。我有几个朋友身怀绝计，或许可以医得了"
		"恩公的伤，不知恩公愿去医伤(yishang)否？");
	me->set_temp("yishang",1);
	return 1;
	}
}

void eatyao()
{
	command("fu jin");
	return;
}

void create_shashou()
{
  object s1,s2,s3;
	say("突然从树林里冲出几个恶狠狠的劲装汉子。\n\n");

	s1 = new(__DIR__"shashou");
	s2 = new(__DIR__"shashou");
	s3 = new(__DIR__"shashou1");
	s1->move(environment(this_object()));
        s2->move(environment(this_object()));
        s3->move(environment(this_object()));

	return;
}
	
int do_yishang()
{
	object me=this_player();
	object o1,o2,o3,o4;

	if (!me->query_temp("yishang"))
		return 0;

	message("vision",me->name()+"随向问天走入林中。\n", environment(me),({me}));
	me->move("/d/jiaxing/mzgate");
	this_object()->move("/d/jiaxing/mzgate");

	write("你随着向问天来到一座庄院前。\n");
	command("say 梅庄四位庄主都身怀绝计，你若能嬴了他们，他们会替你医伤。");
	command("say 但他们轻易不出手。");
	o1 = new(__DIR__"obj/qipu");
	o2 = new(__DIR__"obj/xinglutu");
	o3 = new(__DIR__"obj/shuaiyitie");
	o4 = new(__DIR__"obj/guanglingsan");
	o1->move(me);
	o2->move(me);
	o3->move(me);
	o4->move(me);
        message_vision("$n递给了$N几样宝物。\n", me, this_object() );
        command("say 你到时把这几件宝物分别给几个庄主。");
	command("give qiu to "+me->query("id"));
	command("say 最後和地牢里的老头比剑前把这个铁球交给他。");
	command("bow "+me->query("id"));
	command("bye");
	destruct(this_object());
	return 1;
}
