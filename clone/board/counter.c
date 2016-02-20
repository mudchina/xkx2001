//Cracked by Roath
// /object/region/counter.c     ¼ÆËãÆ÷
// by Jun@SIA
// Copyright (C) 1998 SIA

#include "/u/fear/war/war_include/war_temp.h"

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_NAME;
inherit F_SAVE;

void create()
{
    set("id", "counter");
    restore();
    set("no_clean_up", 1);
}

string query_save_file()
{
    string id;

    if( !stringp(id = query("id")) ) return 0;
    return DATA_DIR + "board/" + id;
}

