//table.c 梳妆台
inherit ITEM;
void create()
{
        set_name("梳妆台", ({ "table" , "shuzhuang tai", "tai"}) );
        set_weight(5000);
        set_max_encumbrance(8000000);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("no_get", 1);
                set("long", "这是一张梳妆台，楠木雕就，金丝绺边，台上一面晶亮的水晶镜子。\n");
                set("value", 0);
        }
}
int is_container() { return 1; }
