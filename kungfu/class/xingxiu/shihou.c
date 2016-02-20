//Cracked by Roath
// shihou.c 狮吼子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("狮吼子", ({ "shihou zi", "shihou" }));
        set("nickname", "星宿派二师兄");
        set("long", 
                "他就是丁春秋的二弟子狮吼子。\n"
                "他狮鼻阔口，一望而知不是中土人士。\n");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 20);
        set("con", 26);
        set("dex", 22);
        
        set("max_qi", 1500);
        set("max_jing", 500);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 40);
        set("combat_exp", 200000);
        set("score", 30000);

        set_skill("force", 120);
        set_skill("huagong-dafa", 120);
        set_skill("dodge", 120);
        set_skill("zhaixinggong", 120);
        set_skill("poison", 70);
        set_skill("strike", 120);
        set_skill("parry", 120);
        set_skill("chousui-zhang", 120);
        set_skill("staff", 120);
        set_skill("tianshan-zhang", 120);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");

        create_family("星宿派", 2, "弟子");

        setup();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}

void attempt_apprentice(object me)
{
        if( me->query("family/family_name") == "丐帮"
        && me->query("combat_exp") >= 10000 ) {
                command ("say 我们老仙最恨叫化子，我可不敢收你。");
                return;
	}
	
	if ((int)me->query("shen") > -10000) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }
	
        command("say 好吧，我就收下你了。");
        command("recruit " + me->query("id"));
}
