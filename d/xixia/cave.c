//Cracked by Roath
//Kane

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
这是沙漠中天然形成的一个石洞，洞中光线昏暗，但却十分干燥，
地下铺者几堆稻草，似乎是供人睡卧之用，静心凝听，洞中仿佛有阵
阵水声。洞的一角放着数堆人头骨(skulls)。
LONG
	);

      set("resource/water", 1);
	set("exits", ([
                "out" : __DIR__"desert2",
        ]));

	set("cost", 2);
	set("item_desc", ([
	"skulls" : "这是一堆共九个人头骨，分为上中下三层，下层五个，中层三个，上层一个\n",
	]));


	set("objects", ([
		"/kungfu/class/taohua/chaofeng" : 1,
		"/kungfu/class/taohua/xuanfeng" : 1,
	]));

	setup();
	replace_program(ROOM);
}
