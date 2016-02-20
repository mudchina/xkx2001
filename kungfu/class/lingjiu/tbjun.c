// /d/lingjiu/npc/tbjun.c 钧天部 程清霜
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
string ask_me(string name);
void greeting(object);
void init();
void create()
{
	set_name("程青霜", ({ "cheng qingshuang", "cheng"}));
	set("long",
	    "她是「灵鹫宫」九天九部中钧天部的副首领。\n"+
	    "负责守卫「灵鹫宫」。\n");
	set("title", "钧天部副首领");
	set("gender", "女性");
	set("age", 20);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 23);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 20);

	set("combat_exp", 300000);
	set("combat_exp", 700000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("literate",100);
	set_skill("music",100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

        set("inquiry", ([
		"weapon" : (: ask_me, "ljjian1" :),
		"武器" : "你需要什么武器呢？\n",
        ]));
	set("wuqi_count", 10);

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("灵鹫宫",4,"弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",25);
}
string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有这样武器吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("wuqi_count") < 1)
		return "抱歉，你来得不是时候，武器已经发完了。";

	ob = new("/clone/weapon/changjian");
	ob->move(this_player());

	add("wuqi_count", -1);

	message_vision("程青霜给$N一件" + ob->query("name") + "。\n", this_player());

	return "拿去吧。好好练功，保卫灵鹫宫。";
}
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "灵鹫宫") 
             {
               message_vision("程青霜冲着$N点点头，微微笑了笑。\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name"))
             {
               message_vision("程青霜冲着$N微笑说：你是来拜师的吧，拜我吧。\n",ob);
               return;
              }
}
#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"