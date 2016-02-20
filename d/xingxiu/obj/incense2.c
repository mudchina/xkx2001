//Cracked by Roath
// incense.c 香火
// By Marz 11/11/96
// Ryu, 12/5/96

inherit ITEM;

void init();
void wear(int);

int worn;

void create()
{
	set_name("点燃的香",({"incense"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一枝点燃的香，烧出一股淡淡的幽香。\n");
		set("unit", "枝");
		set("value", 10000);
    	}
	
	setup();
}

void init()
{
	worn = 0;
	call_out("wear", 120, 1); 
}



void wear(int phase)
{
	worn = phase;
	switch(phase) {
	case 1:
		set("long", "这是一枝点燃的香，已经烧掉一半了。\n");
		call_out("wear", 60, phase+1); 
		break;
	case 2:
		set("long", "这是一枝正燃着的香，几乎快烧完了。\n");
		call_out("wear", 60, phase+1); 
		break;
	case 3:
		destruct(this_object());
		break;
	}	
}

// End of File 
