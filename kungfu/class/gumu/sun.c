// sun.c 孙婆婆
// 15/7/2001  by xuanyuan

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("孙婆婆", ({"sun popo", "sun"}));
        set("gender", "女性");
        set("age", 55);
        set("long",
                "这是一位慈祥的老婆婆，正看着你微微一笑。\n"
        );
        set("attitude", "friendly");

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 40);

        set("combat_exp", 150000);
        set("score", 0);

        set_skill("force", 80);
        set_skill("yunu-xinjing", 60);   
        set_skill("sword", 90);
        set_skill("yunu-jianfa", 80);     
        set_skill("dodge", 70);
        set_skill("gumu-shenfa", 70);   
        set_skill("parry", 60);
        set_skill("cuff",80);
        set_skill("meinu-quan", 60);    
        set_skill("literate",40);

        map_skill("force", "yunu-xinjing");
        map_skill("sword", "yunu-jianfa");
        map_skill("dodge", "gumu-shenfa");
        map_skill("parry", "meinu-quan");
        map_skill("cuff", "meinu-quan");

        set("inquiry", ([
                "小龙女" :  "龙姑娘是我一手带大的，她从小没了父母，现在又独个儿住在这古墓里，唉..\n",
		"玉蜂浆" : (: ask_me :),
        ]) );

	set("book_count", 1);
	set("jiang_count", 4);

        create_family("古墓派",2,"弟子");
        set("env/wimpy", 50);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/cloth")->wear();

}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
	object obj, *obs;

	if (!fam || fam["family_name"] != "古墓派"){
                command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                return;
                }
	if(fam["master_name"] == "李莫愁") {
		command("say 你是那个叛徒的徒弟，我岂能收你！");
		return;
		}       
	if((int)ob->query_skill("yunu-jue", 1) < 60) {
                command("say 你的玉女二十四诀修为尚浅，领悟不了我的功夫。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在玉女二十四诀上多下点功夫？");
                return;
                }
/*
	if (query("book_count") > 0){
		command("sigh");
		command("say 虽然" + RANK_D->query_respect(ob) + "也是我辈中人，但林祖师去后，我没什么能教你的。");
		command("say 不过你我今日相见也是有缘，这本「玉女二十四诀下卷」就送于你钻研，也不枉你我相识一场。");
		obj=new("/d/zhongnan/obj/yunu_book2");
		obj->move(this_object());
		add("book_count", -1);
		command ("give book to "+this_player()->query("id")+"");
                return;
	}
		command("sigh");
		command("say 虽然" + RANK_D->query_respect(ob) + "也是我辈中人，但林祖师去后，我没什么能教你的。");
*/

	if (query("book_count") < 1){
		command("sigh");
		command("say 虽然" + RANK_D->query_respect(ob) + "也是我辈中人，但林祖师去后，我没什么能教你的。");
                return;
	}
	obs = filter_array(children("/d/zhongnan/obj/yunu_book2.c"), (: clonep :));
        if (sizeof(obs) > 2){
		command("sigh");
		command("say 虽然" + RANK_D->query_respect(ob) + "也是我辈中人，但林祖师去后，我没什么能教你的。");
                return;
	}
		command("sigh");
		command("say 虽然" + RANK_D->query_respect(ob) + "也是我辈中人，但林祖师去后，我没什么能教你的。");
		command("say 不过你我今日相见也是有缘，这本「玉女二十四诀下卷」就送于你钻研，也不枉你我相识一场。");
		obj=new("/d/zhongnan/obj/yunu_book2");
		obj->move(this_object());
		add("book_count", -1);
		command ("rumor "+this_player()->query("name")+"弄到了一册玉女二十四诀下卷。");
		command ("give book to "+this_player()->query("id")+"");
}

string ask_me()
{
	mapping fam; 
	object ob, *obs;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if(fam["master_name"] == "李莫愁") 
		return "你是那个叛徒的徒弟，想要老太婆我给你玉蜂浆那是万万不可能的！";

	if (query("jiang_count") < 1)
		return "你来晚了，玉蜂浆已经都给了你的师姐师妹们了。";

	if ( (int)this_player()->query("eff_qi")==(int)this_player()->query("max_qi") ) {
                message_vision("$N向$n脸上仔细地打量了一阵，便皱起眉头。\n", this_object(), this_player());
                return "你并未受伤，要玉蜂浆干吗？\n";
        }

	ob=new("/clone/drug/yufeng-jiang");
	ob->move(this_player());
	add("jiang_count", -1);
	return "这是我们古墓派的疗伤灵药，你拿去好好服用。";
}
