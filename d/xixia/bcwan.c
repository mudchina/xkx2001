//Cracked by Roath
// Room: /d/xixia/bcwan.c

inherit ROOM;

void create()
{
	set("short", "冰草湾");
	set("long", @LONG
冰草湾在营盘水的西南，平时人迹少至，因为当地沙漠里长着一种神奇的药
草——“冰草”而得名。据说这种药草能解百毒，所以偶有人来采这种草，不过
沙漠里常有毒虫出没，极为危险。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("bing_can", 2);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ypshui",
  "southwest" : __DIR__"shixiazi",
]));
	switch(random(3)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/snake" : 1,
				  "/d/xingxiu/npc/spider" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        }
	setup();
	replace_program(ROOM);
}
