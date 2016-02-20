//Cracked by Roath
// /d/shenlong/sea.c
// ALN Sep / 97

inherit ROOM;
#include <ansi.h>

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
        object *inv, weapon, me = this_player();
        string skillarg, str, multiple;
        int w, *cost, times, total;

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
                me->receive_damage("jing", cost[0]);
                me->receive_damage("jingli", cost[1]);             
                me->improve_skill(skillarg, random((int)me->query_int()));

                if(!weapon)
                        me->improve_skill("force", 5 + random(10));
                else    me->improve_skill("force", 2 + random(6));

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
                        case "blade" : return ({15, 30});
                        case "club"  : return ({20, 25});
                        case "staff" : return ({25, 20});
                        case "stick" : return ({30, 15});
                        case "sword" : return ({35, 10});
                        case "cuff"  : return ({35, 20});
                        case "strike": return ({20, 35});
                        case "parry" : return ({15, 25});
                        case "dodge" : return ({25, 15});
                }
        }

        return ({20, 20});
}





