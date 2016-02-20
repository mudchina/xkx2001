//Cracked by Roath
// fish.c

inherit ITEM;

int decayed;

void create()
{
	set_name("活鱼", ({ "fish", "yu" }) );
	set("long", "这是一条活蹦乱跳的大活鱼。\n");
	set("unit", "条" );
	set("speical", 0);
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_live() { return decayed == 0; }
int is_halfdead() { return decayed == 1;}
int is_dead() { return decayed >= 2; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 1:
			message("vision", query("name") + "大概离开水太久了，好象快死了。\n", environment() );
			set("long",	"这条鱼因为离开水太久了，看过去好象快死了。\n");
			call_out("decay", 60, phase + 1);
			break;
		case 2:
			message("vision", query("name") + "死了，开始散发出一股臭气。\n", environment() );
			set_name("死鱼", ({ "si yu", "fish" }) );
			set("long", "一条臭了的鱼，快扔了吧。\n");
			break;
	}
}
