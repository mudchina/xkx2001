//Cracked by Roath
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("×ÏÅÛ", ({ "zi pao", "cloth" }));
        set("long", 
"ÕâÊÇÒ»¼şÉúË¿ÅÛ×Ó£¬ĞØÇ°¾«ĞãµÄ´ÌÁË¶şÁúº¬ÖéÍ¼£¬½ğË¿¹ü±ß£ ¸»¹ó·Ç³£¡£\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "¼ş");
                set("value", 1000);
                set("armor_prop/armor", 15);
        }
        setup();
}

