//Cracked by Roath
#include <ansi.h>

inherit NPC;

int do_train(string);
int do_walkhorse();
void end_walkhorse(object, int);

int djobid = 1;

void create()
{
        set_name("Âí·ò", ({ "ma fu", "ma", "fu" }) );
        set("gender", "ÄÐÐÔ");
        set("age", 40);
        set("long",
"ÕâÊÇÒ»¸ö¿´ÆðÀ´ÀÏÀÏÊµÊµµÄÂí·ò£¬Ëû×¨ÃÅ¸ºÔð¸øÍõÒ¯ÑøÂí¡£\n");
 
        set("str", 30);
        set("int", 35);
        set("con", 25);
        set("dex", 35);
        set("attitude", "peaceful");
        set("combat_exp", 4000);
        set("title", "Æ½ÄÏÍõ¸®Âí·ò");
        set("inquiry", ([
               "name" : "ÎÒÊÇÍõÒ¯µÄÂí·ò£¬×¨ÃÅ¸ºÔðÑøÂí¡£",
                "here" : "ÕâÀïÊÇÂí³¡",
		"¹¤×÷" : "ºÃµÄºÜ£¬ÎÒÕâÀïÕýÈ±ÈËÊÖÄØ£¬ÎÒÕâÀïÓÐÁ½ÖÖ»î£¬Ò»ÖÖÊÇ\n"
			 "ÁïÂí(walkhorse)£¬ÄãÖ»Òª»¨ÉÏÒ»ÌìÇ£×ÅÂíµ½´¦¹ä¹ä¾ÍÊÇÁË¡£	\n"
			 "ÁíÒ»ÖÖÊÇÑµÂí(trainhorse)£¬Ã»Á©°ÑË¢×ÓÄã»¹ÊÇ±ðÉÏ¡£ \n",      
        ]));

        set("wanted", ({ "´óÀíÆ½ÄÏÍõ¸®Âí·ò" }));

        setup();
        }
void init()
{
        object me = this_player();
        mapping myfam;

        ::init();
        
        myfam = (mapping)me->query("family");

        add_action("do_train", "train");
        add_action("do_walkhorse", "walkhorse");
        if( interactive(me) && !is_fighting() )
        {
                remove_call_out("greeting");

                call_out("greeting", 1, me);
        }
}
void greeting(object me)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if( !me || environment(me) != environment() ) return;

        if ( myfam && myfam["family_name"] == "´óÀí¶Î¼Ò" )
	command("say ÕâÎ»" + RANK_D->query_respect(me)+ 
"ÇëÁË£¬»¶Ó­À´µ½ÑøÂí³¡£¡\n");
        else 
              
  command("say ÄãÊÇÊ²Ã´ÈË£¬Ë½´³»Ê¼ÒÖ®µØ£¬ÄãÏëÍµÂí²»³É£¡");
}


int do_walkhorse()
{
        object ob;
        string what;
        string *wanted;
	 mapping myfam;
	
	
        ob = this_player();
        myfam = (mapping)ob->query("family");

	if ( myfam && myfam["family_name"] != "´óÀí¶Î¼Ò" )
           {
     command("say ÕâÐ©¶¼ÊÇÍõÒ¯µÄ°®Âí£¬ÎÒ¿É²»·ÅÐÄ½Ì¸øÍâÈË£¡");
 return 1;
        }

        if ( ob->is_busy() || ob->is_fighting() )
        {
                tell_object(ob, "ÄãÏÖÔÚÕýÃ¦×Å£¡\n");
                return 1;
        }               
        if ( ob->query("djob/supervisor") )

        message_vision("$NÏë¸øÂí·òÁïÂí¡£\n", ob);

        if ( ob->query("djob/supervisor") )
        {
                command("say ÄÄÂí»¹ÂúÉíÔô±ìÄØ£¬Äã¾ÍÏë½»²î£¿");

                if ( ob->query("djob/supervisor") == "Âí·ò") 
                {
                        add_action("do_say", "say");
                        command("say Èç¹ûÄã¼±×ÅÈ¥Á·¹¦£¬Äã¿ÉÒÔ¸úÎÒËµÏëÏÈ×ß¡£");
                } else  
                        command("say Èç¹ûÄãÏëÏÈ×ß£¬¿ÉÒÔÖ±½ÓÈ¥¸æËß"+ob->query("djob/supervisor"));        
                
                return 1;
        }

	 if (query_temp("aaa") > 1)
        
        {
                command("say ×î½üÂí¶¼Í¦ºÃ£¬ÔÙÁï¾ÍµÃµô±ìÁË¡£");
                return 1;
        }

        add_temp("aaa", 1);

        wanted = query("wanted");
        what = wanted[random(sizeof(wanted))];

        ob->set("djob/supervisor", "Âí·ò");
        ob->set("djob/object", what);
        ob->set("djob/description", what);
        ob->set("djob/id", djobid);
        ob->set_temp("apply/short", 
                ({ HIW" ´óÀíÆ½ÄÏÍõ¸®Âí·ò"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
        
message_vision("Âí·ò¸ßÐË¶Ô$NËµµÀ£ºÀ´µÃÕýºÃ£¬ÕâÀïÕýÈ±ÈËÊÖ¡£\n", ob);
        command("say 
Äã¾ÍÔÚÕâÀïºÃºÃ°ïÎÒÃ¦°É£¡");

        call_out("end_walkhorse", 300, ob, djobid);
        djobid++;

        return 1;
}

void end_walkhorse(object who, int jobid)
{
        int i; 
        if ( !objectp(who) || !present(who, environment(this_object())) 
                || (string)who->query("djob/description") != 
"´óÀíÆ½ÄÏÍõ¸®Âí·ò"  
                || (int)who->query("djob/id") != djobid )
                return;

        
message_vision("Âí·ò¶Ô$NËµµÀ£ººÃ£¬ºÃ£¬Âí¿´À´ÓÐ¾«Éñ¶àÁË£¬Äã¿ÉÒÔ×ßÁË£¡\n", 
who);
        command("goodkid " + who->query("id"));
        
        who->delete_temp("apply/short");
        who->add("dali/jobdone", 1);
        who->delete("djob/supervisor");
        who->delete("djob/description");
        who->delete("djob/wage");
        who->delete("djob/object");
        who->delete("djob/id");
	who->add("max_jingli", 1);
        add_temp("aaa", -1);
}


int do_say(string arg)
{
    object ob, who;

    who = this_player();
    ob = this_object();

        if ( arg != "ÎÒÏëÏÈ×ß") return 0;

    if ( who->query("djob/supervisor") != ob->query("name")) return 0;

    message_vision("$NµÍÉùËµµÀ£ ÎÒÏëÎÒ»¹ÊÇÏÈÈ¥Á·Á·¹¦°É¡­\n", who);
    command("disapp "+ who->query("id"));
    command("say ÄãÕâÃ»³öÏ¢µÄ¶«Î÷£¬ÎÒ¿´ÄãÁ·¹¦Ò²Á·²»³öÊ²Ã´ÃûÌÃÀ´£¡");

        who->delete_temp("apply/short");

    this_object()->add_temp("aaa", -1);
    who->add("djob/fail", 1);
    who->delete("djob/supervisor");
    who->delete("djob/description");
    who->delete("djob/object");
    who->delete("djob/id");

    return 1;
}


int do_train(string arg)
{
        object me;
       	int a,b,c,d,reward;
	me=this_player();
        if ( !arg || arg != "horse" )
             return notify_fail( "Ñ±Ê²Ã´£¿\n");

        if (me->query_temp("trainhorse")) {
                if (me->is_busy())
                        return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");

        if ( me->query("djob/supervisor") )
                return notify_fail(" ÏÈÁïÍêÂíÔÙËµÑ±ÂíµÄÊÂ¡£");
        
                tell_object(me, "Äã¿ªÊ¼Õ½Õ½¾ª¾ªµÄÑ±ÂíÁË¡£\n");
  a = me->query_skill("force");
  b = me->query_skill("dodge");
  c = me->query_skill("finger");
  d = me->query_skill("kar");
  reward = random(3);	
if  (random(a+b+c+d) < 40)
{
message_vision("$N¸ÕÒ»¿¿½ü£¬ÓñæõÂíÁÌÆðÒ»õê×Ó°Ñ$NÌßÁËÒ»¸ö¸ú¶·£¬ÌÉÔÚµØÉÏ°ëÌìºßºßß´ß´ÅÀ²»ÆðÀ´¡£\n", me);
	        me->receive_damage("qi", 50);
		me->start_busy(25);
		me->delete_temp("trainhorse");
return 1;
}
if (random(a+b+c+d) > 40 && random(a+b+c+d) < 70){
message_vision("$NÐ¡ÐÄÒíÒíµÄÅÀÉÏÂí±³£¬È´±»ÓñæõÂíºöµÄÒ»¸öÈËÁ¢£¬Ë¤ÔÚµØÉÏ°ëÌìºßºßß´ß´ÅÀ²»ÆðÀ´¡£\n", me);
                me->receive_damage("qi", 50);
                me->start_busy(120);
		me->delete_temp("trainhorse");
return 1;
}
else
 {
message_vision("$NÓÃÁ³ÇáÇáµÄ²Á×ÅÓñæõÂí£¬µÍÉùËµµÀ£ºÄãºÃ¿É°®ßÏ¡£\n", me);
 tell_object(me, "¹±Ï²ÄãÑ±Âí³É¹¦¡£\n");

 me->add("max_jingli", reward);
me->start_busy(120);
me->add("dali/jobdone", 1);
 me->delete_temp("trainhorse");
}
return 1;
	}
}
