//Cracked by Roath
// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <dbase.h>
#include <skill.h>

int query_str()
{
	int temp;
	int improve = 0;

	if ( query_skill("unarmed",1) 
	||   query_skill("cuff",   1)
	||   query_skill("strike", 1)
	||   query_skill("hand",   1)
	||   query_skill("claw",   1)
	||   query_skill("finger", 1) )
	{
		if( query_skill("unarmed",1) >= temp ) temp = query_skill("unarmed",1);
		if( query_skill("cuff",   1) >= temp ) temp = query_skill("cuff",   1);
		if( query_skill("strike", 1) >= temp ) temp = query_skill("strike", 1);
		if( query_skill("hand",   1) >= temp ) temp = query_skill("hand",   1);
		if( query_skill("claw",   1) >= temp ) temp = query_skill("claw",   1);
		if( query_skill("finger", 1) >= temp ) temp = query_skill("finger",1);
		
		improve = temp / 10;
	}

	return (int)query("str") + // (int)query("jiali") +
		query_temp("apply/strength") + improve;
}

int query_encum_str()
{
        int temp;
        int improve = 0;

        if ( query_skill("unarmed",1) 
        ||   query_skill("cuff",   1)
        ||   query_skill("strike", 1)
        ||   query_skill("hand",   1)
        ||   query_skill("claw",   1)
        ||   query_skill("finger", 1) )
        {
                if( query_skill("unarmed",1) >= temp ) temp = query_skill("unarmed",1);
                if( query_skill("cuff",   1) >= temp ) temp = query_skill("cuff",1);
                if( query_skill("strike", 1) >= temp ) temp = query_skill("strike",1);
                if( query_skill("hand",   1) >= temp ) temp = query_skill("hand",1);
                if( query_skill("claw",   1) >= temp ) temp = query_skill("claw",1);
                if( query_skill("finger", 1) >= temp ) temp = query_skill("finger",1);
                improve = temp / 10;
        }

        return (int)query("str") + improve;
}




int query_int()
{
	return (int)query("int") + query_temp("apply/intelligence") +
		(int)query_skill("literate", 1) / 10;
}

int query_con()
{
	return (int)query("con") + query_temp("apply/constitution") +
		(int)query_skill("force", 1) / 10;
}

int query_dex()
{
	return (int)query("dex") + query_temp("apply/dexerity") +
		(int)query_skill("dodge", 1) / 10;
}

int query_kar()
{
	return (int)query("kar") + query_temp("apply/karma");
}

int query_per()
{
	return (int)query("per") + query_temp("apply/personality") +
		(int)query_skill("beauty", 1) / 10;
}
