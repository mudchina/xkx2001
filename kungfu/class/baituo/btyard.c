//Cracked by Roath
// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "白驼山前院");
        set("long", @LONG
这是白驼山庄的前院。院墙白砖蓝瓦，看上像是新翻修的。院中弥漫着
毒气，寸草不生。北面传出「嘶嘶」的声响，南面传来饭香，西边是庄主的
练功房，东边下山去就是山门。
LONG
        );
        set("exits", ([ 
            "eastdown" : __DIR__"btgate",
            "west" : __DIR__"btroom",
	    "north" : __DIR__"btbarn",
	    "south" : __DIR__"btkitchen",
        ]));
        set("objects", ([ 
            CLASS_D("baituo")+"/binu" : 1,
	    CLASS_D("baituo")+"/jiading" : 1,
         ]) );
	set("outdoors","xingxiuhai");
        replace_program(ROOM);
        setup();
}

