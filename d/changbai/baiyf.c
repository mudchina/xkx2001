//Cracked by Roath
// Room: baiyf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "白云峰");
	set("long", @LONG
这里是长白主峰，亦是关外的第一高峰，耸立于天池的北面，又叫“岩
层”。白云触石而出，终日不散。天晴时群峰毕露，独此峰烟雾缭绕，气象
雄壮，崇山隐天，云锁峰尖，乃成为长白的象征。进山的参客，猎户多到此
峰拜祭天地，以保平安。
LONG	);
	set("exits", ([ 
              "southdown" : __DIR__"tianchi",
              "southwest" : __DIR__"yuzf",
              "southeast" : __DIR__"longmf",
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
