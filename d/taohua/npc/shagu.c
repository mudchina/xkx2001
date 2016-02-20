//Cracked by Roath
// Kane

inherit NPC;
#include <ansi.h>
int auto_perform();
string ask_rudao();

void create()
{
        set_name("傻姑", ({ "sha gu", "sha", "gu" }));
        set("long",
"她曲灵风的女儿，幼时似乎受了惊吓，脑子受损，智力与常人相比差了很多。\n"
"她相貌平平，脸上总带着天真的傻笑，嘴里哼着儿歌。\n");
        set("gender", "女性");	
	set("age", 20);
	set("attitude", "heroism");
	set("shen_type", 0);
	set("str", 35);
	set("int", 10);
	set("con", 30);
	set("dex", 10);
	
	set("max_qi", 1100);
	set("max_jing", 800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 300);
	set("combat_exp", 50000);
/*
	set_temp("apply/armor", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
*/	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
        set_skill("pike", 100);
	set_skill("halberd", 100);
	set_skill("strike", 100);
	
	set("inquiry", ([
        "玩" : (: ask_rudao :),
        "玩一会" : (: ask_rudao :),
        "玩一会儿" : (: ask_rudao :),
	]));

	create_family("桃花岛", 3, "弟子");
	set("amulet_count", 1);

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	carry_object("/d/taohua/obj/huocha")->wield();
}

void init()
{
        ::init();
        add_action("do_agree", "agree");
}

string ask_rudao()
{
        object me, obj;

        me = this_player();
        
	if( me->query_temp("play_with_shagu") > 3 + random(4) 
	&& query("amulet_count") > 0 ) {
		command("say 你陪我玩得真够久的，送你样东西吧。\n");
		obj = new("/d/taohua/obj/amulet");
		obj->move(me);
		me->delete_temp("play_with_shagu");
		add_temp("amulet_count", -1);
		message_vision("$N递给$n一个长命锁。\n", this_object(), me);
	}
		
	if( me->query("family/master_name") == "程英"
        || me->query("family/master_name") == "黄药师" ) {
                return "你不是桃花岛的人吗？这里的人都很聪明，不会和傻姑玩的。\n你真笨，比傻姑还笨！";
        }

	me->set_temp("pending/rudao", 1);
	return "爷爷说不能让不三不四的人上岛，如果你能挨我几下揍，\n就让你过去，愿意(agree)的话，告诉我。\n"; 
}


int do_agree()
{
	int i, k;

	write(CYN"\n傻姑拍着手高兴的跳起来，大叫道：开打啦！开打啦！\n"NOR);
	
        set_temp("apply/armor", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);

	k = 5+random(6);
        if( !this_player()->query_temp("pending/rudao") )
                return 0;
	for (i = 0; i < k; i++) {
		if( (int)this_player()->query("qi") < 0
                || !present(this_player(), environment())) {
		write(CYN"\n傻姑拍着手高兴的跳起来，大叫道：打跑啦！打跑啦！不三不四的家伙打跑啦！\n"NOR);                        
		        delete_temp("apply/armor");
			delete_temp("apply/attack");
			delete_temp("apply/defense");
			return 1;
                }
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon")); 
	}

	write(CYN"\n傻姑撅了撅嘴，说道：好吧，你就过去吧，记得以後再来找我玩儿。\n"NOR);	
	this_player()->set_temp("shagu_pass", 1);	

        delete_temp("apply/armor");
        delete_temp("apply/attack");
        delete_temp("apply/defense");
	return 1;
}


int accept_fight(object me)
{
	command("say 好耶！好耶！又有人陪我玩了！\n");
	call_out("play_with_shagu", 10, me);
	return 1;
}

int accept_kill(object me)
{
        if (me->query("family/family_name") == "桃花岛"){
        command("say 你我本是同门，如何要加害于我！\n");
        me->set_temp("th_killer", 1);
        kill_ob(me);
        return 1;
        }
        return 0;
}

int play_with_shagu(object me)
{
        if( !me->is_fighting(this_object()) )
                return;
	command("say 好玩！好玩！今天真好玩！");
	me->add_temp("play_with_shagu", 1);	
}
