//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��ɽ����", ({ "junshan yinzhen","yinzhen","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"����һ����ɽ���룬ɫ��������������ˬ����ɫ�Ȼƣ���ζ�ʴ���\n");
                set("unit", "��");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "��ɽ����",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

