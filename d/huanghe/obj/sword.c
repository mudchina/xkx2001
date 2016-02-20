//Cracked by Roath
// /d/changbai/bj/sword.c
// by ALN 2/98

inherit ITEM;

void create()
{
        set_name("铁剑", ({ "tie jian", "jian" }));
        set("long",
	    "此乃铁剑门“掌门之宝”，见铁剑如见祖师，掌执铁剑的就是本门掌门人。\n");
	set("unit", "柄");
        set("weight", 30);
}
