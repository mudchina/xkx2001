// Change by Server
// npc and user list
// sdong created on 12/3/1999

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        object where;
	int i;
        ob=livings();
        i = sizeof(ob);
        while (i--) {
		if(!ob[i]||!objectp(ob[i]))continue;
	 	if(!userp(ob[i]))destruct(ob[i]);
        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : cleannpc

将线上所有npc and players cleaned.
HELP
    );
    return 1;
}

