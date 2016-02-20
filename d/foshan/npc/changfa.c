//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("戚长发", ({ "qi changfa", "qi", "changfa" }) );
        set("gender", "男性" );
	set("nickname","铁锁横江");
        set("age", 48);
        set("long", 
	     "一个老头儿，嘴里咬着一根短短的旱烟袋，手中打着草鞋。偶尔抬起头来，"
             "向正在练剑的女儿瞧上一眼。淡淡的阳光穿过他口中喷出的一缕缕青烟"
	     "，照在他满头白发和满脸皱纹之上。但见他向吞吐伸缩的竹剑上"
	     "瞥上一眼之时，眼中神光炯然，凛凛有威。\n");
        set("shen_type", 0);

        set("combat_exp", 90000);

        set("attitude", "friendly");
	set("inquiry", ([
            	"铁锁横江" : "江湖上的朋友送我这个绰号，是说我长于防守。\n",
		"连城剑法" : "连城剑法我也不会，不过我的躺尸剑法也很厉害。\n",
                "连城剑" : "连城剑法我也不会，不过我的躺尸剑法也很厉害。\n",
		"唐诗选辑" : "我不识字，从不读诗。\n",
                "躺尸剑法" : "我的这套剑法一出就让敌人变成尸体躺下，够威风吧。\n",
		"干活" : "你去我房后的菜园帮我浇肥把。\n",
		"工作" : "你去我房后的菜园帮我浇肥把。\n",
		"戚芳" : "便是小女，你想帮她找个婆家吗？\n",
	]));

	set("max_neili",1000);
	set("neili",1000);
	set("jiali",50);
        set_skill("strike", 60);
	set_skill("force",60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
	set_skill("tangshi-jian",60);
	map_skill("sword","tangshi-jian");
        map_skill("parry","tangshi-jian");
	set_skill("club",60);

        create_family("连城派", 5, "弟子");


        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/yanguan")->wield();
}

void attempt_apprentice(object ob)
{
        command("shake");
	command("say 拜师就不用了。你如有空帮我干点儿杂活，我就教你武艺。");
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("qi/work")){
		tell_object(ob, "戚长发说：你还是先帮我干点儿活吧。");
                return 0;
	} 
        ob->add_temp("qi/work", -1);
        return 1;
}

