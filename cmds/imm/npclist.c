//Cracked by Roath
// npc and user list
// sdong created on 12/3/1999

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        object where;
		int i;
		int nNPC=0,nPlayer=0,nDeleted=0;

        ob=livings();
        i = sizeof(ob);
        while (i--) {
			if(!ob[i]||!objectp(ob[i]))continue;
			nNPC++;
			if( userp(ob[i]) )nPlayer++;

			where=environment(ob[i]);
			if(!where||!objectp(where)){
				write(sprintf("Delete %s(%s) for having no environment.\n",ob[i]->query("id"),file_name(ob[i]) ) );
				if(!userp(ob[i])){
					destruct(ob[i]);
					nDeleted++;
				}
				else ob[i]->move(environment(this_player()));
				continue;
			}

			if( !userp(ob[i]) && sizeof(children(base_name(ob[i])+".c") ) > 10 )
			{
				    write( sprintf("Delete %s(%s) for multiple copies.\n",ob[i]->query("id"),file_name(ob[i]) ) );
					if( ob[i] && objectp(ob[i]) )
					{
						destruct(ob[i]);
						nDeleted++;
						continue;
					}
			}

			write(sprintf("%s(%s,%s) in %s(%s)\n",ob[i]->query("name"),ob[i]->query("id"),file_name(ob[i]),where->query("short"),file_name(where)));
        }
		write(sprintf("\n\nTotal NPC+Player number: %d where %d are players.\n%d NPC destructed for no environment.",nNPC,nPlayer,nDeleted) );

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : npclist

将线上所有npc and players的/obj/user number 显示出来。
HELP
    );
    return 1;
}
