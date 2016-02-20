//Cracked by Roath
inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short", "拱猪王宫");
        set("long", @LONG
这是一座豪华的王宫，殿内金壁辉煌，金砖漫地，到处是金子做的
猪食盆，里面放满了猪王爱吃的猪食——小白菜、木瓜、豆子、小青草、
胡萝卜、ｅｔｃ．。
LONG
        );

        set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "wn" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/city/gbxiaowu",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
        ]));
        set("objects", ([
            __DIR__"obj/cleansword" : 1,
            __DIR__"obj/marz" : 1,
            __DIR__"obj/rover" : 1,
            __DIR__"obj/xiang" : 1,
	]));
        set("pigging",1);

        set("valid_startroom",1);

        set("outdoors", "quanzhou");
        setup();
}

void init()
{
        add_action("do_leave", "leave");
}

int valid_leave(object me, string dir)
{
        if ((string)me->query("name")!="拱猪王"){
                write("猪王一把揪住你的衣领说：“慢着，你太瘦，还不能出栏！”\n");
		return 0;
	}
        return ::valid_leave(me, dir);
}

int do_leave()
{
        object me = this_player();
        if(me)
                me->move("/d/wizard/wizard_room");
        return 0;
}
