//Cracked by Roath
// Room: /d/taishan/daizong.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "岱宗坊");
	set("long", @LONG
位于泰安县城以北约一里，此处是登泰山的入口。相传当年碧霞元君被姜子
牙戏弄，诱她投掷绣花鞋以定泰山地界，结果碧霞元君只能把绣花鞋从山顶掷到
此处。从此泰山便以此为起点。泰山西北面是黄河。
LONG
	);

	set("exits", ([
		"northup" : __DIR__"baihe",
		"south" : __DIR__"yidao3",
		"west" : "/d/huanghe/bank5",
	]));

        set("objects",([
                "/clone/npc/shan" : 1,
        ]));

	set("outdoors", "taishan");
	set("cost", 4);
	setup();
	replace_program(ROOM);
}

