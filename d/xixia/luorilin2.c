//Cracked by Roath
// Room: /d/xixia/luorilin2.c

inherit ROOM;

void create()
{
        int i;
        set("short", "落日林");
        set("long", @LONG
这里是一片方圆百里的森林，林中古木参天，树荫蔽日，光线黯淡，落日林
的伐木场就在这里，这里是树木大都树龄百年以上，数人合抱的大树比比皆是，
一条不宽的土路蜿蜒通向前方。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tulu",
  "southwest" : __DIR__"dalu",
]));
        i = random (3);
        switch (i) {
        case 0:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/city/obj/branch4" : 1,
            "/d/quanzhou/npc/wuya" : 1,
        ]));
        break;
        case 1:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/wudang/npc/yetu" : 1,
        ]));
        break;
        case 2:
        set("objects", ([
            "/d/city/obj/branch3" : 1,
            "/d/xingxiu/npc/snake" : 1,
        ]));
        break;
        }
        
        set("cost", 3);
        set("outdoors", "xixia");

        setup();
        replace_program(ROOM);
}
