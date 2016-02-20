//Cracked by Roath
// by aln  4 / 98
// modified by xiaojian 06/2000
inherit F_CLEAN_UP;

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        mapping fgskills, fglearned, skill_learned;
        string *skills, skill;
        int amount, i;

        me->apply_condition("zuochan", duration - 1);

        if( !duration ) {
                fgskills = me->query("fgskills");
                fglearned = me->query("fglearned");

                skills = keys(fgskills);
                amount = sizeof(skills);

                skill_learned = me->query_learned();
                for(i = 0; i < amount; i++) {
                        skill = skills[i];
                        me->set_skill(skill, fgskills[skill]);
                        skill_learned[skill] = fglearned[skill];
                }

                me->delete("fgskills");
                me->delete("fglearned");
                //me->add("int", -amount);

                write("\n你从佛我两忘的幻境中又回到了尘世。\n");
                return 0;
        }

        return 1;
}
