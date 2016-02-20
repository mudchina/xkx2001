// Change by Server
// wizlist.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;
	mapping wizstatus;
	int j = 0;
	int i; 
	write(MUD_NAME + "目前的巫师有：");

//
//	for(int i=0; i<sizeof(list); i++)
//		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');

	wizstatus = SECURITY_D->query_wizstatus();
	list = keys(wizstatus);

/*	write(HIW"\n\n『天帝』  "NOR);
	for(int i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(admin)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}
*/
	j=0;
	write(HIY"\n\n『大神』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(arch)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(HIG"\n『神仙』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(wizard)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
        write(HIM"\n『散仙』  "NOR);
        for( i=0; i<sizeof(list); i++)
        {
                if( wizstatus[list[i]] == "(virtuoso)" )
                {
                        j++;
                        printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
                }
        }

	j=0;
	write(YEL"\n『天官』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(caretaker)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(GRN"\n『天师』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(designer)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(HIC"\n『天仙』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(creator)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(MAG"\n『仙人』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(apprentice)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}


	j=0;
	write(CYN"\n『半仙』  "NOR); 	for(i=0; i<sizeof(list); i++) 	{ 		if( wizstatus[list[i]] == "(immortal)" ) 		{ 			j++; 			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' '); 			if(j==7)break; 		} 	}  	write(CYN"『半仙』  "NOR); 	for(; i<sizeof(list); i++) 	{ 		if( wizstatus[list[i]] == "(immortal)" ) 		{ 			j++; 			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' '); 			if(j==7)break; 		} 	} 


	write("\n\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}
