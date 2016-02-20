//Cracked by Roath
//Ryu 6/22/97;
#include <ansi.h>;
inherit NPC;
string ask_me(object who);
int auto_perform();

void create()
{
	set_name("何师我", ({ "he shiwo", "he", "shiwo" }));
	set("shen_type", -1);
	set("title", "丐帮五袋弟子");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("dex", 28);
	set("gender", "男性");
	set("age", 35);
	set("long",
		"此人身披一件宽大破烂的黑衣，满头乱发，一张脸焦黄臃肿，凸凸凹凹满是疤痕。\n");
	set("combat_exp", 800000);
        set("max_qi", 1600);
        set("max_jing", 800);  
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);

        set_skill("force", 150);
	set_skill("longxiang-banruo", 150);
	set_skill("shenkongxing", 150);
	set_skill("staff", 150);
	set_skill("shexing-diaoshou", 150);
	set_skill("hand",150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
	set_skill("stick", 300);
	set_skill("jingang-chu", 150);

	map_skill("force", "longxiang-banruo");
        map_skill("dodge", "shenkongxing");
        map_skill("hand", "shexing-diaoshou");
	map_skill("staff", "jingang-chu");

        prepare_skill("hand", "shexing-diaoshou");

	set("attitude", "friendly");
	set("inquiry", ([
		"霍都" : (: ask_me :),
		"蒙古王子" : (: ask_me :),
	]));
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );	
	set("vendor_goods", ({
		__DIR__"obj/shaobing",
		__DIR__"obj/youtiao",
	}));

	setup();
	carry_object("/clone/weapon/tiezhang")->wield();
	carry_object("/d/gaibang/obj/budai")->set_amount(5);
	carry_object("/d/gaibang/obj/budai")->wear();
}

string ask_me(object who)
{
        int i;
	object cake;
	if (query("asked")) return ("少废话！\n");

        if( (random(10) < 5) || is_fighting() )
                return "我…不知道。\n";

        message("vision",
		"何师我道：你既然知道老子的名字，就会坏我大事！纳命来吧！\n"
                "霍都大喝一声，叫道：“既然如此，老子今天反正豁出去，跟你拼了。”\n" ,
                environment(), this_object() );

        set_name("霍都", ({ "huodu", "huo"}));
	kill_ob(this_player());
	command("follow " + this_player()->query("id"));
	command("drop tiezhang");
	message_vision(HIM"霍都从袖中掏出一柄摺扇，一挥，张了开来，露出扇上一朵娇艳欲滴的牡丹。\n"NOR, this_object());
        carry_object("/clone/unique/fan")->wield();
	carry_object("/d/gaibang/obj/yuzhu-zhang");
        return "你既然知道老子的名字，就会坏我大事！纳命来吧！\n";
}

void unconcious()
{
	object ob = this_object();

        message_vision("\n$N突然卖一破绽，跳出战圈，逃了！\n", ob);
	destruct(ob);
}
int auto_perform()
{
        object me = this_object();
        object weapon1, target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
        if ( weapon->query("skill_type") == "stick" )
	if( objectp(weapon1 = target->query_temp("weapon")))
        command("break " + target->query("id"));

	command("shoot " + target->query("id"));
        }
        return 1;
}

