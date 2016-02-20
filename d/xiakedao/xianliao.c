//Cracked by Roath
// xianliao.c 
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "茶房");
	set("long", @LONG
茶房自古便是谈天说地，传播小道消息的地方。这里人们东一群，
西一伙地闲聊。或是吐沫横飞，讲得天花乱坠；或是指手划脚，争得
面红耳赤。手提铜壶的茶博士正高声吆喝着来回穿梭。
LONG );

	set("exits", ([
		"west" : __DIR__"yongdao5",
//		"east" : __DIR__"eproom",
	]));
	set("cost", 0);

	set("objects", ([ 
	    __DIR__ + "npc/xianren" : 1,
      ]));

	setup();
}
