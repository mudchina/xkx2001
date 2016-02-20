//Cracked by Roath
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("Ô¬¹ÚÄĞ", ({ "yuan guannan", "yuan", "guannan" }) );
        set("gender", "ÄĞĞÔ" );
	set("title", "ÊéÉú");
        set("age", 24);
        set("long", 
	     "Ëû³¤Á³¿¡Ä¿£¬½£Ã¼ºá·É£¬ÈİÑÕ¼äÓ¢Æø±ÆÈË¡£\n");
        set("str", 30);
        set("dex", 30);
        set("con", 27);
        set("int", 35);
        set("shen_type", 1);

	set_skill("blade",70);
        set_skill("unarmed", 70);
        set_skill("force", 60);
        set_skill("dodge", 75);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
	set("max_neili",800);
	set("jiali",20);

        set("combat_exp", 50000);

        set("attitude", "friendly");

	setup();

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	  "Ô¬¹ÚÄĞ½ĞµÀ¡ºÅ®Ã²ÀÉ²ÅÖéÍòõú¡»\n",
	  "Ô¬¹ÚÄĞÊ¹Ò»ÕĞ¡ºÌì½ÌÀöÖÊÎª¾ìÊô¡»\n",
	  "¡ºÇå·çÒıÅåÏÂÑşÌ¨¡»£¡Ô¬¹ÚÄĞµÄµ¶ìªìªÉú·ç\n",
	  "Ô¬¹ÚÄĞµÀ£º¡ºÃ÷ÔÂÕÕ×±³É½ğÎİ¡»£¡\n",
	  "Ô¬¹ÚÄĞÊ¹Ò»ÕĞ¡¸Ï²½áË¿ÂŞÔÚÇÇÄ¾¡¹\n",
	  "Ô¬¹ÚÄĞµÀ£º¡¸Ó¢ĞÛÎŞË«·çÁ÷Ğö¡¹\n",
          "Ô¬¹ÚÄĞµÀ£º¡¸È´ÉÈ¶´·¿È¼»¨Öò¡¹\n",
          "Ô¬¹ÚÄĞµÀ£º¡¸±ÌóïÉùÀïË«Ãù·ï¡¹\n",
          "Ô¬¹ÚÄĞµÀ£º¡¸½ñ³¯ÓĞÅ®ÑÕÈçÓñ¡¹\n",
          "Ô¬¹ÚÄĞ½ĞµÀ£º¡¸Ç§½ğÒ»¿ÌÇìÁ¼Ïü¡¹\n",
          "Ô¬¹ÚÄĞ½ĞµÀ£º¡¸Õ¼¶ÏÈË¼äÌìÉÏ¸£¡¹\n",
          "Ô¬¹ÚÄĞ½ĞµÀ£ºµ¶¹âÑÚÓ³¿×È¸ÆÁ¡¹\n",
	}));

        set("chat_chance", 5);
        set("chat_msg", ({
             "Ô¬¹ÚÄĞ³¤ÉùÒ÷µÀ£º¡¸»Æ½ğÖğÊÖ¿ìÒâ¾¡£¬×òÈÕÆÆ²ú½ñ³¯Æ¶£¬ÕÉ·òºÎÊÂ¿ÕĞ¥°Á£¿²»ÈçÉÕÈ´Í·ÉÏ½í¡­¡­¡¹\n",
	}));
        carry_object("/d/city/obj/cloth")->wear();
	if (clonep()) 
	carry_object("/clone/unique/yuandao", "/clone/weapon/gangdao")->wield();
	add_money("gold",1);
}

int accept_kill()
{
	object wife;

	if (wife=present("xiao zhonghui", environment(this_object()))) {
		remove_call_out("killhim");
		call_out("killhim",1,wife, this_player());
	}
	return 1;
}

void killhim(object wife, object badguy)
{
	message_vision("$N´óºğÒ»Éù£º¡¸ĞİÒªÉËÎÒÏà¹«£¡¡¹\n",wife);
	wife->kill_ob(badguy);
}
