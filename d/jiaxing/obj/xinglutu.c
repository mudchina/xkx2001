//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("行旅图", ({ "xinglu tu", "tu" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是一幅极为陈旧的画图，右上角题着「北宋范中立溪山行旅图」十字，"
		"一座高山冲天而起，墨韵凝厚，气势雄峻之极。\n");
		set("unit", "幅");
		set("value",2000);
	}
	setup();
}	
