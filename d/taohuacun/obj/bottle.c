// huaping.c 花瓶

inherit ITEM;

void create()
{
        set_name("花瓶", ({ "bottle", "hua ping", "bag" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "尊");
                set("long", "一尊玛瑙花瓶。瓶上雕刻着一枝富贵牡丹。\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

