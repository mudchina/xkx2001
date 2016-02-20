//Cracked by Roath
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("¸ÇÒ»Ãù", ({ "gai yiming","gai" }) );
	set("gender", "ÄĞĞÔ");
	set("age", 25);
	set("long",
		"Ëû¶ÌĞ¡¾«º·£¬ÏÂ°Í¼âÏ÷£¬ËµÆğ»°À´Ï¸ÉùÏ¸Æø¡£\n");
	set("nickname","°Ë²½¸Ïó¸¡¢Èü×¨Öî¡¢Ì¤Ñ©ÎŞºÛ¡¢¶À½ÅË®ÉÏ·É¡¢Ë«´Ì¸ÇÆßÊ¡");
	set("title","Ì«ÔÀËÄÏÀ");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  20);
	set("apply/defense", 20);

	set("chat_chance", 15);
	set("chat_msg", ({
		"¸ÇÒ»ÃùÒ»°Ú¶ëÃ¼´Ì£¬Ï¸ÉùÏ¸ÆøµÄµÀ£º¡¸ÄãÓĞÊ²÷á±¦±´£¬¸øÎÒÃÇÁôÏÂ°É£¡¡¹\n",
		"¸ÇÒ»ÃùË«´ÌÒ»»÷£¬¶£¶£×÷Ïì¡£\n",
	}) );

	set_skill("sword", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	setup();
        carry_object(__DIR__"obj/emeici")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
