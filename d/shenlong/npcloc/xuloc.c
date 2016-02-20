//Cracked by Roath
// /d/shenlong/npcloc/xuloc.c

// inherit SKILL;

inherit F_CLEAN_UP;

string *xulocs = ({
        "/d/changbai/shguan1",
        "/d/city/chaguan",
        "/d/qilian/lanzhou-nanmen",
        "/d/shaolin/shanmen",
        "/d/shenlong/dating",
});

void create() { seteuid(getuid()); }

string query_loc()
{
        return xulocs[random(sizeof(xulocs))];
}
