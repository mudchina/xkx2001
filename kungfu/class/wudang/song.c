//Cracked by Roath
// song.c 宋远桥

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
        set_name("宋远桥", ({ "song yuanqiao", "song" }));
        set("nickname", "武当首侠");
        set("long", 
                "他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
                "只见他身穿一件干干净净的灰色道袍。看上去已年过五十，鬓边微见花白，\n"
                "三络长须垂胸，满脸红光，脸上神情冲淡恬和，相貌甚是清雅，身材却稍有\n"
                "肥胖，想是中年发福。\n" );
        set("gender", "男性");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 42);
        set("int", 40);
        set("con", 42);
        set("dex", 40);

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 120);
        set("combat_exp", 1100000);
        set("score", 60000);

        set_skill("force", 220);
        set_skill("taiji-shengong", 220);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 220);
        set_skill("taiji-quan", 220);
        set_skill("strike", 180);
        set_skill("mian-zhang",180);
        set_skill("parry", 200);
        set_skill("sword", 160);
        set_skill("taiji-jian", 160);
        set_skill("literate", 200);
        set_skill("taoism", 200);
        //set_skill("taiji-gong",200);


        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
	prepare_skill("strike", "mian-zhang");
        create_family("武当派", 2, "弟子");

        set("inquiry", ([
                "秘籍" : (: ask_me :),
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("book_count", 1);

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

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
                        "是否还应该在武当九阳功上多下点功夫？");
                return;
        }

        if ((int)ob->query("shen") < 35000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，今天就收下你了。");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob, *obs;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

        if (query("book_count") < 1)
                return "你来晚了，本派的内功心法不在此处。";

        obs = filter_array(children(__DIR__"force_book.c"), (: clonep :));
        if (sizeof(obs) > 2)
                return "你来晚了，本派的内功心法不在此处。";

        ob=new(__DIR__"force_book");
        ob->move(this_player());
        add("book_count", -1);
        command ("rumor "+this_player()->query("name")+"弄到了一册太极十三式。");
        return "好吧，这本「太极十三式」你拿回去好好钻研。";
}

#include "/kungfu/class/wudang/auto_perform.h"
