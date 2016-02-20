//Cracked by Kafei
// Originally from Truilkan... the user versions were whipped up by Buddha

//#include <config.h>
//#include <uid.h>

varargs string extract( string str, int from, int to )
{
    if( !stringp( str ) ) return ""; // syntax error
    if( nullp( from ) ) return str;
    if( nullp( to ) ) to = strlen( str );
    return str[from..to];
}

string data_dir(object obj) {
   return DATA_DIR + base_name(obj);
}

string data_file(object obj) {
   return data_dir(obj) + "/" + (geteuid(obj) ? geteuid(obj) : getuid(obj));
}

varargs string user_data_dir(object obj, string name) {
   if (!name) name = (geteuid(obj));
   if (!name) return "" ;
//   if (!name) error("user_data_dir: Can't determine user's name.\n");
   return data_dir(obj) + "/" + extract(name, 0, 0);
}

varargs string user_data_file(object obj, string name) {
   string dir;
   dir = (name ? user_data_dir(obj, name) : user_data_dir(obj));
   return dir + "/" + (name ? name : geteuid(obj));
}

void assure_user_save_dir(object user) {
	string dir, path, *parts;
	int j;
        if (previous_object() != user) return;
	path = user_data_dir(user);
        if (file_size(path) == -1) {
                seteuid(ROOT_UID);
	        parts = explode(path, "/");
		dir = "";
		for (j = 0; j < sizeof(parts); j++) {
                	dir += parts[j];
                	mkdir(dir);
                	dir += "/";
        	}
        }
	if (file_size(path) == -1)
		write("assure_save_dir failed!\n");
}

void assure_save_dir(object user) {
        string dir, path, *parts;
        int j;
        if (previous_object() != user) return;
        path = data_dir(user);
        if (file_size(path) == -1) {
                seteuid(ROOT_UID);
                parts = explode(path, "/");
                dir = "";
                for (j = 0; j < sizeof(parts); j++) {
                        dir += parts[j];
                        mkdir(dir);
                        dir += "/";
                }
        }
}


