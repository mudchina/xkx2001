//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("棋谱", ({ "qipu" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是向问天收集的围棋名局二十局的棋谱，"
		"里面包括刘仲甫和骊山姥对弈的「呕血谱」。\n");
		set("unit", "本");
		set("value",2000);
	}
	setup();
}	
