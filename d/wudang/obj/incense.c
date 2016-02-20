//Cracked by Roath
// incense.c 香火
// By Marz 11/11/96

inherit ITEM;

void wear(int);

int worn;

void create()
{
	set_name("香火",({"incense"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一枝刚造出来的香火，还带着松枝的香气。\n");
		set("unit", "枝");
		set("value", 10000);
		if (this_player()->query("id") != "xqin")
		{
		set("no_drop", 1);
		set("no_get", 1);
		}
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
		set("long", "这是一枝贡奉用的香火，但已经开始失去香味了。\n");
		call_out("wear", 120, phase+1); 
		break;
	case 2:
		set("long", "这是一枝放了很久的香火，几乎完全失去香气了。\n");
		call_out("wear", 120, phase+1); 
		break;
	case 3:
		destruct(this_object());
		break;
	}	
}

// End of File 
