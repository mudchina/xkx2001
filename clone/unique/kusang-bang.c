//Cracked by Roath
// kusang-bang.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;

inherit STICK;

void create()
{
        set_name(HIW"哭丧棒"NOR, ({"kusang bang", "bang", "stick"}));
        set_weight(10000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIW"一根精钢打就的哭丧棒，棒上白索缠绕，棒头拖着一条麻绳，瞧不出丝毫异处。\n"NOR);
                set("value", 4000000);
                set("material", "blacksteal");
                set("rigidity", 2000);
	        set("poison", 5);
                set("wield_msg", "$N阴恻恻地一笑，抽出一根哭丧棒抓在手中。\n");
                set("unwield_msg", "$N把手中的哭丧棒插回腰中。\n");
        }

        init_stick(100);
        setup();
        ::create();
}       
