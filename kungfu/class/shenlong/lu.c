//Cracked by Roath
//  lugaox.c  Â½¸ßĞù

inherit NPC;
// inherit F_MASTER;

string ask_jieyao();
string ask_sheyao();
string ask_huang();
string ask_book();
void apply_gift(object, int);

string *lujob = ({
        "/d/shenlong/obj/fengchao",
        "/d/shenlong/obj/hougan",
});

void create()
{
        set_name("Â½¸ßĞù", ({ "lu gaoxuan","lu" }));
        set("long",
                "ËÄÊ®À´ËêÄê¼Í£¬ÎÄÊ¿´ò°ç£¬ÉñÇéºÍ°ª¿ÉÇ×¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 41);
        set("attitude", "peaceful");

        set("shen_type", -1);
        set("score", 50000);
        set("shen", -15000);

        set("str", 36);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("jiali", 60);
        set("combat_exp", 160000);

        set_skill("force", 100);
        set_skill("dulong-dafa", 80);
        set_skill("dodge", 100);
        set_skill("lingshe-shenfa", 80);
        set_skill("strike", 80);
        set_skill("huagu-mianzhang", 80);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("medicine", 80);
        set_skill("literate", 90);
//      set_skill("digging", 100);
//      set_skill("magic", 50);
//      set_skill("shenlong-magic", 50);

        set_temp("apply/attack", 60);
        set_temp("apply/damage", 40);
        set_temp("apply/dodge", 50);

        map_skill("force", "dulong-dafa");
        map_skill("dodge", "lingshe-shenfa");
        map_skill("strike", "huagu-mianzhang");
        map_skill("parry", "huagu-mianzhang");
//      map_skill("magic", "shenlong-magic");

        prepare_skill("strike", "huagu-mianzhang");

        create_family("ÉñÁú½Ì", 2, "½ÌÖÚ");
        set("inquiry", ([
                "½âÒ©" : (:ask_jieyao:),
                "±ªµ¨Ò×½îÍè" : (:ask_jieyao:),
                "Ò½¾­" : (: ask_book :),
                "yishu"  : (: ask_book :),
                "ÉßÒ©" : (: ask_sheyao :),
                "ĞÛ»Æ" : (: ask_huang :),
        ]));

        set("chat_chance", 5);
        set("chat_msg", ({
                "Â½´ó·ò×ÔÑÔ×ÔÓïµÀ£ºÔÆÄÏÒ»´ø²è»ªÉ½ÀïÒ»¶¨ÓĞÉÏµÈ·ä³²¡£\n",
                "Â½´ó·ò×ÔÑÔ×ÔÓïµÀ£ºÎäÒÄÉ½ÄÇÖ»Ç§Äêºï¾«²»ÖªËÀÁËÃ»ÓĞ¡£\n",
        }) );

        set("book1_count", 1);
        set("book2_count", 1);
        set("book3_count", 1);

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( (int)ob->query_temp("mark/Â½") < 1 )
                return 0; 
        ob->add_temp("mark/Â½", -1);
        return 1;
}

string ask_huang()
{
        object ob, me = this_player();

        if( !me->query("sg/spy") ) 
                return RANK_D->query_respect(me) +
                "Óë±¾½ÌËØÎŞÀ´Íù£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";

        if(  present("xionghuang", me) )
                return RANK_D->query_respect(this_player()) + "ÄãÏÖÔÚÉíÉÏ²»ÊÇĞÛÆÂğ£¬ÔõÃ´ÓÖÀ´ÒªÁË£¿ÕæÊÇÌ°µÃÎŞ÷Ğ£¡";

        if( time() < me->query("huang/time") + 1800 )
                return RANK_D->query_respect(me) + "Äã²»ÊÇ¸ÕÒª¹ıĞÛ»Æ£¬ÔõÃ´ÓÖÀ´ÒªÁË£¿¹ı¶ÎÊ±¼äÔÙÀ´°É¡£";

        me->set("huang/time", time()); 
        ob = new("/d/shenlong/obj/xionghuang");
        ob->move(me);
        return "ºÃ°É£¬Õâ¿éĞÛ»ÆÄã¾ÍÄÃÈ¥°É¡£";
}

string ask_sheyao()
{
        object me = this_player();

        if( !me->query("sg/spy") ) 
                return RANK_D->query_respect(me) + "Óë±¾½ÌËØÎŞÀ´Íù£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";

        if( !me->query_condition("snake_poison") )
                return"ÄãºÃºÃµÄ£¬ÒªÉßÒ©¸ÉÂğ£¿";

        if( me->query("gender") == "ÄĞĞÔ" )
                say("ºÙºÙ£¬ÕæÃ»³öÏ¢£¬ÎªÁË·½¹ÃÄïÁ¬Ãü¶¼²»ÒªÁË£¿\n");
        else    say("Ì¾£¡ÊÇ²»ÊÇ·½¹ÃÄïÓÖÆÛÎêÄãÁË£¿\n");

        message_vision("$N¶Ô$nËµµÀ£º°Ñ×ìÕÅ¿ª¡£\n", this_object(), me);
        message_vision("$N°Ñ×ìÕÅµÃ´ó´óµÄ¡£\n", me);
        message_vision("Ö»¼û$N°ÑÒ»°üÉßÒ©È«µ¹½ø$n×ìÀï\n", this_object(), me);
        message_vision("$NÀÖ²»¿ÉÖ§µØ¶Ô$nËµµÀ£º¶àĞ»Â½´ó·ò£¡\n", me, this_object()
);

        call_out("lucure", 1 + random(2), me);
        return "ÏÂ´ÎĞ¡ĞÄÁË¡£";
}

void lucure(object me)
{
        message_vision("$NÍÂ³öÒ»¿ÚºÚÑª£¬Á³É«¿´ÆğÀ´ºìÈó¶àÁË¡£\n", me);
        me->clear_condition("snake_poison");
}

string ask_jieyao()
{
        object ob, me = this_player();

        if( !me->query("yijin_wan") )
                return "½âÒ©ÔõÃ´ÄÜËæ±ãÂÒ³Ô£¿\n";
/*
        if( (int)me->query("combat_exp") < 100000 )
                return "Æ¾ÄãÕâµãµÀĞĞ£¬Ò²¸ÒÀ´¿úÊÓ½âÒ©£¿\n";
*/
        if( (int)me->query_temp("lu/jieyao") )
	        return "ÄãÃ»ÓĞÕÒµ½Ê¶µÃ¼×¹ÇÎÄµÄĞĞ¼Ò£¿\n";

        command("sigh");
        say("Â½¸ßĞùËµµÀ£ºÒª²»ÊÇÎÒÆŞ¶ù¿ØÖÆÔÚ½ÌÖ÷ÊÖÀï£¬ÎÒÔçÀë¿ªÉñÁú½ÌÁË¡£\n");

        ob = new("/d/shenlong/obj/zihua");
        ob->move(me);
        me->set_temp("lu/jieyao", 1);
        message_vision("$N½«Ò»" + ob->query("unit") + ob->query("name") + "½»¸ø$n¡£\n", this_object(), me);
        return "Èç¹ûÄãÄÜ·ÃµÃÒ»Î»Ê¶µÃ¼×¹ÇÎÄµÄĞĞ¼Ò½«ËüÒë³öÀ´£¬ÎÒ¾Í¸øÄã½âÒ©¡£\n";
}

string ask_book()
{
        object ob, *obs, me = this_player();
        int lvl;
        
        if( !me->query("yijin_wan") )
                return RANK_D->query_respect(this_player()) + 
                "Óë±¾½ÌËØÎŞÀ´Íù£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";

        if( (int)me->query("sg/exp") < 1000 )
                return "¾ÍÆ¾" + RANK_D->query_respect(this_player()) + "ÔÚ½ÌÖĞµÄ±íÏÖ£¬Ò½¾­Ö®ÊÂ¾ÍÃâÌ¸ÁË¡£";

        lvl = me->query_skill("medicine", 1);

        if( lvl < 30 ) {
                if( query("book1_count") < 1 )
                        return "ÄãÀ´ÍíÁË£¬ÄãËùĞèÒªµÄÒ½¾­ÒÑ¾­ÓĞÈËÄÃ×ßÁË¡£";
                obs = filter_array(children("/d/shenlong/obj/yijing1.c"), (: clonep :));
                if( sizeof(obs) )
                        return "ÄãÀ´ÍíÁË£¬ÄãËùĞèÒªµÄÒ½¾­ÒÑ¾­ÓĞÈËÄÃ×ßÁË¡£";
                ob = new("/d/shenlong/obj/yijing1");
                ob->move(me);
                add("book1_count", -1);
                return "ºÃ°É£¬Õâ±¾¡º»ÆµÛÄÚ¾­¡»ÄãÄÃ»ØÈ¥ºÃºÃ×êÑĞ¡£";
        } else if( lvl < 60 ) {
                if( query("book2_count") < 1 )
                        return "ÄãÀ´ÍíÁË£¬ÄãËùĞèÒªµÄÒ½¾­ÒÑ¾­ÓĞÈËÄÃ×ßÁË¡£";
                obs = filter_array(children("/d/shenlong/obj/yijing2.c"), (: clonep :));
                if( sizeof(obs) )
                        return "ÄãÀ´ÍíÁË£¬ÄãËùĞèÒªµÄÒ½¾­ÒÑ¾­ÓĞÈËÄÃ×ßÁË¡£";
                ob = new("/d/shenlong/obj/yijing2");
                ob->move(me);
                add("book2_count", -1);
                return "ºÃ°É£¬Õâ±¾¡ºÊ®ËÄ¾­·¢»Ó¡»ÄãÄÃ»ØÈ¥ºÃºÃ×êÑĞ¡£";
        } else if( lvl < 90 ) {
                if( query("book3_count") < 1 )
                        return "ÄãÀ´ÍíÁË£¬ÄãËùĞèÒªµÄÒ½¾­ÒÑ¾­ÓĞÈËÄÃ×ßÁË¡£";
                obs = filter_array(children("/d/shenlong/obj/yijing3.c"), (: clonep :));
                if( sizeof(obs) )
                        return "ÄãÀ´ÍíÁË£¬ÄãËùĞèÒªµÄÒ½¾­ÒÑ¾­ÓĞÈËÄÃ×ßÁË¡£";
                ob = new("/d/shenlong/obj/yijing3");
                ob->move(me);
                add("book3_count", -1);
                return "ºÃ°É£¬Õâ±¾¡ºËïË¼åãÇ§½ğ·½¡»ÄãÄÃ»ØÈ¥ºÃºÃ×êÑĞ¡£";
        }

        return "¸óÏÂÊìÖªÒ½Àí£¬ÎÒÕâ¶ùÃ»ÓĞºÏÊÊµÄÒ½¾­¿É¹©Äã×êÑĞ¡£";
}

int accept_object(object who, object ob)
{
        mapping my;
        int i, tot, bonus;

        if( who->query_temp("lu/jieyao") && ob->name() == "ËÌ´Ê" ) {
                who->delete("yijin_wan");
                my = who->query_entire_dbase();
                tot = my["str"] + my["int"] + my["con"] + my["dex"];
                tot -= 80;
                if( tot > 0 ) {
                        for(i = 0; i < tot; i ++) {
                                switch (random(4)) {
                                        case 0: my["str"]--; break;
                                        case 1: my["int"]--; break;
                                        case 2: my["con"]--; break;
                                        case 3: my["dex"]--; break;
                                }
                        }
		}
                            
                who->delete("sg");
                who->delete("sgjob");
                who->set("sg/cured", 1);
                who->delete("yijin_wan");
                apply_gift(who, 0);

                command("touch " + who->query("id"));
                message_vision("Â½¸ßĞù´ÓÒÂ´üÀïÌÍ³öÒ»Á£Ò©ÍèÈû½øÁË$NµÄ×ìÀï¡£\n", who);
                command("whisper " + who->query("id") + " " + "´ËÊÂ¿ÉÇ§Íò²»ÄÜÕÅÑï³öÈ¥¡£\n");

                call_out("destroy", 1, ob);
                return 1;
        }

        if( member_array(base_name(ob), lujob) == -1 )
                return 0;

        command("nod");
        call_out("destroy", 1, ob);

        if( ob->query("owner") != who->query("id") ) {
                command("say ºÇ£¬ºÇ£¬ºÇ£¬ÄãÔËÆøÕæºÃ¼ñÁËÒ»" + ob->query("unit") + ob->query("name") + "¡£");
                return 1;
        }

        if( (bonus = who->query("combat_exp")) > 100000 ) {
                command("say ÕâÖÖĞ¡ÊÂÒÔºó¾Í²»ÓÃÄã²ÙÀÍÁË¡£");
                return 1;
        }

        if( random(6) )
        who->add("sg/exp", 1);

        bonus = 50 + (100000 - bonus) / 200;
        who->add("combat_exp", bonus + random(bonus));
        who->add_temp("mark/Â½", bonus/10);
        return 1;
}

void destroy(object ob)
{
        destruct(ob);
}

void apply_gift(object me, int flag)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex;
        mapping my = me->query_entire_dbase();

        tmpstr = tmpint = tmpcon = tmpdex = 10 + flag;

        for (i = 0; i < 40; i++) {
                switch (random(4)) {
                        case 0: tmpstr++; break;
                        case 1: tmpint++; break;
                        case 2: tmpcon++; break;
                        case 3: tmpdex++; break;
                }
        }

        if (tmpstr <= 30) my["str"] = tmpstr;   else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint;   else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon;   else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex;   else my["dex"] = 30;
}

