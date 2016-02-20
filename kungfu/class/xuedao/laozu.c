//Cracked by Roath
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;
int auto_perform();
string ask_me();
void create()
{
	set_name("血刀老祖", ({ "xuedao laozu", "xuedao", "laozu" }));
	set("long", 
"这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。 \n");
	set("gender", "男性");
	set("age", 80);
	set("attitude", "friendly");
	set("class","lama");

	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3000);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("apply/armor", 100);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
        set_skill("lamaism", 300);
	set_skill("cuff", 300);
	set_skill("yujiamu-quan", 300);
	set_skill("xue-dao", 300);
	set_skill("xueshitiao", 300);
	set_skill("shenkongxing", 300);
	set_skill("longxiang-banruo", 300);

	map_skill("force", "longxiang-banruo");
	map_skill("blade", "xue-dao");
	map_skill("dodge", "xueshitiao");
	map_skill("parry", "xue-dao");
	map_skill("cuff", "yujiamu-quan");

	prepare_skill("cuff", "yujiamu-quan");
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );	
	set("inquiry", ([
	"血刀门" : "咱们这一派是西藏青教中的一支，叫做血刀门。你祖师爷\n"
		   "爷我是这一门的第四代掌教，你好好学功夫，第五代掌教就说不定落在你身上。\n",
        "血刀" : "这柄宝刀每奉月圆之际，须割人头相祭，否则锋锐顿减，与刀主不利。\n",
	"血刀密藉" : "找宝象他们要去。\n",
	"祭刀" : (: ask_me:),
	]) );

	create_family("血刀门", 4, "掌门人");

	set("blade_count", 1);
	setup();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
 	if (clonep()) carry_object("/clone/unique/xuedao"); 
}
void attempt_apprentice(object ob)
{
        if (ob->query("gender")=="女性") {
                command ("say 本派不收女弟子，你回去吧。");
                return;
        }

	if( ob->query("family/family_name") != "雪山派"
        && ob->query("family/family_name") != "血刀门"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }
        if ((int)ob->query("shen") > -100000) {
                command("say 小兄弟在我们黑道里混事儿，做得可不够呀。");
                return;
        }
        else if ((int)ob->query_skill("longxiang-banruo", 1) < 60
	&& (int)ob->query_skill("xiaowuxiang", 1) < 60){
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在加深一点内功修为？");
                return;
        }
        command("say 好吧，老祖我就收下你了。");
        command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam;
	object ob, me = this_player(); 

/*
        if (!(fam = this_player()->query("family")) ||
	fam["family_name"] !="血刀门")
                return RANK_D->query_respect(this_player()) +
                "打听我门派的机密干什麽？";
*/  
	if (!present("xue dao", this_object()))
                return "时辰未到不祭刀。";

if(present("liu chengfeng", environment(me)))
	{ 
if  (present("lu tianshu", environment(me))) 
		{
if  (present("hua tiegan", environment(me))) 
			{ 
      if (present("shui dai", environment(me))) 
	{
        add("blade_count", -1);
	me->add_temp("jidao", 4);
	command ("drop dao");
	command ("rumor "+this_player()->query("name")+"弄到了一把血刀。");
	return "哈哈哈，小崽子居然也知道替老夫操心祭刀之事，可嘉可嘉！ 好！你操上这把血刀把我的心事了了吧。";
	}
	else
	return "时辰未到不祭刀。";
	}
	else
        return "时辰未到不祭刀。";
        }
	else
        return "时辰未到不祭刀。";
        }
else
        return "时辰未到不祭刀。";
        }

#include "/kungfu/class/xuedao/auto_perform.h"	
int accept_kill(object me)
{
        command("say 老佛爷我正想找人杀呐，今天算你倒霉。\n");
        if (present("xue dao", this_object())){
        command("wield dao");
        }
        kill_ob(me);
        return 1;
}
