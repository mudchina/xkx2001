//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("ÎäÒÄÑÒ²è", ({ "wuyi yancha","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"ÕâÊÇÒ»±­ÎäÒÄÑÒ²è£¬ÎÚÁú²èÖĞµÄÃ÷Öé¡£²èÌÀ³ÊÉî³È»ÆÉ«£¬Çå³ºÑŞÀö£»Ò¶µ×ÈíÁÁ£¬Ò¶ÔµÖìºì£¬\n");
                set("unit", "±­");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "ÎäÒÄÑÒ²è",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

