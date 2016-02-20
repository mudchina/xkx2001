//Cracked by Roath

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

int save_box_count (mapping box_content);
int reset_all_value();

// mapping box;

int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

string query_save_file()
{
        string id;
        if( !stringp(id = query("owner_id")) ) return 0;
        return DATA_DIR + "box/" + id;
}

void create()
{
       seteuid(getuid()); 
}

int save_box_count(mapping box_content) 
{
     set("box",box_content);
     save();
	 return 1;
}


int reset_all_value ()
{
	 mapping empty_box = ([]);

     set("box",empty_box);
	 save();
	 return 1;
}

