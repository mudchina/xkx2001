//Cracked by Kafei
// /adm/daemons/file.c
// modified by sdong to support Big5, 11/25/98


void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");
	dir = dir[0..sizeof(dir)-2];
	path = "/";
	for(i=0; i<sizeof(dir); i++) {
		path += dir[i];
		mkdir(path);
		path += "/";
	}
}

string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
}
