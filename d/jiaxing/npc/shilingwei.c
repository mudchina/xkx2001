//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("施令威",({ "shi lingwei","shi" }) );
        set("gender", "男性");
        set("age", 55);
	set("long",
		"他目光炯炯，步履稳重，显是武功不低。\n");
        set("nickname","五路神");
        set("title","梅庄家人");
        set("combat_exp", 45000);
        set("shen_type", 0);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
	set_skill("force",60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
	set_skill("blade",60);

	set("max_neili",300);
	set("neili",300);
	set("jiali",30);


        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}


