//Cracked by Roath
// /kungfu/class/wudang/yin.c 殷梨亭
// xQin 14/08/99
// xQin 15/2/99
// xQin 04/01

inherit NPC;
inherit F_MASTER;
string ask_me(object me);

int auto_perform();

void create()
{
        set_name("殷梨亭", ({ "yin liting", "yin" }));
        set("nickname", "武当六侠");
        set("long",
                "他就是张三丰的六弟子殷梨亭。\n"
                "他今年虽才三十多岁，但已经满面风尘之色，两鬓微见斑白。\n"
                "在武当七侠中排名第六，武当剑法尤为精通。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 32);
        set("int", 38);
        set("con", 36);
        set("dex", 38);

        set("max_qi", 2600);
        set("max_jing", 2200);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 100);
        set("combat_exp", 800000);
        set("shen", 80000);

        set_skill("force", 160);
        set_skill("taiji-shengong", 160);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
        set_skill("cuff", 120);
        set_skill("taiji-quan", 120);
        //set_skill("chang-quan", 120);
        set_skill("strike", 120);
        set_skill("mian-zhang",120);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        //set_skill("wudang-jian", 200);
//      set_skill("throwing", 100);
        set_skill("literate", 180);
        set_skill("taoism", 180);
       // set_skill("taiji-gong",140);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");

        create_family("武当派", 2, "弟子");


       
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("sword.shenmen") :),
        }) );


        set("inquiry", ([
                "天地同寿" : (: ask_me :),
                "纪晓芙" : "可怜我那未过门的妻子，居然被杨逍那淫徒。。。",
                "杨逍" : "总有一天我要手刃这魔教淫贼，以祭晓芙在天。。。",
		"神门十三剑" : "神门十三剑乃。。。 唉，可怜晓芙居然被杨消那淫徒。。。",

        ]));

	
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}



void attempt_apprentice(object ob)
{
        mapping fam;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "武当派" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "并非我门中人，习武还是先从各位道长起吧！");
                return;
        }

        if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
                command("say 我武当派乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }

        if ((int)ob->query("shen") < 80000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，我一定收你。");
                return;
        }
        command("sigh");
        command("say 虽然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，但自晓芙去后，我已无心收徒；不过你我今日"+
                "相见也是有缘，我就传你一式“天地同寿”，也不枉你我相"+
                "识一场。");

        ob->set("yinliting_teach",1);
}

string ask_me(object me)
{
        mapping fam; 
        me=this_player();
        
	if(me->query("family/family_name") != "武当派")
        {
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	}

	if(me->query_skill("taiji-shengong") < 60 )
	{
        command("say 我武当派乃内家武功，最重视内功心法。"); 
        return RANK_D->query_respect(me) + "是否还应该在太极神功上多下点功夫？";
	}

	if(me->query("shen") < 800000 )
	{
	command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
        return RANK_D->query_respect(me) + "若能做出" + "几件侠义之事，我一定收你。";
	}

	me->set("yinliting_teach", 1);
	command("sigh");
        return RANK_D->query_respect(me) + "也是" +
        "我辈中人，但自晓芙去后，我已无心收徒；不过你我今日"+
        "相见也是有缘，我就传你一式“天地同寿”，也不枉你我相"+
        "识一场。";
	
}