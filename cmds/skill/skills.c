//Cracked by Roath
// skills.c

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
        int i,j;

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
        j=0;

        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }
        if(j>0) { printf("[32m©°[42m%21s    [40m[32m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´[37;0m\n", "[37m"+chinese_number(j)+"ÏîÖªÊ¶");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type()=="knowledge"){
                printf("[32m©¦[37;0m%s%s%-40s" NOR " - %-10s %3d/%6d[32m©¦[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32m¡õ[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32m©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼[37;0m\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        if(j>0) { printf("[32m©°[42m%21s    [40m[32m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´[37;0m\n", "[37m"+chinese_number(j)+"Ïî»ù±¾¹¦·ò");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "beidou-zhenfa" )){
                printf("[32m©¦[37;0m%s%s%-40s" NOR " - %-10s %3d/%6d[32m©¦[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32m¡õ[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32m©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼[37;0m\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming" && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        if(j>0) { printf("[32m©°[42m%21s    [40m[32m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´[37;0m\n", "[37m"+chinese_number(j)+"ÏîÌØÊâ¹¦·ò");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming"  && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "beidou-zhenfa" )){
                printf("[32m©¦[37;0m%s%s%-40s" NOR " - %-10s %3d/%6d[32m©¦[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32m¡õ[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32m©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼[37;0m\n");}


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
