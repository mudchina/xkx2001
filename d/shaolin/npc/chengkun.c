//Cracked by Roath

#include <ansi.h>
inherit NPC;
#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();

string ask_me(object who);

void create()
{
	set_name("圆真大师", ({ "yuanzhen dashi", "yuanzhen" }) );
	set("title", "少林派第三十六代弟子");
	set("gender", "男性" );
	set("shen_type", -1);
	set("age", 70);
	set("str", 30);
	set("con", 30);
	set("dex", 30);
	set("int", 25);
	set("long",
		"这是一个身材瘦削的老僧，一脸阴鸷险刻之气。\n" );

	set("combat_exp", 1800000);
	set("attitude", "peaceful");
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	set("inquiry", ([
		"成昆"   : (: ask_me :),
		"chengkun" : (: ask_me :),
	]) );

        set("max_qi", 3000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("class", "bonze");
        set_skill("force", 170);
        set_skill("cuff", 180);
        set_skill("whip", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);

        set_skill("buddhism", 150);
        set_skill("hunyuan-yiqi", 170);
        set_skill("jingang-quan", 180);
        set_skill("riyue-bian", 180);
        set_skill("shaolin-shenfa", 180);

        map_skill("force", "hunyuan-yiqi");
        map_skill("cuff",  "jingang-quan");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "riyue-bian");
        map_skill("dodge", "shaolin-shenfa");

        prepare_skill("cuff", "jingang-quan");

	setup();	
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
		if( is_killing(who) ) 
			return "你既然知道了我的身分，今日休想活命！\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "我就是昔年江湖上人称的＂混元霹雳手＂成昆！\n";
		}
	}

	if( (random(10) < 7) || is_fighting() )
		return "贫僧实在对施主所问之事一无所知。\n";

	set_temp("apply/armor", 100);
	set_temp("apply/dodge", 100);
//	set_temp("apply/damage",  100);

        set_name("成昆", ({ "cheng kun", "cheng", "kun" }) );
	set("nickname", HIY "混元霹雳手" NOR);

	message("vision",
		HIW"圆真眼中突然放出异样的光芒，冷笑一声：既然你已看了出来？\n"
		"那你也不用再找了，明年今日就是你的周年！\n" NOR,
		environment(), this_object() );

	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);

	set("bellicosity", 10000);

//	set_leader(this_player());
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}

	set("revealed", 1);
	return "我就是昔年江湖上人称的＂混元霹雳手＂成昆！\n";
}

void unconcious()
{
        object obj, me;

        me = this_object();
        if (objectp(obj = me->query_temp("last_damage_from")))
                obj->set_temp("kill_chengkun",1);
        ::unconcious();
}
