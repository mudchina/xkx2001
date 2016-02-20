//Cracked by Roath
//maco

inherit ROOM;

void create()
{
        set("short", "空地");
        set("long", @LONG
这是荒山中的空地，前面有一间茅，门前疏散地排著几个土堆(hillock) 
。四周树林茂密，偶闻鸟雀鸣啭，甚为幽静。那茅柴扉草顶，构虽然平平无
奇，但是因其朴素，反而与山中景致融为一体，更添淡雅意境，主人心思之巧密
，自然流露。
LONG
        );
         set("exits", ([
                "south" : __DIR__"wdroad5",
                "enter" : __DIR__"maoshe",
        ]));

         set("objects", ([
                 "/d/taohua/obj/shizi" : 1,
        ]));
        set("item_desc", ([
        "hillock" : "茅屋外的土阵东一堆，西一堆，看似乱七八糟，中间却似乎暗藏五行生的变化。\n",
        ]));

        set("outdoors", "wudang");
        set("cost", 1);

        setup();
}
int valid_leave(object me, string dir)
{

        if(dir == "enter") { 
        if( present("tie bagua", me)  ) {
        message_vision("$N依照铁八卦上的卦象方位走过了土堆。\n", me);
        return ::valid_leave(me, dir);
        }

        else if( me->query("family/family_name") != "桃花岛" && me->query_skill("qimen-dunjia", 1) < 90  ) {
        message_vision("$N在土堆前绕来绕去，不得要领，始终走不过去。\n", me);
                return notify_fail("");
        }

        else {
        }
        message_vision("$N转了几转，轻轻易易的便绕过土堆，自然而然的信步进屋。\n", me);
        return ::valid_leave(me, dir);
        }
        else return ::valid_leave(me, dir);
}
