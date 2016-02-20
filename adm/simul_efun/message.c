//Cracked by Kafei
// /adm/simul_efun/message.c
// modified by sdong to support BIG5, 11/14/98
// modified by sdong to enhance security, 12/05/98

varargs void message_vision(string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;

	my_name= me->name();
	my_gender = me->query("gender");
	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( you ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}

	message("vision", str1, me);
	message("vision", str3,  environment(me), ({ me, you}) );
}

void tell_object(object ob, string str)
{
	message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{

	if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{

	message("shout", str, users(), this_player());
}

void write(string str)
{
	if( this_player() )
		message("write", str, this_player());
	else if( previous_object() )
		message("write", str, previous_object());
	else
		efun::write(str);
}

void printf( string format,
	mixed arg1,mixed arg2,mixed arg3,mixed arg4,
	mixed arg5,mixed arg6,mixed arg7,mixed arg8,
	mixed arg9,mixed arg10,mixed arg11,mixed arg12)
{
	string str;
	str = sprintf( format, arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12 );
	if( this_player() )
		message("write", str, this_player());
	else if( previous_object() )
		message("write", str, previous_object());
	else
		efun::write(str);
}

int notify_fail( string str )
{

	if( this_player() )
	{
		if( this_player()->query("language") == "BIG5" )
			str = "/adm/daemons/languaged"->toBig5(str);
	}
	else if( previous_object() )
	{
		if( previous_object()->query("language") == "BIG5" )
			str = "/adm/daemons/languaged"->toBig5(str);
	}

	return efun::notify_fail( str );
}


varargs void say(string str, mixed exclude)
{

	if( living(previous_object()) )
		message("say", str, environment(previous_object()), previous_object());
	else if( this_player() )
		message("say", str, environment(this_player()), this_player());
}


void log_file(string file, string text)
{
	string filename;
	string str;

	filename = LOG_DIR + file + ".c";
	if( file_size(filename) > 300000 )
	{
		  rename( filename, filename + sprintf("%5d",time()) + ".c" ); // the log file may be too long now, rename it, sdong
	}
	else if( file_size(filename) > 0 )
	{
		str = read_file(filename);
		if(!str)
		{
		  str = "";
		}
	}
	else str = "";

	str += text;
	efun::write_file(filename,str,1);
}

/*
int write_file( string file, string str,int flag)
{
  object user = this_object();

  if( user && userp(user)  && geteuid(user)!= "NONAME"  &&  flag == 0 && find_object(SECURITY_D) && !SECURITY_D->valid_write(file, user, "write_file") && wizardp(user) )
  {
		log_file("/static/WRITE_LOG", sprintf("%s %s(%s) write %s permission denied.\n", ctime(time()), geteuid(user), wizhood(user), file));
		return notify_fail("Permission denied。\n");
  }

  if( user && userp(user) && geteuid(user)!= "NONAME" && flag == 0 && wizardp(user) )
	 log_file("/static/WRITE_LOG", sprintf("%s %s(%s) write %s.\n", ctime(time()), geteuid(user), wizhood(user), file));

  return efun::write_file( file, str, flag);
}


int write_buffer( string dest, int start, mixed source )
{
  object user = this_object();

  if( user && userp(user) && geteuid(user)!= "NONAME" && find_object(SECURITY_D) && !SECURITY_D->valid_write(dest, user, "write_file") && wizardp(user) )
		return notify_fail("Permission denied。\n");

  if( user && userp(user) && geteuid(user)!= "NONAME"  && wizardp(user) )
	  log_file("/static/WRITE_LOG", sprintf("%s %s(%s) write %s.\n", ctime(time()), geteuid(user), wizhood(user), dest));

  return efun::write_buffer( dest, start,source);
}
*/

string read_file( string file )
{
  object user = this_object();

  if( user && userp(user) && find_object(SECURITY_D) && !SECURITY_D->valid_read(file, user, "read_file") && wizardp(user) )
		return "Permission denied。\n";

  if( user && userp(user) && wizardp(user) )
	  log_file("/static/READ_LOG", sprintf("%s %s(%s) read %s.\n", ctime(time()), geteuid(user), wizhood(user), file));

  return efun::read_file( file );
}

void cat(string file)
{
	object user = this_object();
	string str;

  if( user && userp(user) && find_object(SECURITY_D) && !SECURITY_D->valid_read(file, user, "read_file") && wizardp(user) )
  {
		write("Permission denied。\n");
		return;
  }
	str = efun::read_file( file );
	if( user && userp(user) && wizardp(user) )
	  log_file("/static/READ_LOG", sprintf("%s %s(%s) cat %s.\n", ctime(time()), geteuid(user), wizhood(user), file));
	write(str);
	return;
}

void tail(string file)
{
	object user = this_object();

	if( user && userp(user) && find_object(SECURITY_D) && !SECURITY_D->valid_read(file, user, "read_file") && wizardp(user) )
  {
		write("Permission denied。\n");
		return;
  }

	if( userp(user) && wizardp(user) )
		log_file("/static/READ_LOG", sprintf("%s %s(%s) tail %s.\n", ctime(time()), geteuid(user), wizhood(user), file));

	efun::tail( file );
	return;
}


