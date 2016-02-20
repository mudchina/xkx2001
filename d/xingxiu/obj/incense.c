//Cracked by Roath
// incense.c 香火
// By Marz 11/11/96
// Ryu 12/5/96
inherit ITEM;

void init();
//void wear(int);

int worn;

void create()
{
	set_name("香",({"incense"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一枝刚造出来的香，还带着松枝的香气。\n");
		set("unit", "枝");
		set("value", 10000);
    	}
	
	setup();
}

void init()
{
	worn = 0;
	call_out("wear", 120, 1); 
	add_action("do_light", "light");
}
int do_light(string arg)
{
        object  ob, me = this_player();
	if( !arg || arg=="" ) return 0;

    if (!present("fire", me) || !present("incense", me))  return 0;
    
               message("vision",this_player()->name() + "掏出活折把香点燃。\n",
                        environment(me), ({me}) );
               write("你掏出活折把香点燃。\n");
		ob = new("/d/xingxiu/obj/incense2");
		ob->move(me);
		destruct(this_object());
        return 1;
}

/*
void wear(int phase)
{
	worn = phase;
	switch(phase) {
	case 1:
		set("long", "这是一枝香，但已经开始失去香味了。\n");
		call_out("wear", 120, phase+1); 
		break;
	case 2:
		set("long", "这是一枝放了很久的香，几乎完全失去香气了。\n");
		call_out("wear", 120, phase+1); 
		break;
	case 3:
		destruct(this_object());
		break;
	}	
}
*/
// End of File 
