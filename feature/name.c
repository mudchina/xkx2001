//Cracked by Roath
// name.c

#include <ansi.h>
#include <mudlib.h>
#include <dbase.h>
#include <condition.h>

static string *my_id;

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

void set_color(string color)
{
	string colorname;

	colorname = color + query("name");

	colorname = replace_string(colorname, "$BLK$", BLK);
	colorname = replace_string(colorname, "$RED$", RED);
	colorname = replace_string(colorname, "$GRN$", GRN);
	colorname = replace_string(colorname, "$YEL$", YEL);
	colorname = replace_string(colorname, "$BLU$", BLU);
	colorname = replace_string(colorname, "$MAG$", MAG);
	colorname = replace_string(colorname, "$CYN$", CYN);
	colorname = replace_string(colorname, "$WHT$", WHT);
	colorname = replace_string(colorname, "$HIR$", HIR);
	colorname = replace_string(colorname, "$HIG$", HIG);
	colorname = replace_string(colorname, "$HIY$", HIY);
	colorname = replace_string(colorname, "$HIB$", HIB);
	colorname = replace_string(colorname, "$HIM$", HIM);
	colorname = replace_string(colorname, "$HIC$", HIC);
	colorname = replace_string(colorname, "$HIW$", HIW);
	colorname = replace_string(colorname, "$NOR$", NOR);

	set("colorname", colorname + NOR);
}

int id(string str)
{
	string *applied_id;

	if( this_player() && !this_player()->visible(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) ) 
		if( member_array(str, applied_id)!=-1 )
			return 1;
		else
			return 0;
			
	// If apply/id exists, this object is "pretending" something, don't
	// recognize original id to prevent breaking the pretending with "id"
	// command.

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
		return 1;
	else
		return 0;
}

string *parse_command_id_list()
{
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) )
		return applied_id;
	else
		return my_id;
}

varargs string name(int raw)
{
	string str, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/name")) )
		return mask[sizeof(mask)-1];
	else {
		if( stringp(str = query("name")) )
			return str;
		else
			return file_name(this_object());
	}
}

varargs string intermud_name(int raw)
{
	return sprintf("%s(%s@%s)", name(raw), 
			capitalize(this_object()->query("id")),
			INTERMUD_MUD_NAME);
}

varargs string short(int raw)
{
	string naming, title, nick, str, str1, *mask;

	if( !stringp(naming = query("colorname")) )
		naming = name(raw);
	
	if( !stringp(str = query("short")) )
		str = naming + "(" + capitalize(query("id")) + ")";

	if( !this_object()->is_character() ) return str;

	if (!raw) {
		if ((int)query_temp("pending/exercise") != 0)
			return name() + "正坐在地下修炼内力。";
		else if ((int)query_temp("pending/respirate") != 0)
			return name() + "正坐在地下吐纳炼精。";
		else if ((int)query_temp("pending/jingzuo") != 0)
			return name() + "正在蒲团上盘膝静坐。";
	}
	
        if( !raw && sizeof(mask = query_temp("apply/short")) )
                str = (string)mask[sizeof(mask)-1];
//	if( !raw && stringp(str1 = (string)query_temp("apply/short")) ) {
//		str = (string)mask[sizeof(mask) - 1];
//		return (string)query_temp("apply/short");
//		if (stringp(str1))
//		  	str += str1;
//	}
	else {
		if( stringp(nick = query("nickname")) )
			str = sprintf("「%s」%s", nick, str);

		if( stringp(title = query("title")) )
			str = sprintf("%s%s%s", title,(nick?"":" "), str);
	}

	if( !raw ) {
		if( this_object()->is_ghost() ) str = HIB "(鬼气) " NOR + str;
		if( query_temp("netdead") ) str += HIG " <断线中>" NOR;
		if( in_input() ) str += HIC " <输入文字中>" NOR;
		if( in_edit() ) str += HIY " <编辑档案中>" NOR;
		if( interactive(this_object())
		&&	query_idle( this_object() ) > 120 ) str += HIM " <发呆中>" NOR;
		if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
	}

	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/long")) )
		str = mask[sizeof(mask)-1];
	else if( !stringp(str = query("long")) )
		str = short(raw) + "。\n";

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}

