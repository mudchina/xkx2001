//Cracked by Roath
// FLAG

#include <ansi.h>
inherit ITEM;

string long_desc() {
    string msg;

    msg = "\n" +
HIR"    ★"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + RED"~~~~~~~~~~~~~~~~~~~~"NOR + "\n" +
HIB"    ||"NOR + RED"                  /"NOR + "\n" +
HIB"    ||"NOR + HIY"    武林盟主"NOR + RED"     ("NOR + "\n" +
HIB"    ||"NOR + RED"                  \\"NOR + "\n" +
HIB"    ||"NOR + RED"~~~~~~~~~~~~~~~~~~~~"NOR  + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    ||"NOR + "\n" +
HIB"    Ｖ"NOR + "\n";

    return msg;
}

void create() {
    set_name("武林大旗", ({ "flag" }) );
    set_weight(200);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", (: long_desc :));
        set("unit", "面");
        set("value", 100000);
    }
    setup();
}
