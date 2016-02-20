//Cracked by Roath
// /d/shenlong/sea.c
// ALN Sep / 97

inherit ROOM;
#include <ansi.h>
int do_practice(string arg);

string *practice_types = ({
        "blade",
        "club",
        "staff",
        "stick",
        "sword",
        "whip",

        "cuff",
        "strike",
        "parry",
        "dodge",
});
        
int *cost(object, string);

void create()
{
       set("short","´óº£");
       set("long", @LONG
ÕâÊÇÁÉÀ«µÄº£Ãæ£¬º£·ç¡¸ºôºô¡¹ÔÚÄã¶ú±ß´µ¹ı£¬º£ÀËÒ»¸ö½Ó×ÅÒ»¸öÏòÄãÆÃ
´ò¹ıÀ´£¬Í»È»Ò»¸ö¾ŞÀË´òÀ´¼¸ºõ°ÑÄãÏİÈëĞıÎĞÖĞ£¬Äã»¹ÊÇ¾¡¿ìÀë¿ªÕâ¶ù°É¡£
LONG
     );
        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"beach",
        ]));

        set("cost", 20);

        setup();
}

void init()
{
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
}

int do_practice(string arg)
{
        object *inv, weapon;
        object me  = this_player();
        string skillarg, str, multiple;
        int w, *cost, times, total;


        mapping fam, skills, learned;
        string skillname;
        int skill_special, skill_basic;

        skills = me->query_skills();
        learned = me->query_learned();
        skill_basic = me->query_skill(arg, 1);
        if( !stringp(skillname = me->query_skill_mapped(arg)) )
		{
               tell_object(me,"Äã±ØĞëÓĞÌØÊâÎä¹¦·½ÄÜÓë»ù±¾Îä¼¼²ÎÕÕÁìÎò£¡\n");
			   return 1;
		}

        skill_special = me->query_skill(skillname, 1);


        if( skill_special < 1 )
		{
				tell_object(me,"Äã¶ÔÕâ·½ÃæµÄ¼¼ÄÜ»¹ÊÇÒ»ÇÏ²»Í¨£¬×îºÃ´ÓÏÈ´Ó»ù±¾Ñ§Æğ¡£\n");
				return 1;
		}	
        if( skill_basic > skill_special )
		{
				tell_object(me,"Äã" + to_chinese(skillname) + "¹¦Á¦²»¹»£¬ÎŞ·¨¼ÌĞøÁìÎò" + to_chinese(arg) + "£¡\n");
				return 1;
		}
        skill_special = skill_special * me->query("max_jing") * 2 / (1000 + me->query("max_jing"));


        if( me->is_busy() ) {
                tell_object(me, "ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");
                return 1;
		}

        if( me->is_fighting() ) {
                tell_object(me, "ÄãÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");
                return 1;
		}

        if( !arg ) return ("/cmds/skill/enable")->main(me, arg);

        if(sscanf(arg, "%s %d", skillarg, times) != 2 )
                skillarg = arg;

        if( (w = member_array(skillarg, practice_types)) == -1 ) {
                tell_object(me, "ÕâÏî¼¼ÄÜ²»ÄÜÔÚÕâ¶ùÁ·Ï°¡£\n");
                return 1;
        }

        if( w < 6 ) {
                if( !objectp(weapon = me->query_temp("weapon")) ) {
                        tell_object(me, "ÄãÃ»ÓĞÄÃÎäÆ÷ÔõÃ´Á·Ï°£¿\n");
                        return 1;
                } else if( weapon->query("skill_type") != skillarg ) {
                        tell_object(me, "ÄãÊÖÖĞµÄÎäÆ÷²»ÊÊºÏÁ·ÄãÏëÁ·Ï°µÄ¼¼ÄÜ¡£\n");
                        return 1;
                }
        }

        if( (int)me->query_skill(skillarg, 1) < 30 ) {
               tell_object(me, "Äã»¹ÊÇÏÈÈ¥¸úÊ¦¸µ¶à¶àÑ§Ï°¡£\n");
               return 1;
        }

        if(!times || times == 0) {
                times = 1;
                multiple="";
        }
        else    multiple="·´¸´";

        switch(skillarg) {
                case "blade" :
                case "club"  :
                case "staff" :
                case "stick" :
                case "sword" : 
                case "whip"  : str = "»ÓÎè" + weapon->name();  break;
                case "cuff"  : str = "»ÓÎèË«È­"; break;
                case "strike": str = "»ÓÎèË«ÕÆ"; break;
                case "parry" : str = "·ÜÁ¦ŞÕ²©"; break;
                case "dodge" : str = "×İÉÁÌøÔ¾"; break;
        }                


        message_vision("$NÔÚº£ÀËÖĞ" + str + multiple + "Á·Ï°×Å" + to_chinese(skillarg) + "¡£\n", me);

        for(times; times > 0; times--) {
                cost = cost(me, skillarg);
                if( (int)me->query("jing") < cost[0]
                ||  (int)me->query("jingli") < cost[1] ) {
                        tell_object(me, "ÒÀÄãµ±Ç°µÄ×´¿öÀ´¿´Äã²»ÄÜÈç´ËÁ·Ï°¡£\n");
                        return 1;
                }
                //me->receive_damage("jing", cost[0]);
                me->receive_damage("jingli", cost[1]);             
                me->receive_damage("jing", random(skill_basic)/2, "Ú¤Ë¼¿àÏë°ÑÄÔ´ü¸øÏëÆÆÁË£¬°×°×µÄÄÔ½¬Á÷ÁËÒ»µØ");
                me->improve_skill(skillarg, skill_special/8 + random(skill_special/4));
				

                //if(!weapon)
                //        me->improve_skill("force", 5 + random(10));
                //else    me->improve_skill("force", 2 + random(6));

                total = (int)me->query("jing") + (int)me->query("jingli");
                if( total < 500 && random(total) < 20 ) {
                        message_vision("Í»È»Ò»¸ö¾ŞÀË´òÀ´£¬$NÏİÈëĞıÎĞÖĞ£¬Á¢¼´±»º£Ë®ÍÌÃ»ÁË¡£\n", me);
                        for(int i = 0; i < sizeof(inv); i++) {
                                if( userp(inv[i]) )
                                        inv[i]->receive_wound("qi", 50 + inv[i]->query("max_qi"), "µô½øº£ÀïÑÍËÀÁË");
                                else    destruct(inv[i]);
                        }

                        me->unconcious();
                        me->move("/d/shenlong/beach");
                        message("vision", "Äã·¢ÏÖÒ»¸ö»ëÉíË®ÁÜÁÜµÄ¼Ò»ï±»º£Ë®³åÉÏ°¶À´£¬²»ÉµÃ×ß½üÒ»¿´£¬Ô­À´ÊÇ" + me->name() + "\241\243\n", environment(me), ({me}));
                        return 1;
                }
        }
        
        return 1;
}

int *cost(object ob, string skill)
{
        if( (int)ob->query("potential") > 0 && (int)ob->query("neili") > 10 ) {
                if( !random(3) )
                ob->add("potential", -1);
                else ob->add("neili", -8);
                return ({0, 0});
        } else {
                switch(skill) {
                        case "blade" : return ({150, 300});
                        case "club"  : return ({200, 250});
                        case "staff" : return ({250, 200});
                        case "stick" : return ({300, 150});
                        case "sword" : return ({350, 100});
                        case "cuff"  : return ({350, 200});
                        case "strike": return ({200, 350});
                        case "parry" : return ({150, 250});
                        case "dodge" : return ({250, 150});
                }
        }

        return ({20, 20});
}





