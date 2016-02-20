//Cracked by Roath
// genu.c
// xQin 7/00
#include <ansi.h>
inherit NPC;
string ask_me();
int accept_object(object who, object ob);

void create()
{
        set_name("小莲",({ "xiao lian", "genu","girl"}) );
        set("title", CYN"歌女"NOR);
        set("gender", "女性" );
        set("age", 17);
        set("long", "她是一个以卖唱为生的妙龄少女，手中轻抚琵琶，歌喉婉转，令人不由自主的为之心动。\n"
                    "只需五两白银，她就会为你歌舞一曲。\n");
        set_temp("apply/defense", 5);
        set("combat_exp", 700);
        set("shen_type", 1);
        set("per", 23);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 20);
        set("attitude", "friendly");
        set("inquiry", ([
        "演奏" : (: ask_me :),
        "play" : (:ask_me:),
        "唱歌" : (:ask_me:),
        "pipa" : "这把琵琶乃是当年小天女萧琴所赠，唉，如此珍品也只应天上有。\n",
        "琵琶" : "这把琵琶乃是当年小天女萧琴所赠，唉，如此珍品也只应天上有。\n",
        "卖唱" : "小女子以卖唱为生，这位"+RANK_D->query_respect(this_player())+"捧个场好吗？\n",
        
        ]));

        setup();
        carry_object("/d/city/npc/obj/pipa")->wield();
	carry_object("d/quanzhou/npc/obj/red_cloth")->wear();
        carry_object("/d/city/npc/obj/qupu2");
}
int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 500) 
        {
        who->set("fee_paid",1);
	}
	tell_object(who, "小莲躬身作了个揖。\n");
	return 1;
	
}
string ask_me()
{ 
        object me, ob, *obs;
        me = this_player();

	                
        if (me->query("fee_paid", 1)) 
	{
	switch( random(7) ) {
	case 0:
		command ("chang dongxian_ge");
		me->delete("fee_paid", 1);
		break;
	case 1: 
		command ("chang caisang_zi");
		me->delete("fee_paid", 1);
		break;
	case 2: 
		command ("chang dielian_hua");
		me->delete("fee_paid", 1);
		break;
	case 3: 
		command ("chang shuidiao_getou");
		me->delete("fee_paid",1);
		break;
	case 4: 
		command ("chang zuichui_bian");
		me->delete("fee_paid", 1);
		break;
	case 5: 
		command ("chang yujie_xing");
		me->delete("fee_paid", 1);
		break;
	case 6:
		command ("chang san_tai");
		me->delete("fee_paid", 1);
		break;


}
	return "小女子献丑了。";
	}
}