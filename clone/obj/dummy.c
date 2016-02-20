//Cracked by Roath
#include <login.h>

#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

int is_login=0;

void set_login_flag() { is_login = 1; }

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
    string id;

    id = query("id", 1);
    if( !stringp(id) ) return 0;
    if (is_login)
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
    return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}
