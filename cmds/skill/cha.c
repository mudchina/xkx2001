//Cracked by Roath
// skills.c
// Modified by xQin 04/01 to disable the possibility for players to use this cmd to check whether
// an invisible wiz is online.

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "³õÑ§Õ§Á·" NOR,
        HIB "´ÖÍ¨Æ¤Ã«" NOR,
        HIB "°ëÉú²»Êì" NOR,
        HIB "ÂíÂí»¢»¢" NOR,
        HIB "¼İÇá¾ÍÊì" NOR,
        CYN "³öÀà°ÎİÍ" NOR,
        CYN "ÉñºõÆä¼¼" NOR,
        CYN "³öÉñÈë»¯" NOR,
        HIC "µÇ·åÔì¼«" NOR,
        HIC "Ò»´ú×ÚÊ¦" NOR,
        HIW "Éî²»¿É²â" NOR
});

string *knowledge_level_desc = ({
        BLU "ĞÂÑ§Õ§ÓÃ" NOR,
        HIB "³õ¿úÃÅ¾¶" NOR,
        HIB "ÂÔÖªÒ»¶ş" NOR,
        HIB "ÂíÂí»¢»¢" NOR,
        HIB "ÒÑÓĞĞ¡³É" NOR,
        CYN "ĞÄÁìÉñ»á" NOR,
        CYN "ÁËÈ»ì¶ĞØ" NOR,
        CYN "»íÈ»¹áÍ¨" NOR,
        HIC "¾ÙÊÀÎŞË«" NOR,
        HIC "Õğ¹Åîå½ñ" NOR,
        HIW "Éî²»¿É²â" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄ¼¼ÄÜ£¿\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && !ob->is_spouse_of(me))
                return notify_fail("ÄãÒª²ì¿´Ë­µÄ¼¼ÄÜ£¿\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "Äã" : ob->name()) + "Ä¿Ç°²¢Ã»ÓĞÑ§»áÈÎºÎ¼¼ÄÜ¡£\n");
                return 1;
        }
        write( "[44;1m[1;33m"+(ob==me ? "Äã" : ob->name()) +"[44;1m[1;33mÄ¿Ç°ËùÑ§¹ıµÄ¼¼ÄÜ£º£¨¹²"+chinese_number(sizeof(skl))+"Ïî¼¼ÄÜ£©                               [37;0m\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        for(i=0; i<sizeof(skl); i++) {
                printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (member_array(sname[i], mapped)==-1? "  ": "¡õ"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
        }
        write("\n");
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 40;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : skills|cha [<Ä³ÈË>]

Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄã(Äã)²éÑ¯ËùÑ§¹ıµÄ¼¼ÄÜ¡£

ÄãÒ²¿ÉÒÔÖ¸¶¨Ò»¸öºÍÄãÓĞÊ¦Í½¹ØÏµµÄ¶ÔÏó£¬ÓÃ skills ¿ÉÒÔ²éÖª¶Ô·½µÄ¼¼ÄÜ×´¿ö¡£

Î×Ê¦¿ÉÒÔ²éÑ¯ÈÎºÎÈË»ò NPC µÄ¼¼ÄÜ×´¿ö¡£

HELP
    );
    return 1;
}
