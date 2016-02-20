//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("信", ({"xin", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                
set("long","这是一封段正淳写给黄眉大师的信。\n");
                set("no_get", "这样东西不能离开你。\n");
                set("material", "paper");
        }
}














