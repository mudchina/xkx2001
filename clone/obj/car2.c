//Cracked by Roath
// Carriage2: /clone/obj/car2.c 大车里
// Date: xbc /04/14/97

inherit ITEM;

void create()
{
        set_name("大车里", ({ "da che", "che", "carriage" }) );
        set_weight(3000000);
        set_max_encumbrance(5000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", @LONG

大车里 - 
　　车里干干净净，放了两张舒服的大椅子。窗帘拉了下来，阳光从缝隙中透
进来，不知道车子走到哪里了。门外挂了一串风铃，叮呤呤响着。车夫坐在前
面，一路赶着马，一路得意地哼着什么小调。

LONG
	);

                set("amount",30);
        }
        setup();
}

int is_container() { return 1; }

void init()
{	
	remove_call_out("auto_clean_up");
	call_out("auto_clean_up",60);
}

void auto_clean_up()
{
	object *inv;
	object obj;
	string dest;

	inv = all_inventory(this_object());
	if (!inv) return;
	foreach(obj in inv) {
		if(userp(obj)) {
		if(obj->query_temp("dache_dest"))
			dest = obj->query_temp("dache_dest");
		else dest = "/d/city/kedian"; 
		obj->move(dest);
		}
	}
}

/*

	set("short", "大车里");
	set("long", @LONG
车里干干净净，放了两张舒服的大椅子。窗帘拉了下来，阳光从缝隙中透
进来，不知道车子走到哪里了。门外挂了一串风铃，叮呤呤响着。车夫坐在前
面，一路赶着马，一路得意地哼着什么小调。
LONG
	);

	set("cost", 0);
	set("invalid_startroom", 1);
	setup();
        replace_program(ROOM);
}
*/
