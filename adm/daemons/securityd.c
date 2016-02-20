// securityd.c

#include <login.h>
#include <ansi.h>
#include <mudlib.h>

inherit F_DBASE;
inherit F_SAVE;

// xuy added wiz login site checking.
// Modified by Sdong for separated read and write access control, wizlist edit, etc., 11/17/98
// Modified by Sdong for use securityd.o to control access right, 11/20/98

mapping wiz_status;
private mapping wiz_sites;

private string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(virtuoso)",
	"(caretaker)",
	"(creator)",
	"(designer)",
	"(wizard)",
	"(arch)",
	"(admin)"
});


// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

mapping trusted_read;
mapping exclude_read;
mapping trusted_write;
mapping exclude_write;
mapping authorized_cmds;
mapping exclude_cmds;

int check_redundancy(string *wizlist);
string query_cmdlist();
int set_cmdlist(string dir, string users);
int valid_cmd(string file, mixed user, string func);
string query_exclude_cmdlist();
int set_exclude_cmdlist(string dir, string users);


void create()
{
	string *wizlist, wiz_name, wiz_level, wiz_site;
	int i;

	seteuid(ROOT_UID);



	if(!restore())
	{
		wiz_status = allocate_mapping(10000);
		wiz_sites = allocate_mapping(10000);
		wiz_status["npc"] = "(admin)";
		wiz_sites["npc"] = ".*";
	}

 

}

int remove()
{
		  save();
		  return 1;
}

string query_save_file() { return DATA_DIR + "securityd"; }


// added by sdong, 11/16/98
string query_wizlist() {
	string uid, *wiz, wizlist;
	int i;
	wiz = keys(wiz_status);
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + " " + wiz_sites[wiz[i]] + "\n";

	return wizlist;
}

// added by sdong, 11/16/98
mapping query_wizstatus() { return wiz_status; }

// This function check if a wiz login is from trusted site. xuy@XKX
int valid_wiz_login(mixed ob, string site)
{
	string euid, *line;

	if( objectp(ob) ) {
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	} else if ( stringp(ob) )
		euid = ob;

	if( undefinedp(wiz_sites[euid]) ) return 0;

	line = ({});
	line += ({site});
	if( sizeof(regexp(line, wiz_sites[euid])) == 1)
		return 1;
	return 0;
}

// This function returns the status of an uid.
string get_status(mixed ob)
{
	string euid;

	if( objectp(ob) ) {
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;

	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	else return "(player)";
}

int get_wiz_level(object ob)
{
	return member_array(get_status(ob), wiz_levels);
}

/* yzc, usage: ...(this_player(), "(wizard)") < 0 */
int cmp_wiz_level(object ob, string lvl)
{
	return ( get_wiz_level(ob) - member_array(lvl, wiz_levels) );
}

int set_status(mixed ob, string status, string sites,string promoter)
{
	string uid, *wiz, wizlist;
	int i;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if( userp(ob) )                 uid = getuid(ob);
	else if(stringp(ob))    uid = ob;
	else if( !(uid = ob->query("id")) ) return 0;
	
	if ( find_object("/cmds/adm/promote") )	
	{
		if( previous_object() != find_object("/cmds/adm/promote"))
			return 0;	
	}	

	if( status == "(player)" ) {
		map_delete(wiz_status, uid);
		map_delete(wiz_sites, uid);
	}
	else {
		wiz_status[uid] = status;
		if(sites)wiz_sites[uid] = sites;
		else if(undefinedp(wiz_sites[uid]))
				wiz_sites[uid] = ".*";
	}


	log_file( "/static/promotion_log", capitalize(uid)
	 + " become a " + status + " with access ip: " + sites + " on " + ctime(time()) + " by "+promoter+". \n" );

	 save();
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }

// query the wiz cmds access right
// added by sdong, 11/16/98
string query_cmdlist()
{
	string uid, *dir, readlist, *wizlist,this_dir;
	int i,j;


	if(!authorized_cmds)return "no command list\n";

	dir = keys(authorized_cmds);
	for(i=0; i<sizeof(dir); i++)
	{
		if( dir[i][0..0] == "/" && dir[i] != "/")
		{
			this_dir = dir[i][1..sizeof(dir[i])-1];
			authorized_cmds[ this_dir ] = authorized_cmds[ dir[i] ];
			map_delete(authorized_cmds, dir[i]);
		}
	}

	dir = keys(authorized_cmds);
	dir = sort_array(dir, 1);
	for(readlist = "", i=0; i<sizeof(dir); i++)
	{
		readlist += dir[i] + ":";
		wizlist = authorized_cmds[dir[i]];
		wizlist = sort_array(wizlist, 1);
		for(j=0; j<sizeof(wizlist); j++) {
		 readlist += wizlist[j] + ",";
		}
		readlist += "\n";
	}
	return readlist;
}

// set wiz commands access
// sdong, 11/20/98
int set_cmdlist(string dir, string users)
{
	string *wizlist;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if(!dir)return 0;
	if( dir[0..0] == "/" && dir !="/") dir = dir[1..sizeof(dir)-1];

	if(!authorized_cmds)
	{
		authorized_cmds = allocate_mapping(10000);
	}

	if( !users ) {  map_delete(authorized_cmds, dir);}
	else {
		wizlist = explode(users, ",");
		if( !check_redundancy(wizlist) )
		{
			return notify_fail("There is redundancy in list\n");
		}
		authorized_cmds[dir] = wizlist;
	}
	save();
	return 1;
}

// query the wiz exclude cmds list
// added by sdong, 11/16/98
string query_exclude_cmdlist()
{
	string uid, *dir, readlist, *wizlist,this_dir;
	int i,j;

	if(!exclude_cmds)return "no exclude command list yet\n";

	dir = keys(exclude_cmds);
	for(i=0; i<sizeof(dir); i++)
	{
		if( dir[i][0..0] == "/" && dir[i] != "/")
		{
			this_dir = dir[i][1..sizeof(dir[i])-1];
			exclude_cmds[ this_dir ] = exclude_cmds[ dir[i] ];
			map_delete(exclude_cmds, dir[i]);
		}
	}

	dir = keys(exclude_cmds);
	dir = sort_array(dir, 1);
	for(readlist = "", i=0; i<sizeof(dir); i++)
	{
		readlist += dir[i] + ":";
		wizlist = exclude_cmds[dir[i]];
		wizlist = sort_array(wizlist, 1);
		for(j=0; j<sizeof(wizlist); j++) {
		 readlist += wizlist[j] + ",";
		}
		readlist += "\n";
	}
	return readlist;
}

// set wiz exclude commands access
// sdong, 11/20/98
int set_exclude_cmdlist(string dir, string users)
{
	string *wizlist;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;


	if(!dir)return 0;
	if( dir[0..0] == "/" && dir !="/") dir = dir[1..sizeof(dir)-1];

	if(!exclude_cmds)
	{
		exclude_cmds = allocate_mapping(10000);
	}

	if( !users ) {  map_delete(exclude_cmds, dir);}
	else {
		wizlist = explode(users, ",");
		if( !check_redundancy(wizlist) )
		{
			return notify_fail("There is redundancy in list\n");
		}
		exclude_cmds[dir] = wizlist;
	}
	save();
	return 1;
}


// added by sdong, 11/16/98
// query the read access right
string query_readlist() {
	string uid, *dir, readlist, *wizlist,this_dir;
	int i,j;

	dir = keys(trusted_read);
	for(i=0; i<sizeof(dir); i++)
	{
		if( dir[i][0..0] == "/" && dir[i] != "/")
		{
			this_dir = dir[i][1..sizeof(dir[i])-1];
			trusted_read[ this_dir ] = trusted_read[ dir[i] ];
			map_delete(trusted_read, dir[i]);
		}
	}

	dir = keys(trusted_read);
	dir = sort_array(dir, 1);
	for(readlist = "", i=0; i<sizeof(dir); i++)
	{
		readlist += dir[i] + ":";
		wizlist = trusted_read[dir[i]];
		wizlist = sort_array(wizlist, 1);
		for(j=0; j<sizeof(wizlist); j++) {
		 readlist += wizlist[j] + ",";
		}
		readlist += "\n";
	}
	return readlist;
}

// added by sdong, 11/16/98
// query the write access right
string query_writelist() {
	string uid, *dir, writelist, *wizlist,this_dir;
	int i,j;

	dir = keys(trusted_write);
	for(i=0; i<sizeof(dir); i++)
	{
		if( dir[i][0..0] == "/" && dir[i] != "/")
		{
			this_dir = dir[i][1..sizeof(dir[i])-1];
			trusted_write[ this_dir ] = trusted_write[ dir[i] ];
			map_delete(trusted_write, dir[i]);
		}
	}
	dir = keys(trusted_write);
	dir = sort_array(dir, 1);
	for(writelist = "", i=0; i<sizeof(dir); i++)
	{
		writelist += dir[i] + ":";
		wizlist = trusted_write[dir[i]];
		wizlist = sort_array(wizlist, 1);
		for(j=0; j<sizeof(wizlist); j++) {
		 writelist += wizlist[j] + ",";
		}
		writelist += "\n";
	}
	return writelist;
}

// added by sdong, 11/16/98
// query the exclude read access right
string query_exclude_readlist() {
	string uid, *dir, readlist, *wizlist,this_dir;
	int i,j;

	dir = keys(exclude_read);
	for(i=0; i<sizeof(dir); i++)
	{
		if( dir[i][0..0] == "/" && dir[i] != "/")
		{
			this_dir = dir[i][1..sizeof(dir[i])-1];
			exclude_read[ this_dir ] = exclude_read[ dir[i] ];
			map_delete(exclude_read, dir[i]);
		}
	}
	dir = keys(exclude_read);
	dir = sort_array(dir, 1);
	for(readlist = "", i=0; i<sizeof(dir); i++)
	{
		readlist += dir[i] + ":";
		wizlist = exclude_read[dir[i]];
		wizlist = sort_array(wizlist, 1);
		for(j=0; j<sizeof(wizlist); j++) {
		 readlist += wizlist[j] + ",";
		}
		readlist += "\n";
	}
	return readlist;
}

// added by sdong, 11/16/98
// query the exclude write access right
string query_exclude_writelist() {
	string uid, *dir, writelist, *wizlist,this_dir;
	int i,j;

	dir = keys(exclude_write);
	for(i=0; i<sizeof(dir); i++)
	{
		if( dir[i][0..0] == "/" && dir[i] != "/")
		{
			this_dir = dir[i][1..sizeof(dir[i])-1];
			exclude_write[ this_dir ] = exclude_write[ dir[i] ];
			map_delete(exclude_write, dir[i]);
		}
	}
	dir = keys(exclude_write);
	dir = sort_array(dir, 1);
	for(writelist = "", i=0; i<sizeof(dir); i++)
	{
		writelist += dir[i] + ":";
		wizlist = exclude_write[dir[i]];
		wizlist = sort_array(wizlist, 1);
		for(j=0; j<sizeof(wizlist); j++) {
		 writelist += wizlist[j] + ",";
		}
		writelist += "\n";
	}
	return writelist;
}

// check redundancy
// sdong, 11/20/98
int check_redundancy(string *wizlist)
{
	int i,j;

	for(j=0; j<sizeof(wizlist); j++) {
		for(i=j+1;i<sizeof(wizlist);i++)
			if( wizlist[j] == wizlist[i] )
			{
				write("There are redundancy in list: " + wizlist[i]+"\n");
				return 0;
			}
	}
	return 1;
}

// set read access to the dir
// sdong, 11/20/98
int set_readaccess(string dir, string users)
{
	string *wizlist;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if(!dir)return 0;
	if( dir[0..0] == "/" && dir !="/") dir = dir[1..sizeof(dir)-1];

	if( !users ) {  map_delete(trusted_read, dir);}
	else {
		wizlist = explode(users, ",");
		if( !check_redundancy(wizlist) ) return notify_fail("There is redundancy in list\n");
		trusted_read[dir] = wizlist;
	}
	save();
	log_file( "/static/grant_log", this_player()->query("id") + " granted read access in " + dir + " to "+users+" on "+ctime(time())+". \n" );
	return 1;
}

// set write access to the dir
// sdong, 11/20/98
int set_writeaccess(string dir, string users)
{
	string *wizlist;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if(!dir)return 0;
	if( dir[0..0] == "/" && dir !="/") dir = dir[1..sizeof(dir)-1];
	if( !users ) {  map_delete(trusted_write, dir);}
	else {
		wizlist = explode(users, ",");
		if( !check_redundancy(wizlist) ) return notify_fail("There is redundancy in list\n");
		trusted_write[dir] = wizlist;
	}
	save();
	log_file( "/static/grant_log", this_player()->query("id") + " granted write access in " + dir + " to "+users+" on "+ctime(time())+". \n" );
	return 1;
}
// set excluderead access to the dir
// sdong, 11/20/98
int set_exclude_readaccess(string dir, string users)
{
	string *wizlist;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if(!dir)return 0;
	if( dir[0..0] == "/" && dir !="/") dir = dir[1..sizeof(dir)-1];
	if( !users ) {  map_delete(exclude_read, dir);}
	else {
		wizlist = explode(users, ",");
		if( !check_redundancy(wizlist) ) return notify_fail("There is redundancy in list\n");
		exclude_read[dir] = wizlist;
	}
	save();
	return 1;
}
// set exclude write access to the dir
// sdong, 11/20/98
int set_exclude_writeaccess(string dir, string users)
{
	string *wizlist;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if(!dir)return 0;
	if( dir[0..0] == "/" && dir !="/") dir = dir[1..sizeof(dir)-1];
	if( !users ) {  map_delete(exclude_write, dir);}
	else {
		wizlist = explode(users, ",");
		if( !check_redundancy(wizlist) ) return notify_fail("There is redundancy in list\n");
		exclude_write[dir] = wizlist;
	}
	save();
	return 1;
}


// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object.                                                                                   - Annihilator

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("TRUST_D->valid_write: Invalid argument type of user.\n");

	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

	if(file == "/adm/daemons/securityd.c" 
	|| file == "/cmds/adm/promote.c"
	|| file == "/cmds/arch/purge.c"
	|| file == "/include/globals.h") return 0;
	
	// Let user save their save file
	if( func=="save_object" ) {
		if( sscanf(base_name(user), "/clone/%*s")
		&&      sscanf(file, "/data/%*s")
		&&(file == (string)user->query_save_file() 
		|| file == (string)user->query_save_file()+".o" ))
			return 1;
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID ) return 1;

//      if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") )
	if( sscanf(file, "/u/" + euid + "/%*s") )
		return 1;

	path = explode(file, "/");

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( member_array(status, exclude_write[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
	if( member_array(status, trusted_write["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}

	log_file("/static/WRITE_LOG", sprintf("%s %s(%s) write attempt on %s failed.\n", ctime(time()), geteuid(user), wizhood(user), file));
	return 0;
}

// check valid reading, added by sdong, 11/15/98
int valid_read(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;
	//if( find_player("sdong") )
	//      tell_object( find_player("sdong"), geteuid(user)+" try to "+func+" file: "+file+".\n" );

	if(func == "file_size" ||func == "stat") return 1; // always allow file_size

	// Let user load their data file
	if( sscanf(file, "/data/%*s") )
			return 1;
	if( sscanf(file, "/log/%*s") )
			return 1;
	if( sscanf(file, "/adm/etc/%*s") )
			return 1;

	if( !user || !objectp(user) )
	{
		error(geteuid(user)+" try to "+func+" file: "+file+".\n");
		return 0;
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid )
	{
		error(geteuid(user)+" try to "+func+" file: "+file+".\n");
		return 0;
	}

	if( sscanf(euid, "adm/%*s") ) return 1;
	if( sscanf(euid, "cmds/%*s") ) return 1;
	if( euid==ROOT_UID ) return 1;

	status = get_status(user);

	if( sscanf(file, "/u/" + euid + "/%*s") )
		return 1;

	path = explode(file, "/");

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_read[dir]) ) continue;
		if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
		if( member_array(status, exclude_read[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_read["/"])!=-1 ) return 1;
	if( member_array(status, trusted_read["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_read[dir]) ) continue;
		if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
		if( member_array(status, trusted_read[dir])!=-1 ) return 1;
	}

	log_file("/static/READ_LOG", sprintf("%s %s(%s) read attempt on %s failed.\n", ctime(time()), geteuid(user), wizhood(user), file));
	return 0;
}

// check valid commands, added by sdong, 11/25/98
int valid_cmd(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("TRUST_D->valid_cmd: Invalid argument type of user.\n");

	if( func!="cmd_file" ) {
			return 0;
	}

	if(!authorized_cmds)
	{
		authorized_cmds = allocate_mapping(10000);
		authorized_cmds["cmds/arch"] = "(admin),(arch)";
		authorized_cmds["cmds/wiz"] = "(admin),(arch),(wizard)";
	}


	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID ) return 1;

	// only /cmds/ is valid commands
//      if( !sscanf(file, "/cmds/%*s") )
//              return 0;

	path = explode(file, "/");

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_cmds[dir]) ) continue;
		if( member_array(euid, exclude_cmds[dir])!=-1 ) return 0;
		if( member_array(status, exclude_cmds[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, authorized_cmds["cmds"])!=-1 ) return 1;
	if( member_array(status, authorized_cmds["cmds"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		//write(dir+"\n");
		if( dir == "cmds/std" || dir == "cmds/skill" || dir == "cmds/usr" ) return 1;

		if( undefinedp(authorized_cmds[dir]) ) continue;
		if( member_array(euid, authorized_cmds[dir])!=-1 ) return 1;
		if( member_array(status, authorized_cmds[dir])!=-1 ) return 1;
	}

	log_file("/static/CMD_LOG", sprintf("%s(%s) cmds attempt on %s failed.\n", geteuid(user), wizhood(user), file));
	return 0;
}


int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;
	if( getuid(ob)==ROOT_UID ) return 1;
	if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
	if( wiz_status[uid] != "(admin)"
	&&      wiz_status[getuid(ob)] == "(admin)" )
		return 1;
	return 0;
}
