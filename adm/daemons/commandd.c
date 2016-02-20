//Cracked by Kafei
//
// cmd_d.c
//
// modified by sdong, 12/15/98
#include <ansi.h>

mapping search = ([]);

void rehash(string dir)
{
	int i;
	string *cmds;

	if( dir[sizeof(dir)-1]!='/' ) dir += "/";
	cmds = get_dir(dir);
	i = sizeof(cmds);
	while(i--)
		if( !sscanf(cmds[i], "%s.c", cmds[i]) ) {
			if( i==0 ) cmds = cmds[1..sizeof(cmds)];
			else if( i==sizeof(cmds) ) cmds = cmds[0..<2];
			else cmds = cmds[0..i-1] + cmds[i+1..<1];
		}
	if( sizeof(cmds) )
		search[dir] = cmds;
}

string find_command(string verb, string *path)
{
	int i;
	string cmd;

	if( !pointerp(path) ) return 0;

	i = sizeof(path);
	while(i--) {
		if( undefinedp(search[path[i]]) ) rehash(path[i]);
		if( undefinedp(search[path[i]]) ) continue;
		if( member_array(verb, search[path[i]])!=-1 )
		{
			cmd = path[i] + verb;
			if( SECURITY_D->valid_cmd(cmd, this_player(), "cmd_file") )
				return cmd;
			else return 0;
		}
	}
	return 0;
}

