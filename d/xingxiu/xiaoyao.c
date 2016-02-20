//Cracked by Roath
// Xiaoyao.c:  the sleeping room for Xingxiu
// Jay May 13, 96

inherit ROOM;

void create()
{
        set("short", "逍遥洞");
        set("long", @LONG
这是一个粗糙的石洞，里面铺了几张臭哄哄的草垫子。垫子旁边
是一些破酒罐子。洞壁(wall)上有些字迹。
LONG
        );

//        set_light(0);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
                "out" : __DIR__"xxh6",
        ]));

        set("item_desc", ([
                "wall" : "星宿淫贼人人得而株之！\n",
        ]) );
	set("cost", 1);
        setup();
}

