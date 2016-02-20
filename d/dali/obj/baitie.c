//Cracked by Kafei
// baitie.c 拜贴
// AceP

inherit ITEM;

void create()
{
	set_name("拜贴", ({"bai tie", "tie", "letter"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
		set("unit", "封");
        set("long","这是一封由马五德亲笔写的拜贴，凭此可前往无量山剑湖宫观摩无量剑派五年一次的比武。\n");
		set("no_drop", "这样东西不能离开你。\n");
		set("no_get",  "这样东西不能离开那儿。\n");
        set("material", "paper");
    }
}


