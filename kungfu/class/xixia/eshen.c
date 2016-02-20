//Cracked by Roath
inherit NPC;
int auto_perform();
int ask_me();

void create()
{
	set_name("ÄÏº£öùÉñ", ({ "nanhai eshen", "eshen"}));
	set("nickname", "Ğ×Éñ¶ñÉ·");
	set("long", 
"´ËÈËµÄÒ»¸öÄÔ´ü´óµÃÒìºõÑ°³££¬Ò»ÕÅÀ«×ìÖĞÂ¶³ö°×É­É­µÄÀû³İ£¬Ò»¶ÔÑÛ¾¦È´ÊÇÓÖÔ²ÓÖĞ¡¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 700000);
	set("env/wimpy", 40);
	set_temp("apply/armor", 70);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
                "ÄÏº£öùÉñËµµÀ£ºËûÂèµÄ£¬ÄÄ¸ö¸Ò²»ÌıÀÏ×ÓµÄ»°£¬±»ÀÏ×Ó¾¾×¡£¬¿¦àêÒ»ÏÂÅ¤¶ÏÁËËûµÄ²±×Ó¡£\n",
                "ÄÏº£öùÉñÍ»È»·¢Å­´óÉùµÀ£º¡±ÀÏ×ÓÊÇÔÀÀÏ¶ş£¬²»ÊÇÔÀÀÏÈı£¡\n",
		"ÄÏº£öùÉñÍ»È»Ğ¡ÑÛÖĞ¹âÃ¢ËÄÉä£¬ÏòÄãÁ³ÉÏ¹ÇÂµÂµÒ»×ª£¬Äã²»ÓÉµÃ´òÁË¸öº®Õ½¡£\n", 
        }) );

 set("inquiry", ([
	"²âÊÔ" : (: ask_me :),
	"²âÊÔÎä¹¦" : (: ask_me :),
        ]));

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("ding-dodge", 150);
	set_skill("ding-force", 150);
	set_skill("ding-unarmed", 150);
	set_skill("strike", 150);
	set_skill("blade", 150);
	set_skill("canglang-bian", 150);
	set_skill("luan-blade", 150);
	set_skill("whip", 150);

	map_skill("dodge", "ding-dodge");
	map_skill("blade", "luan-blade");
	map_skill("parry", "luan-blade");
        map_skill("force", "ding-force");
	map_skill("whip", "canglang-bian");
        map_skill("unarmed", "ding-unarmed");

	setup();
	switch( random(2) )
        {
                case 0:
                         if (clonep()) carry_object("/clone/unique/eweibian", "/clone/weapon/changbian")->wield();
			 if (clonep()) carry_object("/clone/unique/eyujian", "/clone/weapon/gangdao");
                         break;
                case 1:
                         if (clonep()) carry_object("/clone/unique/eyujian", "/clone/weapon/gangdao")->wield();
			 if (clonep()) carry_object("/clone/unique/eweibian", "/clone/weapon/changbian");
			 break;
        }
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
}


int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "blade" )
	command("cut " + target->query("id"));
	return;
	}
}

int ask_me()
{
object me=this_player();
if ((int)me->query_temp("marks/Î÷ÏÄnan")) 
	{	
say("ÄÏº£öùÉñ¿ñĞ¦ÁËÒ»Õó£ºÄãÒªÊÇ²»ÅÂËÀ£¬¾ÍÊÔÊÔ(accept test)£¬¿´ÀÏ×Ó²»Å¡¶ÏÁËÄãµÄ²±×Ó£¿\n");
	return 1;
	}
/* else	{
	say("ÄÏº£öùÉñÅ­ºÈµÀ£º¹ö£¬ÀÏ×ÓĞÄ·³£¬²»¹ö¿´ÀÏ×ÓÒ»ÏÂÅ¡¶ÏÄãµÄ²±×Ó£¡\n");
	return 1;
	}ı
*/
}

int do_accept(string arg)
{
        mapping guild;
	object me=this_player();
if (!(int)me->query_temp("marks/Î÷ÏÄnan")) 
return notify_fail ("ÄãÏ¹ÊÔÊ²Ã´£¿\n");
        

        if( arg== "test" ) {
                say("\nÄÏº£öùÉñµãÁËµãÍ·£¬ËµµÀ£ººÜºÃ£¬ÕâÊÇµÚÒ»ÕĞ....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("ÄÏº£öùÉñÌ¾ÁË¿ÚÆø£¬ËµµÀ£ºÁ¬µÚÒ»ÕĞ¶¼³Å²»¹ı£¬ÕæÊÇ×Ô²»Á¿Á¦....\n");
                        return 1;
                }
                say("\nÄÏº£öùÉñËµµÀ£ºÕâÊÇµÚ¶şÕĞ....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("ÄÏº£öùÉñ¡¸ºß¡¹µØÒ»Éù£¬ËµµÀ£º±ãÊÇÓĞÕâĞí¶à²»ÅÂËÀµÄ¼Ò»ï....\n");
return 1;
                }
                say("\nÄÏº£öùÉñËµµÀ£ºµÚÈıÕĞÀ´ÁË....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
		COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("ÄÏº£öùÉñÌ¾µÀ£º¿ÉÏ§£¬Ã»Å¡¶ÏÕâ¸ö¹ê¶ù×ÓµÄ²±×Ó....\n");
                        return 1;
                }

say("\nÄÏº£öùÉñÕö´óÁËÒ»Ë«¹ÖÑÛËµµÀ£ºËûÂèÂèµÄ£®£®£®£¡\n\n");
                this_player()->set_temp("xixia/testpass", 2);
                this_player()->delete_temp("marks/Î÷ÏÄnan");
		return 1;
        }
        return 0;
}

