//Cracked by Roath
// 药房 /d/shenlong/yaofang
// ALN Sep / 97

inherit ROOM;

void create()
{
	set("short", "药房");
        set("long", @LONG
这是陆大夫的药房，靠墙放了许多柜子，抽屉中放满了许多中草药，陆大
夫常在这儿给岛上的众人抓药、诊治。你可以在这儿向陆大夫要一些雄黄以避
免岛上的毒蛇侵扰。
LONG
        );

	set("exits", ([
                "north" : __DIR__"zhulin1",
        ]));

	set("objects", ([
               "/kungfu/class/shenlong/lu" : 1,
	]));
	set("cost", 1);

        setup();
        replace_program(ROOM);
}










