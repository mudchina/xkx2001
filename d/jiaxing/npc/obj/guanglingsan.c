//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("广陵散", ({ "guangling san", "san" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是曲洋在东汉蔡邑墓中所得得古人名谱，"
		"该谱因西晋嵇康所奏而闻名天下。\n");
		set("unit", "册");
		set("value",1000);
	}
	setup();
}	
