//Cracked by Roath
// gang.c 水缸
// zhangchi 7/00


inherit ITEM;

void create()
{
        set_name("水缸", ({ "shui gang", "gang" }) );
        set_weight(90000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个极大的水缸，可以用来储存冷水。\n");
                set("unit", "个");
		set("no_get", 1);
		set("value",1);
		set("amount", 0);
        }
}

string extra_long()
{
	int amount=query("amount");

	return "里面有"+chinese_number(amount)+"升水。\n";
}	