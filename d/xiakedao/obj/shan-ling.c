//Cracked by Roath
inherit ITEM;

void create()
{
        set_name( "赏善令", ({ "shangshan ling", "ling", "iron" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一快铁牌，牌的一面是一个笑脸，另一面什麽也没有\n");
                set("value", 0);
                set("material", "iron");
        }
        setup();
}

string query_autoload()
{
        if( query("owner") == this_player()->query("id") )
                return query("name");
}
void autoload(string arg)
{       object it = this_object();
        object me = this_player(); 
        string desc;
                desc = "这是一快铁牌，牌的一面是一个笑脸，另一面刻着“" + me->query("name") + "”\n";
                it->set("long", desc);
                it->set("owner", me->query("id"));
                it->set("setted", 1);
}
        
        
