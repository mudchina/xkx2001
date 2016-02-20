//Cracked by Roath
// /d/changbai/npc/chan.c µ¥Õı
// ALN 1/98

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define SHANZHENG NPCDATA + "shan-zheng"

#define BANGJIAO  "/d/changbai/bj/"

#define BANGYIN   "/d/huanghe/obj/bangyin"
#define BANGYIN2  BANGJIAO + "bangyin2"
#define JIAN      BANGJIAO + "sword"
#define ZHANGLAO  BANGJIAO + "zhanglao"
#define LAMA      BANGJIAO + "lama"

#define BANGZHU   "/d/huanghe/npc/bangzhu"

inherit NPC;
inherit F_SAVE;

#include <ansi.h>
#include <room.h>
#include <localtime.h>

#include "/d/changbai/bj/info_bang.h"
#include "/d/changbai/bj/info_zhanglao.h"
#include "/d/changbai/bj/info_lama.h"
#include "/d/REGIONS.h"

string ask_bang(string);
string ask_bangyin();
string ask_jianghu();
string ask_jian();
string ask_mizong();

string query_save_file()
{
        return SHANZHENG;
}

void create()
{
        string *bangs;

        seteuid(getuid());

        if (!restore()) {
        set_name("µ¥Õı", ({ "shan zheng", "shan", "judge" }));
        set("nickname", "ÌúÃæÅĞ¹Ù");
        set("long", 
"ËûÉúÆ½¼µ¶ñÈç³ğ£¬Ö»ÒªÖªµÀ½­ºşÉÏÓĞÊ²Ã´²»¹«µÀÖ®ÊÂ£¬¶¨È»ÉìÊÖÒª¹Ü¡£\n"
"ËûÂúÁ³ºì¹â£¬µ±µÃÆğ¡°Í¯ÑÕº×·¢¡±ËÄ×Ö£¬ÉñÇéÈ´ÉõÇ«ºÍ£¬²»ËÆ½­ºşÉÏ´«ËµµÄ³öÊÖÎŞÇé¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 900);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 40);
        set("combat_exp", 400000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("wuxingbu", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("wuxing-quan", 120);
        set_skill("club", 100);
        set_skill("ding-force", 100);
        set_skill("liuhe-qiang", 120);

        map_skill("club", "liuhe-qiang");
        map_skill("parry", "liuhe-qiang");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("force", "ding-force");

        prepare_skill("cuff", "wuxing-quan");

        bangs = keys(info_bang);
        for(int i = 0; i < sizeof(bangs); i++) {
                set("inquiry/" + bangs[i], (: ask_bang, bangs[i] :));
        }

        setup();
        }
        else {
                set("id", "shan zheng");
                set_name(query("name"), ({ query("id") }));
                setup();
                clear_condition();  
        }

        set("chat_chance", 10);
        set("chat_msg",({
                (: random_move :)
        }));

        set("inquiry", ([
                "°ï" : (: ask_bang, "°ï" :),
                "Ğ°°ï" : (: ask_bang, "Ğ°°ï" :),
                "°ïÖ÷" : (: ask_bangyin :),
                "°ïÓ¡" : (: ask_bangyin :),
                "bangzhu" : (: ask_bangyin :),
                "½­ºş" : (: ask_jianghu :),
                "jianghu" : (: ask_jianghu :),
                "Ìú½£ÃÅ" : (: ask_jian :),
                "jian" : (: ask_jian :),
                "ÃÜ×Ú" : (: ask_mizong :),
                "ÃÜ×Ú¸ßÊÖ" : (: ask_mizong :),
                "¸ßÊÖ" : "½­ºşÍşÍûÀ´×ÔµÂĞĞ¶ø·ÇÎä¹¦¡£",
        ]));

        carry_object("/clone/weapon/panguanbi")->wield();
}

void init()
{
        add_action("do_sue", "sue");
}

int do_sue(string arg)
{
        object ob, obj, me = this_player();
        mapping sue, sue_site, sued;
        string my, your, *times, yourfam;
        int i, total, period;

        if( is_busy() || is_fighting() ) 
                return notify_fail("µ¥ÕıÕıÃ¦×Å¡£\n");

        if( !(ob = find_player(arg)) ) {
                ob = new(USER_OB);
                ob->set("id", arg);
                if( !ob->restore() ) {
                        command("say Ã»ÓĞÕâ¸öÈË¡£");
                        destruct(ob);
                        return 1;
                }
                ob->set_temp("insue", 1);
                call_out("do_destroy", 1, ob);
        }

        yourfam = (string)ob->query("family/family_name");
        if( ob->query("sell_woman/" + me->query("id"))
        &&  (int)ob->query("combat_exp") > 100000
        &&  (  yourfam == "ÉÙÁÖÅÉ"
            || yourfam == "¶ëáÒÅÉ"
            || yourfam == "Îäµ±ÅÉ"
            || yourfam == "»ªÉ½ÅÉ"
            || yourfam == "´óÀí¶Î¼Ò" ) ) {
                ob->delete("sell_woman/" + me->query("id"));
                ob->set("incharge", time());
                ob->save();
                command("nod");
                command("say ÎÒ½«×ª¸æÎåÔÀ½£ÅÉÕÆÃÅÈË×óÀäìø¡£");
                log_file("SuePK", sprintf("%sÓÚ%sÊ±ÆğËß%s··Âô¸¾Å®\n", me->query("name"), ctime(time()), ob->query("name")));
                return 1;
         }

        if( me->query_temp("my_killer") != ob->query("id") ) {
                command("say ×î½ü" + ob->query("name") + "Ã»ÓĞÉËº¦ÄãÑ½¡£");
                return 1;
        }

        if( me->query_temp("pking/" + ob->query("id")) ) {
                command("say Äã×Ô¼º´³µÄ»ö£¬²»ÄÜÔ¹±ğÈË¡£");
                return 1;
        }

        if( (int)ob->query("combat_exp") < (int)me->query("combat_exp") ) {
                command("say ÕâÖÖË½ÈË¶÷Ô¹Ì«¶àÁË£¬Äã»¹ÊÇ×ÔÇ¿²»Ï¢°¡£");
                return 1;
        }

        if( (int)me->query("combat_exp") > 300000 ) {
                command("say ÄãÒÑ¾­ÔÚÎäÁÖÖĞ³ÉÃûÁË£¬»¹ÊÇ×ÔÇ¿²»Ï¢°É¡£");           
                return 1;
	}

        start_busy(2);
        me->delete_temp("my_killer");

        my = me->query("id");
        your = ob->query("id");

        if( !mapp(sue = query("sue")) ) {
                sue = ([]);
                sue_site = ([]);
                sued = ([]);
        } else {
                if( !mapp(sue_site = query("sue_site")) ) sue_site = ([]);
                sued = query("sued");

                times = keys(sue);
                for(i = 0; i < sizeof(times); i++) {
                        if(time() > atoi(times[i]) + 86400) {
                                map_delete(sue, times[i]);
                                map_delete(sue_site, times[i]);
                                map_delete(sued, times[i]);
                        }
                }

                times = keys(sue);
                total = 0;
                for(i = 0; i < sizeof(times); i++) {
                        if( sue[times[i]] == my && sued[times[i]] == your ) {
                                command("say Äã²»¾ÃÇ°¸Õ¸æ¹ı´ËÈË£¬²»¹ıÏÖÔÚ»¹Ã»ÓĞµ÷²éÇå³ş¡£");
                                save();
                                return 1;
                        }

                        if( sue_site[times[i]] == query_ip_name(me) ) {
                                command("say ÄãµÄÅóÓÑ¸Õ¸æ¹ı´ËÈË£¬²»¹ıÏÖÔÚ»¹Ã»ÓĞµ÷²éÇå³ş¡£");
                                save();
                                return 1;
                        }

                        if( sued[times[i]] == your ) total++;
		}
        }

        command("nod");

        switch((string)ob->query("family/family_name")) {
	case "Îäµ±ÅÉ" : period = 10; break;
	case "ÉÙÁÖÅÉ" : period = 10; break;
        case "»ªÉ½ÅÉ" : period = 15; break;
        case "¶ëáÒÅÉ" : period = 15; break;
        case "ÌÒ»¨µº" : period = 20; break;
        case "Ø¤°ï"    : period = 20; break;
        case "°×ÍÕÉ½×¯" : period = 30; break;
        case "ĞÇËŞÅÉ" : period = 30; break;
        default              : period = 25; break;
        }

        if( random(total) >= period/2 ) {
                command("say ÎÒ½«×ª¸æÎäµ±ÕÆÃÅÈËÕÅÈı·áºÍÎåÔÀ½£ÅÉÕÆÃÅÈË×óÀäìø£¬ÓÉËûÃÇÁ½Î»ÎäÁÖÁìĞäÈËÎï´¦Àí´ËÊÂ¡£");
                ob->set("incharge", time());
                ob->save();

                log_file("SuePK", sprintf("%sÓÚ%sÊ±¸æµ¹%s\n", me->query("name"), ctime(time()), ob->query("name")));            

                for(i = 0; i < sizeof(times); i++) {
                        if( sued[times[i]] == your ) {
                log_file("SuePK", sprintf("%sÒ²ÓÚ%s±»%s´Ó%sÆğËß¹ı\n", ob->query("name"), ctime(atoi(times[i])), sue[times[i]], sue_site[times[i]]));
                                map_delete(sue, times[i]);
                                map_delete(sue_site, times[i]);
                                map_delete(sued, times[i]);
                        }
                }
                save();

                if( ob->query_temp("insue") ) 
                        return 1;

                message_vision("$N´Ò´ÒÃ¦Ã¦Àë¿ªÁË¡£\n", this_object());
                move("/d/wudang/xiaoyuan");
                message_vision("$N×ßÁË¹ıÀ´¡£\n", this_object());

                if( obj = present("zhang sanfeng", environment()) ) {
                        message_vision("$N¶Ô$nËµµÀ£º×î½üÕÅÕæÈË±ğÀ´ÎŞí¦£¿Ö»ÊÇ" + ob->query("name") + "ÔÚÎäÁÖÖĞ²ĞÉ±ÎŞ¹¼£¬»¹ĞèÕÅÕæÈË³öÃæ´¦Àí´ËÊÂ¡£\n", this_object(), obj);
                        message_vision("$NËµµÀ£º´ËÄËÎÒÎäµ±·İÄÚÖ®ÊÂ£¬µ¥ÅĞ¹Ù²»Ø¿ÍÆø£¬ÎÒÁ¢¼´¾ÍÈ¥´¦Àí¡£\n", obj);

                        message_vision("$N´Ò´ÒÃ¦Ã¦Àë¿ªÁË¡£\n", obj);
                        obj->move(environment(ob));
                        message_vision(HIR"\n$N¶Ô$nºÈµÀ£º" + RANK_D->query_rude(ob) + "¾ÓÈ»¸ÒÎ£º¦ÎäÁÖ£¬ÊµÔÚÊÇËÀÓĞÓà¹¼¡£\n"NOR, obj, ob);
                        obj->set_leader(ob);
                        obj->kill_ob(ob);
                }

                message_vision("$N´Ò´ÒÃ¦Ã¦Àë¿ªÁË¡£\n", this_object());
                move("/d/taishan/daizong");
                message_vision("$N×ßÁË¹ıÀ´¡£\n", this_object());
                return 1;    
        }

        command("say µÈµ÷²éÇå³ş£¬ÎäÁÖÖĞ×ÔÓĞÈËÌæÄã³öÃæ¡£");
        set("sue/" + time(), my);
        set("sue_site/" + time(), query_ip_name(me));
        set("sued/" + time(), your);
        save();
        return 1;
}

int accept_object(object who, object ob)
{
        object room;
        int exp, p_exp, bonus, record, period;
        string my_id, file = base_name(ob);

        switch(file) {
        case JIAN:
                if( ob->query("my_killer") != who->query("id") )
                        return notify_fail("ÕâÖÖÃ°ÃûµÄÊÂ£¬ÄãÒ²¸É£¿£¡\n");

                if( (int)who->query("combat_exp") < 300000 )
                        return notify_fail("Ò»¶¨ÊÇÃ°Ãû°É¡£\n");

                command("touch " + who->query("id"));
                command("say Ìú½£ÃÅÖÕÓÚÓĞ¾ÈÁË£¡");

                period = time() - (int)who->query("shan/time4");
                if( period > 480 ) period = 480;
                if( period <  60 ) period =  60;

                bonus = (int)ob->query("bonus") * period / 600;
                record = bonus + random(bonus);
                who->add("combat_exp", record);

                who->set("shan/time4", time());
                log_file("test/ShanBonus", sprintf("%sÓÚ%sÊ±ÉÏ½»ÁË%s£¬ÄÃÁË%s¾­Ñéµã\n", who->query("name"), ctime(time()), ob->name(), chinese_number(record)));
                call_out("do_destroy", 1, ob);
                return 1;

	case BANGYIN:
                my_id = who->query("id");
                if( ob->query("my_killer") != my_id )
                        return notify_fail("ÕâÖÖÃ°ÃûµÄÊÂ£¬ÄãÒ²¸É£¿£¡\n");

                if( !( room = find_object("/d/taishan/fengchan")) )
                        room = load_object("/d/taishan/fengchan");
                if( my_id == room->query("winner") )
                        return notify_fail(RANK_D->query_respect(who) + "ÊÇµ±½ñÎäÁÖÃËÖ÷£¬ÎÒĞ¡Ğ¡Ò»¸öÅĞ¹ÙÆñÄÜ¶ÔÄúËµÈıµÀËÄ£¿");

                if( !( room = find_object("/d/taishan/xiayi")) )
                        room = load_object("/d/taishan/xiayi");
                if( my_id == room->query("winner") )
                        return notify_fail(RANK_D->query_respect(who) + "ÊÇµ±½ñÎäÁÖÃËÖ÷£¬ÎÒĞ¡Ğ¡Ò»¸öÅĞ¹ÙÆñÄÜ¶ÔÄúËµÈıµÀËÄ£¿");

                if( !( room = find_object("/d/taishan/zhengqi")) )
                        room = load_object("/d/taishan/zhengqi");
                if( my_id == room->query("winner") )
                        return notify_fail(RANK_D->query_respect(who) + "ÊÇµ±½ñ·£¶ñÊ¹Õß£¬ÎÒĞ¡Ğ¡Ò»¸öÅĞ¹ÙÆñÄÜ¶ÔÄúËµÈıµÀËÄ£¿");

                exp = (int)ob->query("combat_exp");
                p_exp = (int)who->query("combat_exp");

                if( p_exp > exp + 1000 ) {
                        command("nod");
                        command("say Õâ¶ÔÄãÀ´ËµÊÇĞ¡ÊÂÒ»×®£¬ÎÒ¾Í²»¿äÄãÁË¡£");
                        call_out("do_destroy", 1, ob);
                        return 1;
                }

                command("thumb " + who->query("id"));
                if( (string)who->query("family/family_name") != "Îäµ±ÅÉ" )
                        who->add("shen", exp / 100);

                bonus = 10 + 200 * exp / (exp + p_exp);

                record = bonus + random(bonus);
                who->add("combat_exp", record);

                log_file("test/ShanPlaying", sprintf("%sÓÚ%sÊ±ÄÃÁË%s¾­Ñéµã£¬ÉÏ½»ÁË%s", who->query("name"), ctime(time()), chinese_number(record), ob->query("long")));
                call_out("do_destroy", 1, ob);
                return 1;
        }

        return notify_fail("µ¥ÕıËµµÀ£ºÕâ²»ÊÇÎÒÏëÒªµÄ¡£\n");
}

void do_destroy(object ob)
{
        destruct(ob);
}

// job1
string ask_bang(string name)
{
        object *obj, room;
        string *bangs, str, region, file;
        int i, temp;

        if( name == "°ï" ) 
                return "½­ºşÉÏÓĞ" + chinese_number(sizeof(info_bang)) + "¸öĞ°°ï°ïÖ÷¾­³£¸ãÂÒ£¬ÓĞ" + chinese_number(sizeof(empty_bangs)) + "¸ö°ïÃ»ÓĞµÃÁ¦µÄ°ïÖ÷ÕÆ¹Ü¡£";

        if( name == "Ğ°°ï" ) {
                bangs = keys(info_bang);
                str = "½­ºşÉÏĞ°°ïÓĞ£º";
                temp = sizeof(bangs);
		for( i = 0; i < temp; i++ ) {
                        if( i != temp - 1 )
                                str += bangs[i] + "£¬";
                        else    str += bangs[i] + "¡£";
                }

                return str;
        }

        obj = filter_array(children(BANGZHU), (: clonep :));
        if( sizeof(obj) ) {
	        for(i = 0; i < sizeof(obj); i++) {
                        if( obj[i]->query("bangname") == name ) {
                                command("nod");
                                room = environment(obj[i]);
                                if( !room )
	                        return name + "°ïÖ÷" + info_bang[name] + "×î½üÊ§×ÙÁË¡£";

                                file = base_name(room);
                                if( strsrch(file, "/d/") != 0 
                                || !mapp(room->query("exits")) )
                                return name + "°ïÖ÷" + info_bang[name] + "×î½üÊ§×ÙÁË¡£";
				
                                region = explode(file, "/")[1];
                                return name + "°ïÖ÷" + info_bang[name] + "£¬×î½üÔÚ" + region_names[region] + "Ò»´ø¼¯ÖÚÎª·Ç×÷´õ£¡£¡£¡";
                        }
                }
        }

        command(":)");
        return name + "°ïÖ÷" + info_bang[name] + "×î½ü°²·ÖÊØ¼Í¡£";
}

// job2
string ask_bangyin()
{
        object *obj, ob, me = this_player(), room;
        string *bangs, bang, myfam, my_id;
        int i;

        if( time() < (int)me->query("shan/time2") + 60 )
                return RANK_D->query_respect(me) + "²»ÊÇ¸ÕÏòÎÒ´òÌı¹ıÂğ£¿\n";

        my_id = (string)me->query("id");
        if( !( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");
        if( my_id == room->query("winner") )
                return RANK_D->query_respect(me) + "ÊÇµ±½ñÎäÁÖÃËÖ÷£¬ÔõÒ²Ì°ÕâĞ¡°ïÖ®Ö÷£¿£¡";

        if( !( room = find_object("/d/taishan/xiayi")) )
                room = load_object("/d/taishan/xiayi");
        if( my_id == room->query("winner") )
                return RANK_D->query_respect(me) + "ÊÇµ±½ñÉÍÉÆÊ¹Õß£¬ÔõÒ²Ì°ÕâĞ¡°ïÖ®Ö÷£¿£¡";

        if( !( room = find_object("/d/taishan/zhengqi")) )
                room = load_object("/d/taishan/zhengqi");
        if( my_id == room->query("winner") )
                return RANK_D->query_respect(me) + "ÊÇµ±½ñ·£¶ñÊ¹Õß£¬ÔõÒ²Ì°ÕâĞ¡°ïÖ®Ö÷£¿£¡";

        myfam = (string)me->query("family/family_name");
        if( (int)me->query("shen") < 10000
        &&   myfam != "ÉÙÁÖÅÉ" )
                return RANK_D->query_respect(me) + "ÊÇºÚµÀÉÏµÄÈË£¬ÀÏ·òÆñÄÜ·ÅĞÄ½«Ò»°ïÖ®Ö÷ÍĞ¸¶¸øÄã£¿";

        if( (int)me->query("combat_exp") < 300000 )
                return RANK_D->query_respect(me) + "»¹ÊÇÔÚ½­ºşÉÏ¶à»ì¼¸Äê°É¡£";

        if( (int)me->query("combat_exp") > 800000 )
                return RANK_D->query_respect(me) + "ÒÑÊÇÊÀÍâ¸ßÊÖ£¬ºÎ±ØÔÙÉæÕâÌË»ìË®£¿";

        if( myfam == "´óÀí¶Î¼Ò" )
                return RANK_D->query_respect(me) + "ÄË´óÀí¹úÈËÊÏ£¬¶ÔÖĞÔ­ÎäÁÖ²»Ì«ÊìÏ¤°É¡£";

        if( myfam == "Ø¤°ï" )
                return RANK_D->query_respect(me) + "ÒÑÈëØ¤°ï£¬ºÎ²»ÎªØ¤°ï¾¡ĞÄ¾¡Á¦£¿";

        if( myfam != "ÉÙÁÖÅÉ"
        &&  myfam != "Îäµ±ÅÉ"
        &&  myfam != "¶ëáÒÅÉ"
        &&  myfam != "»ªÉ½ÅÉ" )
                return RANK_D->query_respect(me) + "·ÇÃûÃÅÕıÅÉ³öÉí£¬ÀÏ·òÆñÄÜ·ÅĞÄ½«Ò»°ïÖ®Ö÷ÍĞ¸¶¸øÄã£¿";

 //       if( present("bangyin", me) )
        if( stringp(me->query_temp("shan/bangzhu")) )
                return RANK_D->query_respect(me) + "ÊÖÉÏ²»ÊÇÒÑ¾­ÓĞÁËÒ»°ï°ïÓ¡ÁËÂğ£¿";
            
        obj = filter_array(children(BANGYIN2), (: clonep :));
        if( sizeof(obj) >= 3 )
                return "×î½ü½­ºşÌ«Æ½ÎŞÊÂ£¬ÄãÏÂ´ÎÔÙÀ´°É¡£";

        bangs = empty_bangs;
        if( sizeof(obj) ) {
                for(i = 0; i < sizeof(obj); i++)
                        bangs -= ({obj[i]->query("bangname")});
        }
        bang = bangs[random(sizeof(bangs))];

        ob = new(BANGYIN2);
        ob->set("bangname", bang);
        ob->set("long", bang + ob->query("name") + "¡£\n");
        ob->set("owner", me->query("id"));
        ob->move(me);
        me->set_temp("shan/bangzhu", bang);

        message_vision("$N½«" + bang + ob->query("name") + "½»¸øÁË$n¡£\n", this_object(), me);
        command("congra");
        me->set_temp("apply/short",
                ({ bang + HIR"°ïÖ÷"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));

        log_file("test/ShanPlaying", sprintf("%sÓÚ%sÊ±µ±ÉÏÁË%s°ïÖ÷\n", me->query("name"), ctime(time()), bang));

        me->set("shan/time2", time());
        return "Íû" + RANK_D->query_respect(me) + "ÔçÈÕ½«" + bang + "¸Ä±à³ÉÒ»¸öÏÀÒåÖ®°ï¡£";
}

// job3
string ask_jianghu()
{
        object *obj, ob, me = this_player();
        string *places, place;
        int i, temp;

        if( time() < (int)me->query("shan/time3") + 120 )
                return RANK_D->query_respect(me) + "²»ÊÇ¸ÕÏòÎÒ´òÌı¹ıÂğ£¿\n";

        if( (int)me->query("shen") < 100000
        &&  (string)me->query("family/family_name") != "ÉÙÁÖÅÉ" )
                return RANK_D->query_respect(me) + "ÊÇºÚµÀÉÏµÄÈË£¬Ö»ÅÂÄ§½ÌÊÇ" + RANK_D->query_respect(me) + "ÒıÀ´µÄ¡£";

        if( (int)me->query("combat_exp") < 500000 )
                return RANK_D->query_respect(me) + "»¹ÊÇÔÚ½­ºşÉÏ¶à»ì¼¸Äê°É¡£";

        obj = filter_array(children("ZHANGLAO"), (: clonep :));
        if( (temp = sizeof(obj)) >= 3 )
                return RANK_D->query_respect(me) + "ÄÜ·ñ¾¡Ò»Ğ©ÒåÎñ£¬É¨³ıÄ§½ÌÊÆÁ¦£¿";

        if( temp = sizeof(obj) ) {
                for(i = 0; i < sizeof(obj); i++) {
                        if( obj[i]->query("bj_victim") == me->query("id") )
                                return RANK_D->query_respect(me) + "Ò²Ì«ÈÃÎÒÎäÁÖÕıÅÉÈËÊ¿Ê§ÍûÁË¡£";
                }
        }

        if( temp >= 3 )
                return RANK_D->query_respect(me) + "ÄÜ·ñ¾¡Ò»Ğ©ÒåÎñ£¬É¨³ıÄ§½ÌÊÆÁ¦£¿";

        ob = new("ZHANGLAO");
        ob->set("bj_victim", me->query("id"));
        places = keys(zl_places);
        place = places[random(sizeof(places))];
        ob->move(place);
        message("vision",
                ob->name() + "×ßÁË¹ıÀ´¡£\n",
                environment(ob), ({ob}));

        me->set("shan/time3", time());
        log_file("test/ShanPlaying", sprintf("%sÓÚ%sÊ±ÊÚÃü±£»¤%s\n", me->query("name"), ctime(time()), zl_places[place]));
        command("sigh");
        return "×î½üÄ§½ÌÉ¦ÈÅ" + zl_places[place] + "£¬¸ãµÃÕû¸ö½­ºş²»µÃ°²Äş¡£";
}


// job4
string ask_jian()
{
        object *obj, room, lama, ob = this_player();
        string place;
        int i, temp;

        if( (int)ob->query("combat_exp") < 500000 ) {
                command("shake " + ob->query("id"));
                return "´ËÊÂÌ«¹ı¼èÄÑ£¬·ÇÄãÁ¦¿ÉÎª¡£";
        }

        if( time() < (int)ob->query("shan/time4") + 60 )
                return RANK_D->query_respect(ob) + "²»ÊÇ¸ÕÏòÎÒ´òÌı¹ıÂğ£¿\n";

        ob->set("shan/time4", time());

        obj = filter_array(children(LAMA), (: clonep :));

        if( temp = sizeof(obj) ) {
                for(i = 0; i < temp; i++) {
                        if( !(room = environment(obj[i])) ) {
                                destruct(obj[i]);
                                command("sigh");
                                return "Ìú½£ÃÅ¡°ÕÆÃÅÖ®±¦¡±Ê§×ÙÁË£¬ÑÛ¿´¾ÍÒª´óÄÑÁÙÍ·ÁË¡£";
                        }

                        if( !mapp(room->query("exits")) 
                        ||  strsrch(base_name(room), "/d/") != 0 ) {
                                destruct(obj[i]);
                                command("sigh");
                                return "Ìú½£ÃÅ¡°ÕÆÃÅÖ®±¦¡±Ê§×ÙÁË£¬ÑÛ¿´¾ÍÒª´óÄÑÁÙÍ·ÁË¡£";
                        }
                }

                command("shout");
                return "½­ºşÊ¢´«Ìú½£ÃÅ¡°ÕÆÃÅÖ®±¦¡±ÒÑ±»ÃÜ×Ú¸ßÊÖËù»ñ¡£";
        }

        place = lama_places[random(sizeof(lama_places))];
        lama = new(LAMA + "2");
        lama->move(place);
        message("vision",
                lama->name() + "×ßÁË¹ıÀ´¡£\n",
                environment(lama), ({lama}));

        lama = new(LAMA);
        lama->move(place);
        message("vision",
                lama->name() + "×ßÁË¹ıÀ´¡£\n",
                environment(lama), ({lama}));

        command("shout");
        return "½­ºşÊ¢´«Ìú½£ÃÅ¡°ÕÆÃÅÖ®±¦¡±ÒÑ±»ÃÜ×Ú¸ßÊÖËù»ñ¡£";
}


string ask_mizong()
{
        object ob, *obj, room;
        string file;

        obj = filter_array(children(LAMA), (: clonep :));

        if( !sizeof(obj) ) return "ÎÒÒ²²»ÖªµÀËûÃÇÔÚÄÄÀï¡£";

        ob = obj[random(sizeof(obj))];
        if( !(room = environment(ob)) ) {
                destruct(ob);
                return "ÎÒÒ²²»ÖªµÀËûÃÇÔÚÄÄÀï¡£";
        }

        if( strsrch((file = base_name(room)), "/d/") != 0 ) {
                destruct(ob);
                return "ÎÒÒ²²»ÖªµÀËûÃÇÔÚÄÄÀï¡£";
        }

        command("nod");
        return "½­ºşÉÏ´«ÎÅ£¬×î½üËûÃÇ³öÃ»ÔÚ" + region_names[explode(file, "/")[1]] + "Ò»´ø¡£";
}
