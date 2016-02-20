//Cracked by Roath
// guangming-xinfa.c 光明心法

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{       
        return notify_fail("光明心法只能靠学(learn)来提高。\n");
}
